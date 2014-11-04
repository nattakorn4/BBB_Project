#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeclock.h"
#include "databasecomfiguretion.h"
#include "testtimer.h"
#include "controller.h"
#include "gpio_config.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new labelshowtime(this);

    //databasecomfiguretion db;

    //if(db.getdatasim() == 1){
     //   check("00000000000000000");
    //  }
    QTimer *timer = new QTimer(this);
    timer->setInterval(10000);
    connect(timer, SIGNAL(timeout()), this, SLOT(Main_Control()));
//    timer->start(1000);
    timer->start();
    Main_Control();

}
void MainWindow::test()
{
    for(int i=0;i<3;i++){
        if((i%2)==0){
             printf("aaaaaaaaa");

        }
        else{
             printf("nnnnnnnnnn \n");
        }
        SetTopic("dsfdfsdfs");
        Display_1("On");
    }


}
void MainWindow::Main_Control(){
    //===============Initial====================
    timeclock c;
    databasecomfiguretion db;
    GPIO_Config io;
    //===============Get data===================
    NDate = c.getDate();
    NHH = c.getHH();
    NMM = c.getMM();
    Size = db.getsize();

    Room_stat[1]=0;
    Room_stat[2]=0;
    Room_stat[3]=0;
    Room_stat[4]=0;
    Room_stat[5]=0;
    Room_stat[6]=0;
    Room_stat[7]=0;
    Room_stat[8]=0;
    Room_stat[9]=0;
    Room_stat[10]=0;
    Room[0] = 1;
    Room[1] = 1;
    Room[2] = 1;
    Room[3] = 2;
    Room[4] = 3;
    Room[5] = 4;
    Room[6] = 5;
    Room[7] = 9;
    Room[8] = 3;
    Room[9] = 10;
    Date[0] = 2;
    Date[1] = 2;
    Date[2] = 2;
    Date[3] = 2;
    Date[4] = 2;
    Date[5] = 2;
    Date[6] = 2;
    Date[7] = 2;
    Date[8] = 2;
    Date[9] = 2;
    SHH[0] = 13;
    SHH[1] = 13;
    SHH[2] = 13;
    SHH[3] = 13;
    SHH[4] = 13;
    SHH[5] = 13;
    SHH[6] = 13;
    SHH[7] = 13;
    SHH[8] = 13;
    SHH[9] = 13;
    EHH[0] = 24;
    EHH[1] = 24;
    EHH[2] = 24;
    EHH[3] = 24;
    EHH[4] = 24;
    EHH[5] = 24;
    EHH[6] = 24;
    EHH[7] = 24;
    EHH[8] = 24;
    EHH[9] = 24;


    //===============check======================
    for(int i=0;i<Size;i++){
        printf("%d",NDate);printf("  %d",NHH);printf("  %d",SHH[i]);printf("  %d",EHH[i]);printf("  %d",Date[i]);printf("  %d\n",i);
       if(Room[i]==1) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[1] = 1; } }
       if(Room[i]==2) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[2] = 1;  } }
       if(Room[i]==3) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[3] = 1;  } }
       if(Room[i]==4) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[4] = 1;  } }
       if(Room[i]==5) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[5] = 1;  } }
       if(Room[i]==6) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[6] = 1;  } }
       if(Room[i]==7) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[7] = 1;  } }
       if(Room[i]==8) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[8] = 1;  } }
       if(Room[i]==9) { if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[9] = 1;  } }
       if(Room[i]==10){ if(SHH[i]<=NHH && EHH[i]>NHH&&Date[i]==NDate){printf("room %d open \n",Room[i]);Room_stat[10] = 1; } }

    }
    if(Room_stat[1] == 1) {  Display_1("On");   }else{ Display_1("Off");  }
    if(Room_stat[2] == 1) {  Display_2("On");   }else{ Display_2("Off");  }
    if(Room_stat[3] == 1) {  Display_3("On");   }else{ Display_3("Off");  }
    if(Room_stat[4] == 1) {  Display_4("On");   }else{ Display_4("Off");  }
    if(Room_stat[5] == 1) {  Display_5("On");   }else{ Display_5("Off");  }
    if(Room_stat[6] == 1) {  Display_6("On");   }else{ Display_6("Off");  }
    if(Room_stat[7] == 1) {  Display_7("On");   }else{ Display_7("Off");  }
    if(Room_stat[8] == 1) {  Display_8("On");   }else{ Display_8("Off");  }
    if(Room_stat[9] == 1) {  Display_9("On");   }else{ Display_9("Off");  }
    if(Room_stat[10] == 1){  Display_10("On");  }else{ Display_10("Off"); }

    if(Room_stat[1] == 1 && io.GPIO_Getvalue(1) == 1) {  io.GPIO_Setvalue(1,1);   }else{ io.GPIO_Setvalue(1,0);  }
    if(Room_stat[2] == 1 && io.GPIO_Getvalue(2) == 1) {  io.GPIO_Setvalue(2,1);   }else{ io.GPIO_Setvalue(2,0);  }
    if(Room_stat[3] == 1 && io.GPIO_Getvalue(3) == 1) {  io.GPIO_Setvalue(3,1);   }else{ io.GPIO_Setvalue(3,0);  }
    if(Room_stat[4] == 1 && io.GPIO_Getvalue(4) == 1) {  io.GPIO_Setvalue(4,1);   }else{ io.GPIO_Setvalue(4,0);  }
    if(Room_stat[5] == 1 && io.GPIO_Getvalue(5) == 1) {  io.GPIO_Setvalue(5,1);   }else{ io.GPIO_Setvalue(5,0);  }
    if(Room_stat[6] == 1 && io.GPIO_Getvalue(6) == 1) {  io.GPIO_Setvalue(6,1);   }else{ io.GPIO_Setvalue(6,0);  }
    if(Room_stat[7] == 1 && io.GPIO_Getvalue(7) == 1) {  io.GPIO_Setvalue(7,1);   }else{ io.GPIO_Setvalue(7,0);  }
    if(Room_stat[8] == 1 && io.GPIO_Getvalue(8) == 1) {  io.GPIO_Setvalue(8,1);   }else{ io.GPIO_Setvalue(8,0);  }
    if(Room_stat[9] == 1 && io.GPIO_Getvalue(9) == 1) {  io.GPIO_Setvalue(9,1);   }else{ io.GPIO_Setvalue(9,0);  }
    if(Room_stat[10] == 1 && io.GPIO_Getvalue(10) == 1){  io.GPIO_Setvalue(10,1);  }else{ io.GPIO_Setvalue(10,0); }

}
void MainWindow::Main_Startup(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::SetTopic(QString title){

    ui->label->setText(title);
    ui->label->setStyleSheet("font: 80pt;");
    ui->label->setAlignment(Qt::AlignHCenter);


}
void MainWindow::Display_1(QString command){
    if(command == "On"){
        ui->data1->setText("On");
    }else if(command == "Off"){
        ui->data1->setText("Off");
    }else{
        ui->data1->setText("Error");
    }
}
void MainWindow::Display_2(QString command){
    if(command == "On"){
        ui->data2->setText("On");
    }else if(command == "Off"){
        ui->data2->setText("Off");
    }else{
        ui->data2->setText("Error");
    }
}
void MainWindow::Display_3(QString command){
    if(command == "On"){
        ui->data3->setText("On");
    }else if(command == "Off"){
        ui->data3->setText("Off");
    }else{
        ui->data3->setText("Error");
    }
}
void MainWindow::Display_4(QString command){
    if(command == "On"){
        ui->data4->setText("On");
    }else if(command == "Off"){
        ui->data4->setText("Off");
    }else{
        ui->data4->setText("Error");
    }
}
void MainWindow::Display_5(QString command){
    if(command == "On"){
        ui->data5->setText("On");
    }else if(command == "Off"){
        ui->data5->setText("Off");
    }else{
        ui->data5->setText("Error");
    }
}
void MainWindow::Display_6(QString command){
    if(command == "On"){
        ui->data6->setText("On");
    }else if(command == "Off"){
        ui->data6->setText("Off");
    }else{
        ui->data6->setText("Error");
    }
}
void MainWindow::Display_7(QString command){
    if(command == "On"){
        ui->data7->setText("On");
    }else if(command == "Off"){
        ui->data7->setText("Off");
    }else{
        ui->data7->setText("Error");
    }
}
void MainWindow::Display_8(QString command){
    if(command == "On"){
        ui->data8->setText("On");
    }else if(command == "Off"){
        ui->data8->setText("Off");
    }else{
        ui->data8->setText("Error");
    }
}
void MainWindow::Display_9(QString command){
    if(command == "On"){
        ui->data9->setText("On");
    }else if(command == "Off"){
        ui->data9->setText("Off");
    }else{
        ui->data9->setText("Error");
    }
}
void MainWindow::Display_10(QString command){
    if(command == "On"){
        ui->data10->setText("On");
    }else if(command == "Off"){
        ui->data10->setText("Off");
    }else{
        ui->data10->setText("Error");
    }
}

