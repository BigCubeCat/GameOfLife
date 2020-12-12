#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include "model/Life.h"
#include <QTimer>
#include <QKeyEvent>
#include "view/Camera.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"


class Canvas : public QOpenGLWidget {
public:
    Life *life;
    Camera *mCamera;
    vector<bool> render_data;
    int data_size;
    int dimension;
    int cellSize;
    Panel *controlPanel;
    CoordsPanel *coordsPanel;

    float fps_speed = 0.5f;

    explicit Canvas(QWidget *parent = nullptr);

    ~Canvas();

    void render2d();
    void render();

    void setSpeed(int speed);
    void setSettings(int d, int s);
    void setB(vector<int> b);
    void setS(vector<int> s);
public slots:
    void updateSettings();
    void getIndex();
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
