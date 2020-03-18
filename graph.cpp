#include "graph.h"
#include<QtCharts/qlineseries.h>
#include<QtCharts/qchart.h>
#include<QtCharts/qchartview.h>
#include<QVector>
#include<QDataStream>
#include<iostream>
#include<QDebug>
#include<QLegend>
#include<QBarSet>

QT_CHARTS_USE_NAMESPACE

graph::graph(QPushButton* activate,QFile *file)
{
    this->file=file;
    build = new QPushButton("Build",this);
        build->setGeometry(150,50,100,30);
    back = new QPushButton("Back",this);
        back->setGeometry(150,90,100,30);
    label = new QLabel("Enter name of product: ",this);
        label->setGeometry(20,10,130,30);
    edit = new QLineEdit(this);
        edit->setGeometry(150,10,100,30);
 //   this->setGeometry(400,250,1400,700);
  QObject::connect(activate, SIGNAL(clicked()),this,SLOT(show()));
  QObject::connect(back, SIGNAL(clicked()),this,SLOT(close()));
  QObject::connect(build,SIGNAL(clicked()),this,SLOT(building()));
}

void graph::building()
{
window.close();
       QVector<QString> vec;
       QVector<QString> vecsort;
       QVector<QString> masvec[100];
        QDataStream stream(file);
        int i=0;
    QLineSeries *series = new QLineSeries;

    file->open(QIODevice::ReadWrite);
    while(!file->atEnd())
    {
        stream >> vecsort;
        if (vecsort[0] == edit -> text())
        {
            masvec[i] = vecsort;
            i++;

        }
    }
    for (int j=0; j<i - 1; j++)                        //пузырёк
    {
        for (int var = 0; var < i - j - 1; ++var)
        {
            if (masvec[var][2].toInt() > masvec[var+1][2].toInt())
            {
                swap(masvec[var][0], masvec[var+1][0]);
                                swap(masvec[var][1], masvec[var+1][1]);
                swap(masvec[var][2], masvec[var+1][2]);

            }
        }
    }
    for (int j=0; j<i; j++)
    {
        series->append(masvec[j][2].toInt(), masvec[j][1].toInt());
    }

   QChart *chart = new QChart();
        chart->addSeries(series);
        chart->createDefaultAxes();


        //QBarSet *leg = new QBarSet ("apple");


       QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
           window.setCentralWidget(chartView);
            window.setGeometry(500, 300, 800, 600);
            window.setWindowTitle("Graphic");             //название окна
            chart -> legend()->setVisible(true);
            QLabel *leg = new QLabel(edit -> text(), &window);
        //    QLabel leg("Apple", &window);
            leg->setGeometry(350, 30, 50, 30);
            edit -> clear();
            window.show();
            file->close();

}
