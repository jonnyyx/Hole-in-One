#include "mainwindow.h"
#include <QWidget>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(1000,800);
    push=new QPushButton(this);
    push->setText(tr("push the button"));
    push->move(600,600);
    push->adjustSize();
    push->show();
}

MainWindow::~MainWindow()
{

}
