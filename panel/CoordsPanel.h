//
// Created by bigcubecat on 08.12.2020.
//

#ifndef GAMEOFLIFE_COORDSPANEL_H
#define GAMEOFLIFE_COORDSPANEL_H

#include <QWidget>
#include <QSpinBox>
QT_BEGIN_NAMESPACE
namespace Ui { class CoordsPanel; }
QT_END_NAMESPACE

#include "./ui_coords.h"
#include <QPushButton>
#include <QSpinBox>

using namespace std;

class CoordsPanel : public QWidget {
    Q_OBJECT
public:
    QHBoxLayout *m_layout;
    int size;
    int dimension;
    vector< QSpinBox * > coords;
    explicit CoordsPanel(QWidget *parent = nullptr);
    ~CoordsPanel();
    int getIndex();
    void reshape(int d, int s);
signals:
    void signalIndex(int);
private slots:
    void calculateIndex();
private:
    void clearLayout();
    int  pow(int a, int b);
    Ui::CoordsPanel *ui;
};


#endif //GAMEOFLIFE_COORDSPANEL_H
