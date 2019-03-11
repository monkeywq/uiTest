#include "uiTest.h"
#include <QMessageBox>
#include <QLabel>
#include <math.h>
#include <QFileDialog>
#include <QtCore/QTextStream>
#include <QTime>

#define PI acos(-1)
uiTest::uiTest(QWidget *parent)
	: QMainWindow(parent)
{
	GK = "f=0.1Hz";
	firstAxisA = 0;
	firstAxisF = 0;
	secondAxisA = 0;
	secondAxisF = 0;
	GKNumber = 0;
	GKFile = new QFile("./GK/gk1.txt");

	ui.setupUi(this);

	QAction *openAction = new QAction(QStringLiteral("打开"), this);
	firstAxisMap = new QPixmap(ui.firstAxis->width(),ui.firstAxis->height());
	firstAxisMapPainter = new QPainter(firstAxisMap);
	secondAxisMap = new QPixmap(ui.secondAxis->width(),ui.secondAxis->height());
	secondAxisMapPainter = new QPainter(secondAxisMap);
	firstAxisMap->fill(Qt::white);
	secondAxisMap->fill(Qt::white);

	firstAxisMapX0 = ui.firstAxis->x();
	firstAxisMapY0 = ui.firstAxis->y();
	firstAxisMapH = ui.firstAxis->height();
	firstAxisMapW = ui.firstAxis->width();

	secondAxisMapX0 = ui.secondAxis->x();
	secondAxisMapY0 = ui.secondAxis->y();
	secondAxisMapH = ui.secondAxis->height();
	secondAxisMapW = ui.secondAxis->width();
	//ui.label->setPixmap(*pixMap);
	if (ui.checkBox->isChecked() == true)
	{
		ui.lineEdit->setEnabled(false);
		ui.lineEdit_2->setEnabled(false);
		ui.lineEdit_3->setEnabled(false);
		ui.lineEdit_4->setEnabled(false);
		ui.pushButton_6->setEnabled(false);
		ui.lineEdit_5->setEnabled(true);
		ui.pushButton_5->setEnabled(true);
	}
	else
	{
		ui.lineEdit->setEnabled(true);
		ui.lineEdit_2->setEnabled(true);
		ui.lineEdit_3->setEnabled(true);
		ui.lineEdit_4->setEnabled(true);
		ui.pushButton_6->setEnabled(true);
		ui.lineEdit_5->setEnabled(false);
		ui.pushButton_5->setEnabled(false);
	}
	
	
	
	p = new QPen;
	drawAxis(firstAxisMapPainter);
	drawAxis(secondAxisMapPainter);
	p->setColor(Qt::blue);
	p->setWidth(2);
	p->setStyle(Qt::SolidLine);
	firstAxisMapPainter->setPen(*p);
	drawCurve(firstAxisMapPainter,1,2);
	ui.firstAxis->setPixmap(*firstAxisMap);
	p->setColor(Qt::red);
	secondAxisMapPainter->setPen(*p);
	drawCurve(secondAxisMapPainter,1,3);
	ui.secondAxis->setPixmap(*secondAxisMap);

	

	ui.lineEdit->setText(QString("%1").arg(firstAxisA));
	ui.lineEdit_2->setText(QString("%1").arg(firstAxisF));
	ui.lineEdit_3->setText(QString("%1").arg(secondAxisF));
	ui.lineEdit_4->setText(QString("%1").arg(secondAxisA));

//串口
	serialPort = new QSerialPort;
	serialPortTest = new QSerialPort;
	//QString com = "COM3";
	//serialPort->setPortName(com);
	//serialPort->open(QIODevice::ReadWrite);

	//if (serialPort->isOpen() == true)
	//{
	//	QMessageBox::about(NULL, "message", "open success");
	//}


	connect(ui.openAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	connect(ui.closeAction,SIGNAL(triggered()), this, SLOT(slotTest2()));
	

}



void uiTest::showCurve()
{
	firstAxisMap->fill(Qt::white);
	drawAxis(firstAxisMapPainter);
	//p->setColor(Qt::blue);
	//firstAxisMapPainter->setPen(*p);
	drawCurve(firstAxisMapPainter,firstAxisF, firstAxisA);
	ui.firstAxis->setPixmap(*firstAxisMap);

	secondAxisMap->fill(Qt::white);
	drawAxis(secondAxisMapPainter);
	//p->setColor(Qt::red);
	//secondAxisMapPainter->setPen(*p);
	drawCurve(secondAxisMapPainter, secondAxisF, secondAxisA);
	ui.secondAxis->setPixmap(*secondAxisMap);
}
void uiTest::drawAxis(QPainter *painter)
{
	QPen p(Qt::black, 1);
	QPen p0 = painter->pen();
	p.setStyle(Qt::DashLine);
	painter->setPen(p);
	
	int y = firstAxisMapY0;
	int x = firstAxisMapX0;
	while (y < firstAxisMapY0 + firstAxisMapH)
	{
		y += firstAxisMapH / 6;
		painter->drawLine(firstAxisMapX0, y, firstAxisMapX0 + firstAxisMapW, y);
		
	}
	while (x < firstAxisMapX0 + firstAxisMapW)
	{
		x += firstAxisMapW / 5;
		painter->drawLine(x, firstAxisMapY0, x,firstAxisMapY0 + firstAxisMapH);
		
	}

	painter->setPen(p0);
	painter->drawText(0, 100, tr("0000000000"));

	

}
void uiTest::drawCurve(QPainter *painter,float f,float A)
{
	int x0 = firstAxisMapX0;
	int sinx, siny, sinx0, siny0;
	int y0 = firstAxisMapY0 + 0.5*firstAxisMapH;
	float tMax = 5;
	int tDiv = 1000;
	float dt = tMax/tDiv;
	float dtPix = (float)firstAxisMapW / tDiv;
	float AMaxPix = firstAxisMapH / 3;
	float AMaxVal = 3;
	sinx0 = x0;
	siny0 = y0;
	
	//p.setWidth(2);
	//p.setStyle(Qt::SolidLine);
	//p.setColor(Qt::blue);
	//painter->setPen(*pen);
	for (int i = 0; i < tDiv; i++)
	{
		sinx = x0 + i*dtPix;
		siny = y0 - sin(f*2*PI*i*dt)*A/AMaxVal*AMaxPix;
		painter->drawLine(sinx0, siny0, sinx, siny);
		//painter->drawPoint(sinx, siny);

		sinx0 = sinx;
		siny0 = siny;
	}
}
void uiTest::serialPortInit(QSerialPort *s,QString *n)
{
	currentTime = QTime::currentTime();
	QString timeStr=currentTime.toString("hh:mm:ss");
	s->setPortName(*n);
	if (s->isOpen() == true)
	{
		
		//s->close();
		//QMessageBox::about(NULL, "warning", "serialport is already opened!");
		return;
	}
	s->open(QIODevice::ReadWrite);
	if (s->isOpen() == false)
	{
		//QMessageBox::about(NULL, "warning", "fail!");
		timeStr = "fail   " + timeStr;
		ui.textBrowser->append(timeStr);
		return;
	}
	//s->setDataTerminalReady(true);
	s->setBaudRate(QSerialPort::Baud9600);
	s->setDataBits(QSerialPort::Data8);
	s->setParity(QSerialPort::NoParity);
	s->setStopBits(QSerialPort::OneStop);
	s->setFlowControl(QSerialPort::NoFlowControl);
	QMessageBox::about(NULL, "message", "successful!");
	timeStr = "serial port is opened  " + timeStr;
	ui.textBrowser->append(timeStr);
	//ui.textBrowser->setText("OK!");
	connect(serialPort,SIGNAL(readyRead()), this, SLOT(slotSerialPortReciveData()));
}

void uiTest::slotSerialPortReciveData()
{
	QString str = "OK";
	serialReciveData(serialPort, &str);
}
void uiTest::serialReciveData(QSerialPort *s, QString *str)
{
	
	
	//ui.textBrowser->append("OK");
	QByteArray buf = s->readAll();
	QString strbuf = buf;
	if (!buf.isEmpty())
	{
		
		QMessageBox::about(NULL, "message", "OK");
		ui.textBrowser->append(strbuf);
	}
}

void uiTest::serialSendData(QSerialPort *s, QString *str)
{
	ui.textBrowser->append(ui.lineEdit->text());
	s->write(ui.lineEdit->text().toLatin1());
	//QMessageBox::about(NULL, "message", "OK");
}
void uiTest::serialPortClose(QSerialPort *s, QString *n)
{
	s->setPortName(*n);
	s->close();
}
void uiTest::openFileAsTxt(int GKNumber)
{
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open image file"),
		"./GK/", tr("Text files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm *.txt);;All files (*.*)"));

	if (fileName.isEmpty())
	{
		return;
	}
	else
	{
		//QFile f(fileName);
		delete GKFile;
		GKFile = new QFile(fileName);
		setGKNumber();
		/*if (!GKFile->open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::about(NULL, "warning", "faile");
			return;
		}
		QTextStream txtInput(GKFile);
		txtInput.seek(0);
		int line = 0;
		QString str1;
		while (line<=GKNumber)
		{
			if (txtInput.atEnd() == true)
			{
				break;
				QMessageBox::warning(NULL, CN("警告"), CN("找不到该工况！"));
			}
			str1= txtInput.readLine();
			line++;
		}
		QMessageBox::about(NULL, "me",str1);
		GKFile->close();*/
		//QMessageBox::about(NULL, "messge", "sucessful");
	}
}
void uiTest::setGKNumber()
{
	if (!GKFile->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::about(NULL, "warning", "faile");
		return;
	}
	QTextStream txtInput(GKFile);
	txtInput.seek(0);
	int line = 0;
	QString str1;
	while (line <= GKNumber)
	{
		if (txtInput.atEnd() == true)
		{
			
			QMessageBox::warning(NULL, CN("警告"), CN("找不到该工况！"));
			return;
		}
		str1 = txtInput.readLine();
		line++;
	}
	
	QStringList list=str1.split(" ");
	firstAxisA = list[2].toFloat();
	firstAxisF = list[4].toFloat();
	secondAxisA = list[6].toFloat();
	secondAxisF = list[8].toFloat();
	QMessageBox::about(NULL, "me", QString::number(list[2].toInt()));
	GKFile->close();
}
void uiTest::saveFileAsTxt(QString str)
{
	QString fileName = tr("./GK/gk2.txt");
	QFile f(fileName);
	f.open(QIODevice::ReadOnly | QIODevice::Text);
	int lineNumber = 0;
	QTextStream txtInPut(&f);
	while (!txtInPut.atEnd())
	{
		QString str;
		str+= txtInPut.readLine();
		lineNumber++;
	}
	f.close();///获取行号

	f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
	QTextStream txtOutPut(&f);
	txtOutPut <<QString::number(lineNumber)+": "+str << endl;
	
	f.close();
}

