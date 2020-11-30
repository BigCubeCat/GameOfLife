#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include "panel/Panel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Canvas *wgt = new Canvas();
    ui->main_layout->addWidget(wgt);

    Panel *panel = new Panel();
    ui->dockWidget->setWidget(panel);

    auto visionAction = ui->dockWidget->toggleViewAction();
    visionAction->setText("View settings");
    ui->menuView->addAction(visionAction);
    wgt->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

