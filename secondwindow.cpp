#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QDebug>
#include <QSet>

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
    wgtMain_->setMaximumSize(500,500);
    this->setMaximumSize(500,500);
    //wgtMain_->setMinimumSize(500,500);


    //toolBar_ = new QToolBar;

    menu_bar_ = new QMenuBar(this);
    //menu_opciones = new QMenu;
    this->setMenuBar(menu_bar_);


    menu_opciones = new QMenu(tr("&Menu"), this);
    menu_bar_->addMenu(menu_opciones);
    act_comprobar_sol = new QAction(tr("&Comrobar solución"), this);
    menu_opciones->addAction(act_comprobar_sol);
    menu_bar_->addMenu(menu_opciones);


   // toolBar_=addToolBar(tr("Edit"));


    createBoard();
    iniciar_cronometro();

    connect(chrono_timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(act_comprobar_sol, SIGNAL(triggered(bool)), this, SLOT(comprobacion()));
    /*connect(chrono_start_, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(chrono_stop_, SIGNAL(clicked(bool)), chrono_timer_, SLOT(stop()));*/

    //vector[5]->setReadOnly(true);


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
    lytMain_->addWidget(linea, 2,3,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::VLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 2,7,11,1);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 5,0,1,11);

    linea = new QFrame;
    linea->setFrameShape(QFrame::HLine);
    linea->setLineWidth(15);
    lytMain_->addWidget(linea, 9,0,1,11);

    //int f = 30;



    for (int i = 2; i<13; i++){
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
     QLabel *sudoku_label = new QLabel("Comprobador de Sudoku");
     sudoku_label->setAlignment(Qt::AlignCenter);


    lytMain_->addWidget(chrono_label_ = new QLabel(this), 1,0,1,0);
    lytMain_->addWidget(sudoku_label, 0,0,1,0);
    chrono_label_->setAlignment(Qt::AlignCenter);
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

int SecondWindow::get_pos(int x, int y){

    return x*9+y;

}
void SecondWindow::comprobacion(){

    if (checker())
        qDebug() << "correcto";
    else
        qDebug() << "False";

}

bool SecondWindow::checker(){
    bool sol = false;

//comprobar que no se repiten números por fila.
    QSet<int> set_;

    for (int i = 0; i <9; i++){
        for (int j = 0; j<9; j++){
            if (vector[get_pos(i,j)]->text().toInt() < 10 && vector[get_pos(i,j)]->text().toInt() > 0){ //nos asguramos de que sean números del 1 al 9.
                set_.insert(vector[get_pos(i,j)]->text().toInt());
            }
        }
        if (set_.size()!=9){
            return false;
        }

        set_.clear();

    }

//Comprobación de columnas
    set_.clear();
    for (int i = 0; i <9; i++){
        for (int j = 0; j<9; j++){
            //evitamos comprobar si son numeros del 0-9 porque ya lo hicimos para las filas;
            set_.insert(vector[get_pos(j,i)]->text().toInt());

        }
        if (set_.size()!=9){
            return false;
        }

        set_.clear();

    }

//Comprobación cuadrados internos.

    set_.clear();
    qDebug() << "cuadraditos";

    for (int k = 0; k<=6; k+=3){ // recorre filas de cuadrados
        for (int m = 0; m<=6; m+=3){ //recorre columnas de cuadrados
            for (int i = m; i<m+3; i++){//filas
                for (int j = k; j<k+3; j++){//columnas
                    set_.insert(vector[get_pos(i,j)]->text().toInt());
                }
            }
            if (set_.size()!=9){
                return false;
            }
            set_.clear();
        }

    }


    return true;
}
