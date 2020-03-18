#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFile>

class Options : public QWidget
{
    Q_OBJECT
public:
    explicit Options(QPushButton *Vnesti);
    QPushButton *Changezap;         //кнопки
    QPushButton *ChangeAll;
    QPushButton *Exit;
    QPushButton *EnterToDatabase;
    QPushButton *CreateFile2;
        QLabel *nameofproduct;        //метки
        QLabel *amount_of_product;
        QLabel *data_of_arrival;
            QLineEdit *polekolvo;     //записи
            QLineEdit *polename;
            QLineEdit *poledata;
                QFile *file1;        //файлы
                QFile *file2;
                QFile *file3;
                QFile *file4;
                int k=0;        //количество раз введенных полей
signals:



public slots:
void Change_All();

void Enter();

void Change_File2();

void ChangeOne();

};

#endif // OPTIONS_H
