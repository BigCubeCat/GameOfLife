#include "Canvas.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <cmath>

Camera *camera = new Camera(10, -10, 10, 4 * M_PI / 7, M_PI / 4, 0.005, 0.01, 800, 600);

Canvas::Canvas(int n, int s, QWidget *parent)
    : QOpenGLWidget(parent)
{
    this->setMouseTracking(true);
    worker = new Thread(n, s);
    // life update timer
    mTimer = new QTimer(this);
    mTimer->setSingleShot(false);
    mTimer->setInterval(1);
    connect(mTimer, &QTimer::timeout, this, &Canvas::nextGen);
    mTimer->start();
    // fps update timer
    fpsTimer = new QTimer(this);
    fpsTimer->setSingleShot(false);
    fpsTimer->setInterval(fps);
    connect(fpsTimer, &QTimer::timeout, this, &Canvas::fpsUpdate);
    fpsTimer->start();
    connect(worker, &Thread::generationFinished, this, &Canvas::startThread); // rerun thread
    worker->start();
}

Canvas::~Canvas() {
    worker->life->clear_data();
}
/*GL functions*/
void Canvas::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glutInit(0, nullptr);
    glEnable(GL_COLOR_MATERIAL);
    //glutPassiveMotionFunc(mouseLook);
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
    cellSize = (float)worker->life->SIZE / (float)minimum;
    int centerX = this->width() / 2;
    int centerY = this->height() / 2;
    camera->setCenter(centerX, centerY);
}
/*render*/
void Canvas::render2d() {
    float _top, bottom, left, right;
    if (render_data.empty()) return;
    for (int i = 0; i < worker->life->SIZE; i++) {
        for (int j = 0; j < worker->life->SIZE; j++) {
            if (render_data[i * worker->life->SIZE + j]) {
                right = (j + 1) * cellSize;
                left = j * cellSize;
                _top = i * cellSize;
                bottom = (i + 1) * cellSize;
                glColor3f(((float)i / (float)worker->life->SIZE), ((float)j / (float)worker->life->SIZE), 1.0f);
                glVertex3f(left, _top, -5.0f);
                glVertex3f(right, _top, -5.0f);
                glVertex3f(right, bottom, -5.0f);
                glVertex3f(left, bottom, -5.0f);
            }
        }
    }
}

void Canvas::render() {
    float t, b, l, r, f, back;
    if (render_data.empty()) return;
    for (int i = 0; i < worker->life->SIZE; i++) {
        for (int j = 0; j < worker->life->SIZE; j++) {
            for (int k = 0; k < worker->life->SIZE; k++) {
                if (worker->life->getCell(i * worker->life->SIZE * worker->life->SIZE + j * worker->life->SIZE + k)) {
                    r = (j + 1) * cellSize;
                    l = j * cellSize;
                    t = i * cellSize;
                    b = (i + 1) * cellSize;
                    f = k * cellSize;
                    back = (k + 1) * cellSize;
                    glColor3f(((float)i / (float)worker->life->SIZE), ((float)j / (float)worker->life->SIZE), ((float)k / (float)worker->life->SIZE));

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
                }
            }
        }
    }
}
/* Slots */
void Canvas::updateSettings() {
    worker->life->setNewParams(controlPanel->settings.dimension, controlPanel->settings.size);
    worker->life->B = controlPanel->settings.B;
    worker->life->S = controlPanel->settings.S;
    mTimer->setInterval(controlPanel->settings.speed);
    qDebug() << "Update Settings";
}
void Canvas::pause() {
    lifeIsRunning = !lifeIsRunning;
}
void Canvas::fpsUpdate() {
    this->update();
}
void Canvas::getIndex() {
    // TODO
}
void Canvas::startThread(QVector<bool> new_render_data) {
    render_data = new_render_data;
    qDebug()<<"thread start";
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
void Canvas::keyPressEvent(QKeyEvent* event) {
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