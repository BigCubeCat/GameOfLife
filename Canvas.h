#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include "model/Life.h"
#include <QTimer>
#include <QKeyEvent>
#include "model/Thread.h"
#include "view/Camera.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"
#ifdef __linux__
    #include <GL/glut.h>
#else
    #include <GLUT/glut.h>
#endif

Camera *camera;

class Canvas : public QOpenGLWidget {
    Q_OBJECT
public:
    Thread *worker;
    vector<bool> render_data;
    float cellSize;
    float buffer;
    int WIDTH = 800; int HEIGHT = 600;
    Panel *controlPanel;
    CoordsPanel *coordsPanel;
    bool movement[4];

    float fps_speed = 0.5f;

    explicit Canvas(int n, int s, QWidget *parent = nullptr);

    ~Canvas();

    void render2d();
    void render();
    static void mouseLook(int, int);

public slots:
    void updateSettings();
    void getIndex();
    void nextGen();
private:
    QTimer *mTimer;
protected:
    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateLife();
};


#endif //GAMEOFLIFE_CANVAS_H
