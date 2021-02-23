#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Canvas.h"
#include <QStatusBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    Canvas *canvas;
    QString fileName;

    void emitWarning(QString);

    void emitMessage(QString);

    void emitError(QString);

private:
    Ui::MainWindow *ui;

    void openFile();

    void saveFile();

    void saveAs();
public slots:
    void sendMessage(QString, int);

};

#endif // MAINWINDOW_H
