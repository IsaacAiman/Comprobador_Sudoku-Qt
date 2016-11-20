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

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private:
    QWidget             *wgtMain_;
    Ui::SecondWindow    *ui;
    QMenuBar*           menu_;
    QGridLayout*        lytMain_;
    QSlider*            volumeSlider_;
    QVector<QLineEdit*> vector;
    void createBoard();
};

#endif // SECONDWINDOW_H
