#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include<QFile>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    QPushButton *Vnesti;
    QPushButton *Information; //создал кнопку
    QPushButton *Clear; //создал кнопку
    QPushButton *Built; //создал кнопку
    QPushButton *Exit; //создал кнопку
    QFile *file;
private:
    Ui::MainWindow *ui;
public slots:
    void ShowInfo();
    void Clearing();

};

#endif // MAINWINDOW_H
