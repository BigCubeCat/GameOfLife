#include "Canvas.h"
#include <QColor>
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <cmath>

#define drawLine(x, y, z, x1, y1, z1) glVertex3f(x, y, z); glVertex3f(x1, y1, z1);
#define drawCell(t, b, l, r, f, back) glVertex3f(l, t, f);glVertex3f(r, t, f);glVertex3f(r, b, f);glVertex3f(l, b, f);glVertex3f(l, t, back);glVertex3f(r, t, back);glVertex3f(r, b, back);glVertex3f(l, b, back);glVertex3f(l, t, f);glVertex3f(l, b, f);glVertex3f(l, b, back);glVertex3f(l, t, back);glVertex3f(r, t, f);glVertex3f(r, b, f);glVertex3f(r, b, back);glVertex3f(r, t, back);glVertex3f(r, t, f);glVertex3f(r, t, back);glVertex3f(l, t, f);glVertex3f(l, t, back);glVertex3f(r, b, f);glVertex3f(r, b, back);glVertex3f(l, b, f);glVertex3f(l, b, back);

Camera *camera = new Camera(-5, 5, -5, 4 * M_PI / 7, M_PI / 4, 0.005, 0.1, 800, 600);

Canvas::Canvas(QWidget *parent)
    : QOpenGLWidget(parent) {
        this->setMouseTracking(true);
        worker = new Worker();
        // life update timeint signal qtr
        mTimer = new QTimer(this);
        mTimer->setSingleShot(false);
        mTimer->setInterval(10000);
        connect(mTimer, &QTimer::timeout, this, &Canvas::nextGen);
        mTimer->start();
        fpsTimer = new QTimer(this);
        fpsTimer->setSingleShot(false);
        fpsTimer->setInterval(fps);
        connect(fpsTimer, &QTimer::timeout, this, &Canvas::fpsUpdate);
        fpsTimer->start();
        connect(worker, &Worker::updateRender, this, &Canvas::updateRender); // rerun thread
}

void Canvas::setLife(fileData file_data) {
}

/*GL functions*/
void Canvas::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_BLEND);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void Canvas::paintGL() {
    glClearColor(controlPanel->R, controlPanel->G, controlPanel->B, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    camera->translation(movement[0], movement[1], movement[2], movement[3]);
    gluLookAt(
            camera->getX(), camera->getY(), camera->getZ(), camera->getSightX(),
            camera->getSightY(), camera->getSightZ(), 0, 1, 0);

    if (worker->D < 3) {
        render2d();
    } else {
        render();
    }

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
    glBegin(GL_QUADS);
    float __top, bottom, left, right;
    if (!drawing) return;
    for (int i = 0; i < worker->SIZE; i++) {
        for (int j = 0; j < worker->SIZE; j++) {
            if (render_data[i * worker->SIZE + j]) {
                right = (j + 1) * cellSize;
                left = j * cellSize;
                __top = i * cellSize;
                bottom = (i + 1) * cellSize;
                glColor3f(((float) i / (float) worker->SIZE), ((float) j / (float) worker->SIZE), 1.0f);
                glVertex3f(left, __top, 0.0f);
                glVertex3f(right, __top, 0.0f);
                glVertex3f(right, bottom, 0.0f);
                glVertex3f(left, bottom, 0.0f);
            }
        }
    }
    glEnd();
}

void Canvas::render() {
    if (!drawing) return;
    float right, left, _top, bottom, _forward, backward;
    for (int i = 0; i < worker->SIZE; i++) {
        for (int j = 0; j < worker->SIZE; j++) {
            for (int k = 0; k < worker->SIZE; k++) {
                if (worker->getCell(i * worker->SIZE * worker->SIZE + j * worker->SIZE + k)) {
                    right = (j + 1) * cellSize;
                    left = j * cellSize;
                    _top = i * cellSize;
                    bottom = (i + 1) * cellSize;
                    _forward = k * cellSize;
                    backward = (k + 1) * cellSize;
                    if (controlPanel->showEdges) {
                        // Draw cube sides
                        glColor3f(0.0, 0.0, 0.0);
                        glBegin(GL_LINES);
                        drawLine(right, _top, _forward, left, _top, _forward);
                        drawLine(right, bottom, _forward, left, bottom, _forward);
                        drawLine(right, bottom, backward, left, bottom, backward);
                        drawLine(right, _top, backward, left, _top, backward);
                        drawLine(right, _top, _forward, right, bottom, _forward);
                        drawLine(right, _top, backward, right, bottom, backward);
                        drawLine(left, _top, backward, left, bottom, backward);
                        drawLine(left, _top, _forward, left, bottom, _forward);
                        drawLine(left, _top, _forward, left, _top, backward);
                        drawLine(left, bottom, _forward, left, bottom, backward);
                        drawLine(right, _top, _forward, right, _top, backward);
                        drawLine(right, bottom, _forward, right, bottom, backward);
                        glEnd();
                    }
                    if (controlPanel->shadeColor) {
                        glColor3f(((float) i / (float) worker->SIZE), ((float) j / (float) worker->SIZE),
                                ((float) k / (float) worker->SIZE));
                    } else {
                        glColor3f(controlPanel->r, controlPanel->g, controlPanel->b);
                    }
                    glBegin(GL_QUADS);
                    drawCell(_top, bottom, left, right, _forward, backward);
                    glEnd();
                }
            }
        }
    }
}

/* Slots */
void Canvas::step() {
    controlPanel->updateGeneration(worker->life->generation);
    worker->start();
    lifeIsRunning = false;
}

void Canvas::stop() {
    lifeIsRunning = false;
}

void Canvas::play() {
    lifeIsRunning = true;
}

void Canvas::updateSettings() {
    mTimer->setInterval(controlPanel->settings.speed);
    worker->updateParameters(controlPanel->settings.dimension, controlPanel->settings.size, controlPanel->settings.B,
            controlPanel->settings.S, 2);
    updateRender(worker->life->renderData(worker->coord));

    coordsPanel->reshape(worker->life->N, worker->life->SIZE);
}

void Canvas::fpsUpdate() {
    this->update();
}

void Canvas::getIndex(int new_index) {
    worker->coord = new_index;
    worker->changeCoord();
    update();
}

void Canvas::updateRender(std::string new_render_data) {
    drawing = true;
    int len = new_render_data.length();
    qDebug() << "updaterender";
    if (sizeof(render_data) != len) {
        render_data = new bool[len];
    }
    qDebug() << QString::fromStdString(new_render_data);
    for (int i = 0; i < new_render_data.length(); i++) {
        if (new_render_data[i] == 'A') {
            render_data[i] = true;
        } else {
            render_data[i] = false;
        }
    }
}

void Canvas::nextGen() {
    if (lifeIsRunning && !worker->isBusy) {
        qDebug() << "Generation = " << worker->life->generation;
        controlPanel->updateGeneration(worker->life->generation);
        worker->start();
    }
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
        qDebug() << "Focused";
    } else {
        onFocus = false;
        qDebug() << "UnFocudes";
    }
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
