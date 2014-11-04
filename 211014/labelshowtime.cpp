#include "labelshowtime.h"
#include <QDateTime>
#include "databasecomfiguretion.h"

labelshowtime::labelshowtime(QWidget *parent):
    QLabel(parent)
{
    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    //new databasecomfiguretion();

    connect(timer,SIGNAL(timeout()),
            this,SLOT(ShowTime()));
    timer->start();
    ShowTime();
    resize(500,100);
    //setStyleSheet("background: yellow");
    setStyleSheet("font: 50pt;");
}
void labelshowtime::ShowTime()
{
  setText( QTime::currentTime().toString("hh:mm:ss"));


}

