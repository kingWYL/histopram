#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);
    histogramview *histoprames = new histogramview();
    this->setCentralWidget(histoprames);
    //this->centralWidget()->setStyleSheet("border: 3px solid #FFFFFF; border-radius:10px;");

}
MainWindow::~MainWindow()
{
    delete ui;
}

