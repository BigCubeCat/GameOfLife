#ifndef GAMEOFLIFE_PANEL_H
#define GAMEOFLIFE_PANEL_H

#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Panel;
}
QT_END_NAMESPACE

#include "./ui_panel.h"
#include "utils/intpow.h"
#include "io/io.h"
#include <QColor>
#include <QColorDialog>

using namespace std;

struct Settings {
    vector<int> B;
    vector<int> S;
    int size = 16;
    int dimension = 3;
    int speed = 75;
    int probability = 0;
    int x = 0;
    int y = 0; 
    int z = 0;
};

class Panel : public QWidget {
Q_OBJECT

public:
    Settings settings;
    Settings default_settings;

    explicit Panel(QWidget *parent = nullptr);

    float r, g, b;
    float R = 0.4;
    float G = 0.4;
    float B = 0.4;
    bool shadeColor = true;
    bool showEdges = true;
    bool showMap = false;
    bool showAxis = true;

    ~Panel();

    void updateGeneration(int);

    void updateSettings(int, int, QString, QString);

    QString getB();

    QString getS();

signals:

    void updateData();

    void updateRules();

    void playSignal();

    void stopSignal();

    void stepSignal();

    void updateSpeed();
    
    void setCellSignal();

private slots:

    void setCell();
    
    //void getCoordForCell();

    void generateWorld();

    void lobanovRules();

    void applyRules();

    void relativeRules();

    void setSpeed();

    void changeColor();

    void checkShade();

    void checkEdge();

    void checkMap();

    void checkAxis();

    void changeBG();

    void aliveSliderChanged();

private:
    Ui::Panel *ui;
};

#endif //GAMEOFLIFE_PANEL_H
