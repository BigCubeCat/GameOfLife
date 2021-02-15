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
        explicit Panel(QWidget* parent = nullptr);

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

    private:
        Ui::Panel* ui;
};

#endif //GAMEOFLIFE_PANEL_H
