#include "Canvas.h"
#include "view/Camera.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QRgb>
#include <QTimer>
#include <QDebug>

Canvas::Canvas(QWidget *parent)
    : QOpenGLWidget(parent)
{
    life = new Life(2, 3);
    mCamera = new Camera();
    dimension = 2;
    mTimer = new QTimer();
    connect(mTimer, &QTimer::timeout, this, QOverload<>::of(&Canvas::updateLife));
    mTimer->start(100);
    vector<int> coords;
    render_data = life->getRenderData(coords);
}

Canvas::~Canvas() {
    life->clear_data();
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -10.0f); // Move right and into the screen

    glBegin(GL_QUADS);
    if (dimension == 2) {
        render2d();
    } else {
        render();
    }
    glEnd();
    glPopMatrix();
}

void Canvas::render2d() {
    float _top, bottom, left, right;
    float size = 0.1f;
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -5.0f);
    glVertex3f(size, 0.0f, -5.0f);
    glVertex3f(size, size, -5.0f);
    glVertex3f(0.0f, size, -5.0f);
    for (int i = 0; i < life->SIZE; i++) {
        for (int j = 0; j < life->SIZE; j++) {
            if (render_data[i * life->SIZE + j]) {
                right = (j + 1) * size;
                left = j * size;
                _top = i * size;
                bottom = (i + 1) * size;
                glColor3f(0.0f, 1.0f, 0.0f);
                glVertex3f(left, bottom, -5.0f);
                glVertex3f(left, _top, -5.0f);
                glVertex3f(right, _top, -5.0f);
                glVertex3f(right, bottom, -5.0f);
            }
        }
    }
}

void Canvas::render() {
    glColor3f(0.0f, 1.0f, 0.0f);

}

void Canvas::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void Canvas::updateLife() {
    life->nextGeneration();
    vector<int> coords;
    render_data = life->getRenderData(coords);
    this->update();
    controlPanel->updateGeneration();
}

void Canvas::setB(vector<int> b) {
    life->B = b;
}

void Canvas::setS(vector<int> s) {
    life->S = s;
}

void Canvas::setSettings(int d, int s) {
    life->setNewParams(d, s);
}

void Canvas::setSpeed(int speed) {
    mTimer->setInterval(speed);
}

void Canvas::updateSettings() {
    qDebug() << "Porn";
}

void Canvas::getIndex() {
    // TODO
}

void Canvas::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_W) {
        /*if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false/*/
    }
}
/*
glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-1.0, -1.0, -5.0f);
glVertex3f(-1.0, 1.0, -5.0f);
glVertex3f(1.0, 1.0, -5.0f);
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
