#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Canvas *canvas;
    canvas = new Canvas();
    ui->main_layout->addWidget(canvas);

    Panel *panel = new Panel(canvas);
    ui->dockWidget->setWidget(panel);
    CoordsPanel *coordsPanel = new CoordsPanel(canvas);
    ui->coordsDock->setWidget(coordsPanel);

    canvas->controlPanel = panel;
    canvas->coordsPanel = coordsPanel;

    connect(panel, &Panel::updateData, canvas, &Canvas::updateSettings);
    connect(coordsPanel, &CoordsPanel::signalIndex, canvas, &Canvas::getIndex);

    auto visionAction = ui->dockWidget->toggleViewAction();
    visionAction->setText("View settings");
    ui->menuView->addAction(visionAction);
    auto visionCoords = ui->coordsDock->toggleViewAction();
    visionAction->setText("Navigation");
    ui->menuView->addAction(visionCoords);
    canvas->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

