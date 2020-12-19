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
    connect(worker, &Thread::generationFinished, this, &Canvas::nextGen);  // connect finish genration to update canvas
    render_data = worker->life->getRenderData(0);
    worker->start();
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

void Canvas::render2d() {/*
    float _top, bottom, left, right;
    glColor3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < life->SIZE; i++) {
        for (int j = 0; j < life->SIZE; j++) {
            if (render_data[i * life->SIZE + j]) {
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
    qDebug() << "--";*/
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
    this->update();
    qDebug() << camera.centerX << camera.centerY << camera.centerZ;
}

void Canvas::nextGen() {
    /*
     * Call after born new generation
    */
    qDebug() << "Next Gen";
    render_data = worker->life->getRenderData(coordsPanel->INDEX);
    this->update();
    controlPanel->updateGeneration();
}

void Canvas::updateLife() {
    qDebug() << "Какого хуя?";
}
/*
glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-1.0, -1.0, -5.0f);
glVertex3f(-1.0, 1.0, -5.0f);
glVertex3f(1.0, 1.0, -5.0
void Canvas::nextGen() {f);
glVertex3f(1.0, -1.0, -5.0f);
// Top face (y = 1.0f)
// Define vertices in counter-clockwise (CCW) order with normal pointing out
glColor3f(0.0f, 1.0f, 0.0f); // Green
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);

// Bottom face (y = -1.0f)
glColor3f(1.0f, 0.5f, 0.0f); // Orange
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);

// Front face  (z = 1.0f)
glColor3f(1.0f, 0.0f, 0.0f); // Red
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -2.0f, 1.0f);

// Back face (z = -1.0f)
glColor3f(1.0f, 1.0f, 0.0f); // Yellow
glVertex3f(1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);

// Left face (x = -1.0f)
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);

// Right face (x = 1.0f)
glColor3f(1.0f, 0.0f, 1.0f); // Magenta
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);*/
