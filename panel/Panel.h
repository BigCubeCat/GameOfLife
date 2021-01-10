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
using namespace std;

struct Settings {
    int *B;
    int *S;
    int size;
    int dimension;
    int speed;
};

class Panel : public QWidget {
    Q_OBJECT

public:
    Settings settings;
    Settings default_settings;
    explicit Panel(QWidget* parent = nullptr);

    ~Panel();

    void updateGeneration();
signals:
    void updateData();
    void playSignal();
    void stopSignal();
    void stepSignal();
private slots:
    void clearSettings();
    void applySettings();

private:
    Ui::Panel* ui;
};

#endif //GAMEOFLIFE_PANEL_H
