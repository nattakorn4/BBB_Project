#include "mainwindow.h"
#include <QApplication>
#include "clock.h"
#include "databasecomfiguretion.h"
#include <QTimer>
#include "controller.h"
#include "gpio_config.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    //QTimer::singleShot(1000, &app, SLOT());
    //new databasecomfiguretion();
    GPIO_Config IO;
    IO.GPIO_Initial();
    w.show();
    //new Controller();


    //w.testtimer();
    //w.on_label_windowIconTextChanged(gett);





    //app.exec();
    return app.exec();
    //return 0;
}
