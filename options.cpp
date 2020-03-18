#include "options.h"
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QDataStream>
#include <QDebug>
#include<stdlib.h>

Options:: Options(QPushButton *Vnesti)

{
    QObject :: connect(Vnesti, SIGNAL(clicked()),this, SLOT(show())) ;
nameofproduct=new QLabel("name of product: ", this);     //выделение памяти под таблички
nameofproduct -> setGeometry(300, 50, 600, 20);          // расположение и длина таблички
amount_of_product=new QLabel("amount of product: ", this);
amount_of_product -> setGeometry(300, 80, 220, 20);
data_of_arrival=new QLabel("date of arrival: ", this);
data_of_arrival -> setGeometry(300, 110, 220, 20);
///////////////////////////////////////////////////////
    Changezap=new QPushButton("Change string", this);  //создал кнопку);
    Changezap -> setGeometry(50, 50, 150, 30);   // расположение и длина кнопки
    ChangeAll=new QPushButton("Change All", this);
    ChangeAll -> setGeometry(50, 90, 150, 30);    // расположение и длина кнопки
    EnterToDatabase=new QPushButton("Enter to Database", this);
    EnterToDatabase -> setGeometry(300, 150, 120, 30);    // расположение и длина кнопки
   // EnterToDatabase -> setEnabled(false);
    Exit=new QPushButton("Back", this);
    Exit -> setGeometry(50, 150, 150, 30);     // расположение и длина кнопки
    CreateFile2 = new QPushButton("CreateFile2", this);
    CreateFile2 -> setGeometry(430, 150, 120, 30);    // расположение и длина кнопки
///////////////////////////////////////////////////////
        polename=new QLineEdit(this);         //выделение памяти под поле
        polename-> setGeometry(430, 50, 100, 20);       //расположение поля
        polekolvo=new QLineEdit(this);
        polekolvo-> setGeometry(430, 80, 100, 20);
        poledata=new QLineEdit(this);
        poledata-> setGeometry(430, 110, 100, 20);
//////////////////////////////////////////////////////////
            file1=new QFile("C:\\11111\\file1.txt");      //выделяю память под файлы
            file2=new QFile("C:\\11111\\file2.txt");
            file3=new QFile("C:\\11111\\file3.txt");
            file4=new QFile("C:\\11111\\file4.txt");
            EnterToDatabase->setShortcut(Qt::Key_Return);          //
        QObject :: connect(Exit, SIGNAL(clicked()), this, SLOT(close()));     //закрытие
        QObject :: connect(EnterToDatabase, SIGNAL(clicked()), this, SLOT(Enter()));
        QObject :: connect(ChangeAll, SIGNAL(clicked()), this, SLOT(Change_All()));
        QObject :: connect(CreateFile2, SIGNAL(clicked()), this, SLOT(Change_File2()));
        QObject :: connect(Changezap,SIGNAL(clicked()),this,SLOT(ChangeOne()));
}

void Options:: Enter()
{
      QVector <QString> Array;     //вектор записей
      Array << polename -> text() << polekolvo -> text() << poledata -> text();
      file1 -> open(QIODevice:: Append);
      QDataStream stream(file1);
      stream << Array;
      file1 -> close();
      polename -> clear();
      polekolvo -> clear();
      poledata -> clear();
      k++;
}

void Options :: Change_File2()
{
    QVector<QString> vec={};
    QVector<QString> vec2={};
    QVector<QString> vec3={};
    bool flag=false;
    QDataStream stream(file1);
    QDataStream stream2(file2);
    QDataStream stream3(file3);


   file1->open(QIODevice::ReadOnly);
   file2->open(QIODevice::WriteOnly);
   while(!file1->atEnd())
   {
       stream>>vec;
       stream2<<vec;
   }
   file1->close();
   file2->close();
   file1->open(QIODevice::ReadOnly);
file3->open(QIODevice::WriteOnly);
file3->close();
////////////////////////////////////////////////////////////
       while(!file1->atEnd())
       {
           file3->open(QIODevice::Append);
          stream>>vec;
           file2->open(QIODevice::ReadOnly);
           while(!file2->atEnd())
           {
               stream2>>vec2;
               if(vec[0]==vec2[0])
               {
                   if(vec[2].toInt()>vec2[2].toInt())
                   {
                       flag=true;
                      vec3=vec;
                   }
               }
           }
           if(flag)
           {
           stream3<<vec3;
           flag=false;
           }
           file2->close();
           file3->close();
        }
       file1->close();
}
void Options::Change_All()
{
    QVector<QString> vec={};
    QVector<QString> vec2={};
    QVector<QString> vec3={};
    QString mas[200];
    QDataStream stream(file1);
    bool flag=false;
    QDataStream stream2(file2);
    QDataStream stream3(file3);
     file3->open(QIODevice::ReadOnly);
     file1->open(QIODevice::WriteOnly);
     while(!file3->atEnd())
     {
         stream3 >> vec;
         stream << vec;
     }
     int i=0;
file1->close();
file3->close();
file1->open(QIODevice::ReadOnly);
    while(!file1->atEnd())
    {
        stream>>vec;
        mas[i]=vec[0];
        i++;
    }
file1->close();
file2->open(QIODevice::ReadOnly);
    while(!file2->atEnd())
    {
        stream2>>vec;
         for(int v=0;v<i;v++)
         {
             if(vec[0]==mas[v])
                 {
                    flag=true;
                 }
         }
         if(flag==false)
         {
             flag=true;
             file1->open(QIODevice::Append);
             stream<<vec;
             file1->close();
         }
         flag=false;
    }
file1->close();
file2->close();
}

void Options::ChangeOne()
{
     QVector<QString> vec={};
      QVector<QString> vec2={};
     QString a= polename->text();
      QDataStream stream(file1);
      QDataStream stream3(file3);
      QDataStream stream4(file4);
      file1->open(QIODevice::ReadOnly);
      file3->open(QIODevice::ReadOnly);
      file4->open(QIODevice::WriteOnly);
      while(!file1->atEnd())
      {
          stream>>vec;
          if(vec[0]!=a)
          stream4<<vec;
      }
      file1->close();
      file4->close();
      file1->open(QIODevice::WriteOnly);
      file4->open(QIODevice::ReadOnly);
      while(!file4->atEnd())
      {
          stream4>>vec;
          stream<<vec;
      }
      file1->close();
      file4->close();
      file1->open(QIODevice::Append);
      while(!file3->atEnd())
      {
          stream3>>vec;
          if(vec[0]==a)
              vec2=vec;
      }
      stream<<vec2;
      file1->close();
      file3->close();
      polename->clear();
}
