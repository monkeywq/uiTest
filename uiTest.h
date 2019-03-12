#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_uiTest.h"
#include <QPainter>
#include <QtSerialPort/QSerialPort>
#include <QtserialPort/QSerialPortInfo>
#include <QTime>
#include <QFile>

# define CN QStringLiteral
class uiTest : public QMainWindow
{
	Q_OBJECT
	
public:
	//QPixmap *firstAxisMap;
	//QPainter *firstAxisMapPainter;
	//QPixmap *secondAxisMap;
	//QPainter *secondAxisMapPainter;
	//QPen *p;
	//int firstAxisMapX0,firstAxisMapY0;
	//int secondAxisMapX0, secondAxisMapY0;
	//int firstAxisMapW, firstAxisMapH;
	//int secondAxisMapW, secondAxisMapH;
	//float firstAxisF, firstAxisA;
	//float secondAxisF, secondAxisA;
	//int GKNumber;
	//QFile *GKFile;
	//QTime currentTime;
	//QSerialPort *serialPort;
	//QSerialPort *serialPortTest;
	//QString GK;
	
public:
	uiTest(QWidget *parent = Q_NULLPTR);
	void drawAxis(QPainter *painter);
	void drawCurve(QPainter *painter, float f, float A);
	void serialPortInit(QSerialPort *s, QString *n);
	void serialSendData(QSerialPort *s,QString *str);
	void serialReciveData(QSerialPort *s, QString *str);
	void serialPortClose(QSerialPort *s, QString *n);
	void openFileAsTxt(int GKNumber);
	void saveFileAsTxt(QString str);
	void showCurve();
	void setGKNumber();
private slots:
	 void slotOpenFile();
	 void slotTest2();
	 void slotControlInput();
	 void slotViewCurve();
	 void slotSerialPortInit();
	 void slotSerialPortSendData();
	 void slotSerialPortReciveData();
	 void slotSerialPortClose();
	 void slotSerialPortTestInit();
	 void slotSaveFile();
	 void slotChangeGKPram();
	 void slotSelectGKFile();
	 void slotSelectGKNumber();
private:
	Ui::uiTestClass ui;
	QPixmap *firstAxisMap;
	QPainter *firstAxisMapPainter;
	QPixmap *secondAxisMap;
	QPainter *secondAxisMapPainter;
	QPen *p;
	int firstAxisMapX0, firstAxisMapY0;
	int secondAxisMapX0, secondAxisMapY0;
	int firstAxisMapW, firstAxisMapH;
	int secondAxisMapW, secondAxisMapH;
	float firstAxisF, firstAxisA;
	float secondAxisF, secondAxisA;
	int GKNumber;
	QFile *GKFile;
	QTime currentTime;
	QSerialPort *serialPort;
	QSerialPort *serialPortTest;
	QString GK;
};
