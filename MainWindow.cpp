#include "MainWindow.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <stdio.h>
#include <QDebug>
#include <QGraphicsView>
#include <QSpinBox>
#include "MoveItem.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	this->resize(640, 640);          // Устанавливаем размеры окна приложения

	//this->setFixedSize(640, 640);




	scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
	
	scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
	ui.verticalWidget->resize(600, 600);
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
	ui.graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
	ui.graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

	
	scene->setSceneRect(0, 0, 1000, 1000); // Устанавливаем размер сцены


	item = new MoveItem();        // Создаём графический элемента
	item->setPos(40.56,    // Устанавливаем случайную позицию элемента
		30);
	scene->addItem(item);   // Добавляем элемент на графическую сцену

		connect(item, &MoveItem::testSignal, this, &MainWindow::testSlot);
	
	//ui.label->setText(QString::number((item->pos()).x())); 
	
		//connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_push_button_2()));
		connect(this, &MainWindow::testSignalMain, item, &MoveItem::testSlots2);
	//connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButton()));
	//connect(this, &QtWidgetsApplication2::signal, form, &QtWidgetsClass::slot);
	//connect(form, &QtWidgetsClass::signalForm, this, &QtWidgetsApplication2::slotsForm);
	

}

MainWindow::~MainWindow()
{}
void MainWindow::changeInfo(int x, int y) {
	ui.label->setText(QString::number(x));
}
void MainWindow::testSlot(QString a) {
	ui.label->setText(a);
}
void MainWindow::on_pushButton_clicked()
{
	
	MoveItem* item = new MoveItem();        // Создаём графический элемента
	item->setPos(40,    // Устанавливаем случайную позицию элемента
		30);
	scene->addItem(item);   // Добавляем элемент на графическую сцену
	connect(item, &MoveItem::testSignal, this, &MainWindow::testSlot);
//	QPointF as = item->pos();
//	connect(item, &MoveItem::mouseMoveEvent, this, &MainWindow::changeInfo);

}
void MainWindow::on_push_button_2() {
	emit testSignalMain("dsdssdss");


}

