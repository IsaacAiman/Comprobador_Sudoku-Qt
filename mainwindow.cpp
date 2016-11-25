#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->salir_, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(quit()));
    connect(ui->continuar_, SIGNAL(clicked(bool)), this, SLOT(secondwindow()));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::secondwindow(){

    this->hide();
    s = new SecondWindow();
    s->show();


}
