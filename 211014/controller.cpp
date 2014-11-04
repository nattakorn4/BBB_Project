#include "controller.h"
#include "mainwindow.h"

Controller::Controller()
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(10000);
    connect(timer, SIGNAL(timeout()), this, SLOT(test1()));
    timer->start(5000);
}
void Controller::test1()
{
    printf("12345678654321\n");

}
