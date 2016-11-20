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
    volumeSlider_ = new QSlider(Qt::Horizontal);


   // QLine *linea = new QLine;
   // QFrame *linea = new QFrame;
    //linea->setFrameShape(QFrame::VLine);

    //lytMain_->addWidget(linea, 4,0,1,9);
    /*volumeSlider_->setRange(0, 100);
    volumeSlider_->setSliderPosition(100);*/

    /*lytMain_->addWidget(volumeSlider_, 2,4,1,1);
    lytMain_->addWidget(volumeSlider_, 1,4,1,1);*/




    for (int i = 0; i<81; i++){
        qDebug() << "for";
        QLineEdit *p = new QLineEdit();
        vector.push_back(p);
    }

    int k = 0;
    int row = 0;
    int column = 0;

    qDebug() << "adasdas";
    QFrame *linea = new QFrame;
    linea->setFrameShape(QFrame::VLine);
    lytMain_->addWidget(linea, 0,3,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::VLine);
    lytMain_->addWidget(linea, 0,7,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    lytMain_->addWidget(linea, 3,0,1,11);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    lytMain_->addWidget(linea, 7,0,1,11);

    for (int i = 0; i<11; i++){
        row = 0;

        if (column !=3){
            column ++;
            for (int j = 0; j<11; j++){
                QLineEdit *p = new QLineEdit();
                if (row!=3){
                    lytMain_->addWidget(vector[k], i,j,1,1);
                    k++;
                    row ++;
                }
                else{
                    row =0;
                    //j--;
                }
            }

        }
        else{
            column = 0;
        }
      //lytMain_->addWidget(vector[i], 0,i,1,1);
      //lytMain_->addWidget(vector[i], i,0,1,1);
    }

}

SecondWindow::~SecondWindow()
{

}
