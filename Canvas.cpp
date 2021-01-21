#include "Canvas.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <cmath>

Camera *camera = new Camera(-5, 5, -5, 4 * M_PI / 7, M_PI / 4, 0.005, 0.1, 800, 600);

Canvas::Canvas(int n, int s, QWidget *parent)
        : QOpenGLWidget(parent) {
    this->setMouseTracking(true);
    worker = new Worker();
    // life update timeint signal qtr
    mTimer = new QTimer(this);
    mTimer->setSingleShot(false);
    mTimer->setInterval(1);
    connect(mTimer, &QTimer::timeout, this, &Canvas::nextGen);
    mTimer->start();
    fpsTimer = new QTimer(this);
    fpsTimer->setSingleShot(false);
    fpsTimer->setInterval(fps);
    connect(fpsTimer, &QTimer::timeout, this, &Canvas::fpsUpdate);
    fpsTimer->start();
    connect(worker, &Worker::updateRender, this, &Canvas::startThread); // rerun thread
}

/*GL functions*/
void Canvas::initializeGL() {
    glClearColor(1, 1, 1, 1);
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
    glEnable(GL_DEPTH_TEST);

    camera->translation(movement[0], movement[1], movement[2], movement[3]);
    gluLookAt(
            camera->getX(), camera->getY(), camera->getZ(), camera->getSightX(),
            camera->getSightY(), camera->getSightZ(), 0, 1, 0);
    glBegin(GL_QUADS);

    if (worker->D < 3) {
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
    gluPerspective(45, (float) w / h, 0.01, 100.0);
    int centerX = this->width() / 2;
    int centerY = this->height() / 2;
    camera->setCenter(centerX, centerY);
}

/*render*/
void Canvas::render2d() {
    float _top, bottom, left, right;
    if (!drawing) return;
    for (int i = 0; i < worker->SIZE; i++) {
        for (int j = 0; j < worker->SIZE; j++) {
            if (render_data[i * worker->SIZE + j]) {
                right = (j + 1) * cellSize;
                left = j * cellSize;
                _top = i * cellSize;
                bottom = (i + 1) * cellSize;
                glColor3f(((float) i / (float) worker->SIZE), ((float) j / (float) worker->SIZE), 1.0f);
                glVertex3f(left, _top, 0.0f);
                glVertex3f(right, _top, 0.0f);
                glVertex3f(right, bottom, 0.0f);
                glVertex3f(left, bottom, 0.0f);
            }
        }
    }
}

void Canvas::render() {
    float t, b, l, r, f, back;
    if (!drawing) return;
    for (int i = 0; i < worker->SIZE; i++) {
        for (int j = 0; j < worker->SIZE; j++) {
            for (int k = 0; k < worker->SIZE; k++) {
                //if (worker->getCell(i * worker->SIZE * worker->SIZE + j * worker->SIZE + k)) {
                    r = (j + 1) * cellSize;
                    l = j * cellSize;
                    t = i * cellSize;
                    b = (i + 1) * cellSize;
                    f = k * cellSize;
                    back = (k + 1) * cellSize;
                    glColor3f(((float) i / (float) worker->SIZE), ((float) j / (float) worker->SIZE),
                              ((float) k / (float) worker->SIZE));
                    glVertex3f(l, t, f);
                    glVertex3f(r, t, f);
                    glVertex3f(r, b, f);
                    glVertex3f(l, b, f);

                    glVertex3f(l, t, back);
                    glVertex3f(r, t, back);
                    glVertex3f(r, b, back);
                    glVertex3f(l, b, back);

                    glVertex3f(l, t, f);
                    glVertex3f(l, b, f);
                    glVertex3f(l, b, back);
                    glVertex3f(l, t, back);

                    glVertex3f(r, t, f);
                    glVertex3f(r, b, f);
                    glVertex3f(r, b, back);
                    glVertex3f(r, t, back);

                    glVertex3f(r, t, f);
                    glVertex3f(r, t, back);
                    glVertex3f(l, t, f);
                    glVertex3f(l, t, back);

                    glVertex3f(r, b, f);
                    glVertex3f(r, b, back);
                    glVertex3f(l, b, f);
                    glVertex3f(l, b, back);
                //}
            }
        }
    }
}

/* Slots */
void Canvas::step() {
    worker->start();
    lifeIsRunning = false;
}

void Canvas::stop() {
    lifeIsRunning = false;
}

void Canvas::play() {
    lifeIsRunning = true;
    worker->start();
}

void Canvas::updateSettings() {
    mTimer->setInterval(controlPanel->settings.speed);
    worker->updateParameters(controlPanel->settings.dimension, controlPanel->settings.size, controlPanel->settings.B,
                             controlPanel->settings.S);
}

void Canvas::fpsUpdate() {
    this->update();
}

void Canvas::getIndex(int new_index) {
    worker->coord = new_index;
}

void Canvas::startThread(bool *new_render_data) {
    drawing = true;
    render_data = new_render_data;
    if (lifeIsRunning)
        worker->start();
}

void Canvas::nextGen() {
}

void Canvas::updateCount() {
    controlPanel->updateGeneration();
}

void Canvas::updateLife() {
}

/* Custom functions */
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    int X = event->pos().x();
    int Y = event->pos().y();

    if (onFocus)
        camera->rotation(X, Y);
}

void Canvas::leaveEvent(QEvent *event) {
    camera->setCenter(width() / 2, height() / 2);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (!onFocus) {
        setFocus();
        onFocus = true;
    } else {
        onFocus = false;
    }
    qDebug() << "on Focus = " << onFocus;
}

void Canvas::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up)
        movement[2] = true;
    if (event->key() == Qt::Key_Left)
        movement[0] = true;
    if (event->key() == Qt::Key_Down)
        movement[1] = true;
    if (event->key() == Qt::Key_Right)
        movement[3] = true;
    camera->translation(movement[0], movement[1], movement[2], movement[3]);
    for (bool &i : movement) {
        i = false;
    }
}