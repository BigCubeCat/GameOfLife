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
    setWindowTitle("N-Dimension Game Of Life");

    Canvas *canvas;
    canvas = new Canvas(3, 32);
    ui->main_layout->addWidget(canvas);

    Panel *panel = new Panel(canvas);
    ui->dockWidget->setWidget(panel);
    CoordsPanel *coordsPanel = new CoordsPanel(canvas);
    ui->coordsDock->setWidget(coordsPanel);

    canvas->controlPanel = panel;
    canvas->coordsPanel = coordsPanel;

    connect(panel, &Panel::updateData, canvas, &Canvas::updateSettings);
    connect(coordsPanel, &CoordsPanel::signalIndex, canvas, &Canvas::getIndex);
    connect(panel, &Panel::playSignal, canvas, &Canvas::play);
    connect(panel, &Panel::stopSignal, canvas, &Canvas::stop);
    connect(panel, &Panel::stepSignal, canvas, &Canvas::step);

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

