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
    int INDEX = 0;
    QHBoxLayout *m_layout;
    int size;
    int life_size;
    vector< QSpinBox * > coords;
    explicit CoordsPanel(QWidget *parent = nullptr);
    ~CoordsPanel();
    int getIndex();
    void reshape(int s, int ls);
signals:
    void signalIndex();
private slots:
    void calculateIndex();
private:
    Ui::CoordsPanel *ui;
};


#endif //GAMEOFLIFE_COORDSPANEL_H
