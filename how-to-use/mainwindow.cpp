#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << EasyLiving::isChecked(0);
    qDebug() << EasyLiving::isChecked(1);
    qDebug() << EasyLiving::isChecked(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
