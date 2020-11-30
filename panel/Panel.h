#ifndef GAMEOFLIFE_PANEL_H
#define GAMEOFLIFE_PANEL_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Panel; }
QT_END_NAMESPACE

#include "./ui_panel.h"

class Panel : public QWidget {
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr);

    ~Panel();

private:
    Ui::Panel *ui;
};


#endif //GAMEOFLIFE_PANEL_H
