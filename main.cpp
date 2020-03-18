#include "mainwindow.h"
#include "options.h"
#include"graph.h"
#include <QApplication>
#include <QPushButton>
#include<QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;   //создал окно
    Options Opt(w.Vnesti); //окно опшнс
    w.file=Opt.file1;
    Opt.setGeometry(500,300, 560, 240);        // размеры опшнс окна
    Opt.setWindowTitle("Input to Database");             //название ошнс окна
    w.setGeometry(500,300, 300, 350);          // размеры главного окна
   graph k(w.Built,Opt.file2);                 //окно графика
    k.setGeometry(500,300, 300, 150);          // размеры окна графика
    w.setWindowTitle("Stock 1.0");             //название главного окна
    w.show();
    return a.exec();
}
