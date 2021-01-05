#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include "model/Life.h"
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
    Worker *worker;
    QVector<bool> render_data;
    float cellSize;
    bool onFocus = false;
    Panel *controlPanel;
    CoordsPanel *coordsPanel;
    bool movement[4];
    bool lifeIsRunning = false;

    int fps = 10;

    explicit Canvas(int n, int s, QWidget *parent = nullptr);

    ~Canvas();

    void render2d();
    void render();
    static void mouseLook(int, int);

public slots:
    void updateSettings();
    void getIndex(int);
    void nextGen();
    void pause();
    void updateCount();
    void fpsUpdate();
    void startThread(QVector<bool>);
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
