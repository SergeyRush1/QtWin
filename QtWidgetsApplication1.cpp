#include "QtWidgetsApplication1.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <stdio.h>
#include <QDebug>
#include "MainWindow.h"

//#include <QTextCodec>
#pragma execution_character_set("utf-8")
using namespace std;


QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
  //  connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(whenButtonIsClicked()));
  //  connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(openDialogClicked()));
   // connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(whenButtonIsClicked()));
   
}
//void QtWidgetsApplication1::whenButtonIsClicked()
//{
   // MainWindow z;
   
    //z.show();
    
    //QString cyrillicName = QString::fromLocal8Bit("словоЌа ириллице");
   // ui.label->setText(cyrillicName);

   // ui->label->setText("the button has been clicked !");
//}
/*
void QtWidgetsApplication1::openDialogClicked() {
  
  
    QString cyrillicName = QString::fromLocal8Bit("словоЌа ириллице");
  //  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Massage", cyrillicName);
    if (reply== QMessageBox::Yes)
    {
        QString cyrillicName = QString::fromLocal8Bit("ƒј");
        ui.label->setText(cyrillicName);
        QApplication::quit();
    }
    else {
        QString cyrillicName = QString::fromLocal8Bit("нет");
        ui.label->setText(cyrillicName);
    

    }

    */
//}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}
