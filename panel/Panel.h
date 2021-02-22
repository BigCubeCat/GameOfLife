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
#include "intpow.h"
#include "io/io.h"
#include <QColor>
#include <QColorDialog>

using namespace std;

struct Settings {
    vector<int> B;
    vector<int> S;
    int size;
    int dimension;
    int speed;
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

    ~Panel();

    void updateGeneration(int);

    void updateSettings(int, int, QString, QString);

    QString getB();

    QString getS();

signals:

    void updateData();

    void playSignal();

    void stopSignal();

    void stepSignal();

private slots:

    void clearSettings();

    void applySettings();

    void recomendedSettings();

    void changeColor();

    void checkShade();

    void checkEdge();

    void changeBG();

private:
    Ui::Panel *ui;
};

#endif //GAMEOFLIFE_PANEL_H
