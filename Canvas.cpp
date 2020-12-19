#include "Canvas.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <QDebug>

Canvas::Canvas(int n, int s, QWidget *parent)
    : QOpenGLWidget(parent)
{
    // make and start thread with life
    worker = new Thread(n, s);
    render_data = worker->life->getRenderData(0);
    mTimer = new QTimer(this);
    mTimer->setSingleShot(false);
    mTimer->setInterval(1);
    connect(mTimer, &QTimer::timeout, this, &Canvas::nextGen);
    mTimer->start();
}

Canvas::~Canvas() {
    worker->life->clear_data();
}

void Canvas::initializeGL() {
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void Canvas::paintGL() {
    qDebug() << "cell size = " << cellSize;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    float g_RotateX = 0.0f;
    float g_RotationSpeed = 0.1f;

    /* centerXYZ - наклон*
     * eyeXYZ - позиция
     */
    gluLookAt(camera.eyeX, camera.eyeY, camera.eyeZ, camera.centerX, camera.centerY,
              camera.centerZ, camera.upX, camera.upY, camera.upZ);

    if (worker->life->N == 2) {
        glBegin(GL_QUADS);
        render2d();
    } else {
        render();
    }
    glEnd();

    glPopMatrix();
}

void Canvas::render2d() {
    float _top, bottom, left, right;
    glColor3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < worker->life->SIZE; i++) {
        for (int j = 0; j < worker->life->SIZE; j++) {
            if (render_data[i * worker->life->SIZE + j]) {
                right = (j + 1) * cellSize;
                left = j * cellSize;
                _top = i * cellSize;
                bottom = (i + 1) * cellSize;
                glColor3f((float)(rand() % 10) / 10, (float)(rand() % 10) / 10, (float)(rand() % 10) / 10);
                glVertex3f(left, _top, -5.0f);
                glVertex3f(right, _top, -5.0f);
                glVertex3f(right, bottom, -5.0f);
                glVertex3f(left, bottom, -5.0f);
            }
        }
    }
    qDebug() << "--";
}

void Canvas::render() {
    glColor3f(0.0f, 1.0f, 0.0f);
    // TODO
}

void Canvas::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 0.01, 100.0);
    int minimum = min(w, h);
    cellSize = (float)worker->life->SIZE / (float)minimum * 5;
    buffer = minimum / 2.0f;
}

void Canvas::updateSettings() {
    qDebug() << "Porn";
}

void Canvas::getIndex() {
    // TODO
}

void Canvas::keyPressEvent(QKeyEvent* event) {
    qDebug() << "H";
    switch (event->key()) {
        case Qt::Key_W:
            camera.centerZ += fps_speed;
        case Qt::Key_S:
            camera.centerZ -= fps_speed;
        case Qt::Key_D:
            camera.centerX += fps_speed;
        case Qt::Key_A:
            camera.centerX -= fps_speed;
    }
    qDebug() << camera.centerX << camera.centerY << camera.centerZ;
    this->update();
}

void Canvas::nextGen() {
    /*
     * Call after born new generation
    */
    qDebug() << "Next Gen";
    render_data = worker->life->getRenderData(coordsPanel->INDEX);
    this->update();
    controlPanel->updateGeneration(); // Вынеси в отдельный сигнал!!!
    worker->start();
}

void Canvas::updateLife() {
    qDebug() << "Какого хуя?";
}
