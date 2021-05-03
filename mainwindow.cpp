#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include "panel/Panel.h"
#include "panel/CoordsPanel.h"
#include "io/io.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
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
    connect(panel, &Panel::updateRules, canvas, &Canvas::updateRules);
    connect(panel, &Panel::updateSpeed, canvas, &Canvas::updateSpeed);
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
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveAs);

    connect(canvas, &Canvas::emitMessage, this, &MainWindow::sendMessage);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openFile() {
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "", tr("Game Of Life(*.life *.json)"));
    try {
        auto file_data = readFile(fileName);
        canvas->worker->setLife(file_data);
        canvas->controlPanel->updateSettings(file_data.D, file_data.SIZE, file_data.stringB, file_data.stringS);
        canvas->coordsPanel->reshape(canvas->worker->life->N, canvas->worker->life->SIZE);
        emitMessage(QString("Success"));
    }  catch (int a) {
        emitError(QString("Read Error"));
    }
}

void MainWindow::saveFile() {
    if (fileName.length() > 0) {
        saveToFile(fileName, canvas->worker->getData(canvas->controlPanel->getB(), canvas->controlPanel->getS()));
    } else {
        saveAs();
    }
    emitMessage(fileName + QString(" written"));
}

void MainWindow::saveAs() {
    fileName = QFileDialog::getSaveFileName(
            this, tr("Save File"), fileName, tr("Life Files (*.json *.life *.txt)")
    );
    saveFile();
}

void MainWindow::emitWarning(QString text) {
    QStatusBar *bar = this->statusBar();
    bar->showMessage(text);
    bar->setStyleSheet("background-color:yellow;");
}

void MainWindow::emitMessage(QString text) {
    QStatusBar *bar = this->statusBar();
    bar->showMessage(text);
    bar->setStyleSheet("");
}

void MainWindow::emitError(QString text) {
    QStatusBar *bar = this->statusBar();
    bar->showMessage(text);
    bar->setStyleSheet("background-color:red;");
}

void MainWindow::sendMessage(QString text, int d) {
    if (d == 0) {
        emitMessage(text);
    } else if (d == 1) {
        emitWarning(text);
    }
}
