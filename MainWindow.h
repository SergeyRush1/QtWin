#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#endif
#include <QObject>
#include <QtWidgets/QMainWindow>
#include <ui_QtWidgetsApplication1.h>
#include <ui_MainWindow1.h>
#include <QGraphicsScene>
#include <QWidget>
#include "MoveItem.h"

class MainWindow  : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
    Ui::MainWindow ui;
    MoveItem* item;


private:
    
    QGraphicsScene* scene;

private slots:
    void on_pushButton_clicked();
    void on_push_button_2();


public slots: 
    void changeInfo(int x,int y);
    void testSlot(QString a);


signals:
    void testSignalMain(QString);



};
