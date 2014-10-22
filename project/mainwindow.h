#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include "labelshowtime.h"
#include "databasecomfiguretion.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void settime();
    ~MainWindow();
    QTimer *timer;
    void SetTopic(QString title);
    void Display_1(QString command);
    void Display_2(QString command);
    void Display_3(QString command);
    void Display_4(QString command);
    void Display_5(QString command);
    void Display_6(QString command);
    void Display_7(QString command);
    void Display_8(QString command);
    void Display_9(QString command);
    void Display_10(QString command);

private slots:
    void test();
    void Main_Control();
    void Main_Startup();


private:
    Ui::MainWindow *ui;
    qint32 Room[10];        //Room Number
    qint32 Date[10];        //Date
    qint32 SHH[40];         //HH Start
    qint32 EHH[40];         //HH End
    qint32 SMM[40];         //MM Start
    qint32 EMM[40];         //MM End
    qint32 Size;
    qint32 NDate;           //Date Now
    qint32 NHH;             //HH Now
    qint32 NMM;             //MM Now
    qint32 Room_stat[11];

};

#endif // MAINWINDOW_H
