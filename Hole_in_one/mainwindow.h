#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:

};

#endif // MAINWINDOW_H
