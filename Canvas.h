#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include "model/Life.h"
#include <QTimer>
#include <QKeyEvent>
#include "view/Camera.h"


class Canvas : public QOpenGLWidget {
public:
    Life *life;
    Camera mCamera;
    bool mode3d = false;
    int ***render_data;
    int data_size;

    float fps_speed = 0.5f;

    explicit Canvas(QWidget *parent = nullptr);

    ~Canvas();

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
