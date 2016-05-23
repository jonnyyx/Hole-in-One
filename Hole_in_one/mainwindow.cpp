#include "mainwindow.h"

MainWindow::MainWindow()
{
    setupUi(this);
    resize(400, 400);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Background, Qt::green);
    this->setPalette(Qt::green);
    this->show();
//    palette->setBrush(QPalette::Background, *(new QBrush(*(new QPixmap(":/pic/back.png")))));
//    setPalette(*palette);

//  setWindowFlags(Qt::FramelessWindowHint);
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(new QPushButton("Level"),1,0,1,1);
    layout->addWidget(new QPushButton("Highscore"),2,0,1,1);
    layout->addWidget(new QPushButton("Quit"),3,0,1,1);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}
MainWindow::~MainWindow()
{
}
