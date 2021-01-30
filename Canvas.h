#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H
#include <QOpenGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include "model/Worker.h"
#include "view/Camera.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"
#include <vector>

#ifdef __linux__

#include <GL/glut.h>

#else
#include <GLUT/glut.h>
#endif


class Canvas : public QOpenGLWidget {
Q_OBJECT
public:
    Worker *worker;                                         /* Game Of Life model's controller */
    bool *render_data;                                      /* data for render */
    float cellSize = 2.0f;                                  /* cell size on drawing */
    bool onFocus = false;                                   /* mouse movement enable when onFocus = true */
    Panel *controlPanel;                                    /* panel for setup model */
    CoordsPanel *coordsPanel;                               /* panel for move and navigate on 4+D space */
    bool movement[4];
    bool lifeIsRunning = false;
    bool drawing = false;

    int fps = 10;

    explicit Canvas(int n, int s, QWidget *parent = nullptr);

    void render2d();

    void render();

public slots:

    void play();

    void step();

    void stop();

    void updateSettings();

    void getIndex(int);

    void nextGen();

    void updateCount();

    void fpsUpdate();

    void startThread(std::string);

private:
    QTimer *mTimer;
    QTimer *fpsTimer;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void leaveEvent(QEvent *event) override;

protected:
    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void updateLife();

};


#endif //GAMEOFLIFE_CANVAS_H
