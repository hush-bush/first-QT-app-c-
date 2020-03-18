#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QFile>

#include<QMainWindow>
class graph : public QWidget
{
    Q_OBJECT
public:
    explicit graph(QPushButton *activate,QFile *file);
QPushButton *build;
QPushButton *back;
QLineEdit *edit;
QLabel *label;
QFile *file;
QMainWindow window;

signals:

public slots:
void building();
};

#endif // GRAPH_H
