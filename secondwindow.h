#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QMenu>
#include <QGridLayout>
#include <QSlider>
#include <QVector>
#include <QLineEdit>
#include <QWidget>
#include <QLine>
#include <QFrame>
#include <QFont>
#include <QElapsedTimer>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QString>
#include <QMessageBox>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
    int get_pos(int x, int y);

private:
    //QFont               *fuente;
    QAction             *actOpciones_;
    QToolBar            *toolBar_;
    QMenuBar            *menu_bar_;
    QMenu               *menu_opciones;
    QAction             *act_comprobar_sol;
    QTime               *startTime_;
    QTimer              *chrono_timer_;
    QLabel              *chrono_label_;
    QPushButton         *chrono_start_;
    QPushButton         *chrono_stop_;
    QFrame              *linea;
    QWidget             *wgtMain_;
    Ui::SecondWindow    *ui;
    QGridLayout*        lytMain_;
    QSlider*            volumeSlider_;
    QVector<QLineEdit*> vector;
    void createBoard();
    void iniciar_cronometro();
    bool checker();
private slots:

    void updateTime();
    void comprobacion ();
    //void start();

};

#endif // SECONDWINDOW_H
