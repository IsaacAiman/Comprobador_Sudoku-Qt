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
    iniciar_cronometro();

    connect(chrono_timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    /*connect(chrono_start_, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(chrono_stop_, SIGNAL(clicked(bool)), chrono_timer_, SLOT(stop()));*/




}

SecondWindow::~SecondWindow()
{

}
void SecondWindow::createBoard(){


    for (int i = 0; i<81; i++){
        QLineEdit *p = new QLineEdit();
        p->setMaxLength(1);
        p->setAlignment(Qt::AlignHCenter);
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

    //Label del chronometro
     lytMain_->addWidget(chrono_label_ = new QLabel(this), 12,0,5,5);
    //label de Salir
    //label de mostrar solución
    //label de comprobar

}

void SecondWindow::iniciar_cronometro(){

    chrono_timer_=new QTimer;
    startTime_ = new QTime;



    chrono_label_->setText(QTime(0, 0).toString());
   // lytMain_->addWidget(chrono_start_ = new QPushButton("start", this), 5,12,5,5);
   // lytMain_->addWidget(chrono_stop_ = new QPushButton("stop", this),   6,12,5,5);

    QFont fuente;
    fuente.setPointSizeF(10);
    chrono_label_->setFont(fuente);

    startTime_->start();
    chrono_timer_->start(1000);


}

void SecondWindow::updateTime(){

    chrono_label_->setText(QTime(0, 0).addMSecs(startTime_->elapsed()).toString());

}

