#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"
#include "reader/reader.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("N-Dimension Game Of Life");

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
    connect(panel, &Panel::playSignal, canvas, &Canvas::play);
    connect(panel, &Panel::stopSignal, canvas, &Canvas::stop);
    connect(panel, &Panel::stepSignal, canvas, &Canvas::step);

    auto visionAction = ui->dockWidget->toggleViewAction();
    visionAction->setText("Control Panel");
    ui->menuView->addAction(visionAction);
    auto visionCoords = ui->coordsDock->toggleViewAction();
    visionCoords->setText("Navigation");
    ui->menuView->addAction(visionCoords);
    canvas->setFocus();

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile() {
    auto fileName = QFileDialog::getOpenFileName(this, 
            tr("Open Image"), "", tr("Game Of Life(*.life *.json)"));

    auto file_data = readFile(fileName);
    canvas->setLife(file_data);
}
