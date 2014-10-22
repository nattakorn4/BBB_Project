#include "testtimer.h"
#include "iostream"
#include <QTimer>


testtimer::testtimer()
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(test1()));
    timer->start(1000);
//    timer->start();
    //test1();

}
void testtimer::test1()
{
    for(int i=0;i<1;i++){
        if((i%2)==0){
             printf("aaaaaaaaa");

        }
        else{
             printf("nnnnnnnnnn \n");
        }
    }


}

