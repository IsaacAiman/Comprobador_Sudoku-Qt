#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SecondWindow s;

    w.show();


    return a.exec();
}
