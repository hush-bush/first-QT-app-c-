#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>
#include<QDesktopServices>


MainWindow::MainWindow()
{
    ui->setupUi(this);  //работает не трогай
    Vnesti=new QPushButton("Input to Database", this);  //создал кнопку);
    Vnesti -> setGeometry(50, 50, 200, 30);   // расположение и длина кнопки
    Information=new QPushButton("Information about exchanhing of products", this);
    Information -> setGeometry(50, 100, 200, 30);    // расположение и длина кнопки
    Clear=new QPushButton("Clear Database", this);
    Clear -> setGeometry(50, 150, 200, 30);    // расположение и длина кнопки
    Built = new QPushButton("build a graph", this);
    Built -> setGeometry(50, 200, 200, 30);    // расположение и длина кнопки
    Exit=new QPushButton("Exit", this);
    Exit -> setGeometry(50, 250, 200, 30);     // расположение и длина кнопки
    QObject :: connect(Exit, SIGNAL(clicked()), this, SLOT(close()));     //закрытие
    QObject::connect( Information, SIGNAL(clicked()), this, SLOT(ShowInfo()));
    QObject::connect( Clear, SIGNAL(clicked()),this,SLOT(Clearing()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowInfo()
{
    system("C:\\11111\\file3.txt");
}


void MainWindow::Clearing()
{
   file->open(QIODevice::WriteOnly);
   file->close();
}

