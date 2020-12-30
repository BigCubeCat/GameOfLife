#include "Canvas.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <cmath>

Canvas::Canvas(int n, int s, QWidget *parent)
    : QOpenGLWidget(parent)
{
    // make and start thread with life
    camera = new Camera(-10, 10, -10, 4 * M_PI / 7, M_PI / 4, 0.01, 0.2, 800, 600);
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
/*GL functions*/
void Canvas::initializeGL() {
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glutPassiveMotionFunc(mouseLook);
}

void Canvas::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    //camera->rotation(0, 0);
    camera->translation(movement[0], movement[1], movement[2], movement[3]);
    gluLookAt(
            camera->getX(), camera->getY(), camera->getZ(), camera->getSightX(),
            camera->getSightY(), camera->getSightZ(), 0, 1, 0);
    glBegin(GL_QUADS);

    if (worker->life->N == 2) {
        render2d();
    } else {
        render();
    }
    glEnd();

    glPopMatrix();
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
/*render*/
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
}

void Canvas::render() {
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

// Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

// Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

// Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

// Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

// Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube
}

void Canvas::updateSettings() {
}

void Canvas::getIndex() {
    // TODO
}

void Canvas::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_W:
            movement[2] = true;
        case Qt::Key_A:
            movement[0] = true;
        case Qt::Key_S:
            movement[1] = true;
        case Qt::Key_D:
            movement[3] = true;
    }
    camera->translation(movement[0], movement[1], movement[2], movement[3]);
    for (bool &i : movement) {
        qDebug() << i;
        i = false;
    }
}

void Canvas::nextGen() {
    /*
     * Call after born new generation
    */
    render_data = worker->life->getRenderData(coordsPanel->INDEX);
    this->update();
    controlPanel->updateGeneration(); // Вынеси в отдельный сигнал!!!
    worker->start();
}

void Canvas::updateLife() {
}

void Canvas::mouseLook(int x, int y) {
    camera->rotation(x, y);
    // TODO check mouse in widget
}