#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QDebug>

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent)
{


    wgtMain_ = new QWidget(this);
    lytMain_ = new QGridLayout(wgtMain_);
    wgtMain_->setLayout(lytMain_);
    setCentralWidget(wgtMain_);
    QFont fuente;
    fuente.setPointSizeF(20);
    //wgtMain_->setFixedSize();
    wgtMain_->setFont(fuente);
    wgtMain_->setMaximumSize(500,400);
    this->setMaximumSize(500,400);
    //wgtMain_->setMinimumSize(500,500);

    createBoard();

}

SecondWindow::~SecondWindow()
{

}
void SecondWindow::createBoard(){


    for (int i = 0; i<81; i++){
        QLineEdit *p = new QLineEdit();
        vector.push_back(p);
    }

    int k = 0;
    int row = 0;
    int column = 0;

    linea = new QFrame;
    linea->setFrameShape(QFrame::VLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 0,3,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::VLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 0,7,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 3,0,1,11);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 7,0,1,11);

    //int f = 30;



    for (int i = 0; i<11; i++){
        row = 0;
        if (column !=3){
            column ++;
            for (int j = 0; j<11; j++){
                QLineEdit *p = new QLineEdit();
                //p->setFont(fuente);
                if (row!=3){
                    lytMain_->addWidget(vector[k], i,j,1,1);
                    k++;
                    row ++;
                }
                else{
                    row =0;
                }
            }
        }
        else{
            column = 0;
        }
    }
}
