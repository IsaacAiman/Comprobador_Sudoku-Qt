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

    QAction             *actLimpiar_;
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
    bool checker(); //checks if the solution is right or wrong.
    void create_sudoku();
    bool check_row(int pos); //checks that no number repeats in the row of the given position.
    bool check_col(int pos); //checks that no number repeats in the column of the given position.
    bool check_area(int pos); //checks that no number repeats in the area of the given position.
private slots:

    void updateTime();
    void comprobacion ();
    void clear_board();

};

#endif // SECONDWINDOW_H
