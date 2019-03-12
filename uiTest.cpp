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
	firstAxisA = 0;   //主轴幅值
	firstAxisF = 0;  //主轴频率
	secondAxisA = 0;  //副轴幅值
	secondAxisF = 0; //副轴频率
	GKNumber = 0;    //工况编号
	GKFile = new QFile("./GK/gk1.txt");  //工况文件
	ui.setupUi(this);

	QAction *openAction = new QAction(QStringLiteral("打开"), this);   //打开文件动作
	firstAxisMap = new QPixmap(ui.firstAxis->width(),ui.firstAxis->height());   // 主轴波形画布
	firstAxisMapPainter = new QPainter(firstAxisMap);                       // 主轴波形画笔
	secondAxisMap = new QPixmap(ui.secondAxis->width(),ui.secondAxis->height());   // 副轴波形画布
	secondAxisMapPainter = new QPainter(secondAxisMap);          // 副轴波形画笔
	firstAxisMap->fill(Qt::white);
	secondAxisMap->fill(Qt::white);

	firstAxisMapX0 = ui.firstAxis->x();          //主轴画布位置、尺寸
	firstAxisMapY0 = ui.firstAxis->y();
	firstAxisMapH = ui.firstAxis->height();
	firstAxisMapW = ui.firstAxis->width();

	secondAxisMapX0 = ui.secondAxis->x();       // 副轴画布位置、尺寸
	secondAxisMapY0 = ui.secondAxis->y();
	secondAxisMapH = ui.secondAxis->height();
	secondAxisMapW = ui.secondAxis->width();    
	
	if (ui.checkBox->isChecked() == true)   //check框勾选，自动模式，工况参数不可自定义，只能选择工况编号
	{
		ui.lineEdit->setEnabled(false);
		ui.lineEdit_2->setEnabled(false);
		ui.lineEdit_3->setEnabled(false);
		ui.lineEdit_4->setEnabled(false);
		ui.pushButton_6->setEnabled(false);
		ui.lineEdit_5->setEnabled(true);
		ui.pushButton_5->setEnabled(true);
	}
	else                                  //未勾选，手动模式，工况参数自定义，可以保存工况
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
	drawAxis(firstAxisMapPainter);  //画主轴网格
	drawAxis(secondAxisMapPainter); // 画副轴网格

	p->setColor(Qt::blue);			
	p->setWidth(2);
	p->setStyle(Qt::SolidLine);
	firstAxisMapPainter->setPen(*p);
	drawCurve(firstAxisMapPainter,1,2);  //画主轴曲线
	ui.firstAxis->setPixmap(*firstAxisMap); 

	p->setColor(Qt::red);             //画副轴曲线
	secondAxisMapPainter->setPen(*p);
	drawCurve(secondAxisMapPainter,1,3);
	ui.secondAxis->setPixmap(*secondAxisMap);

	

	ui.lineEdit->setText(QString("%1").arg(firstAxisA));  //主轴幅值输入框
	ui.lineEdit_2->setText(QString("%1").arg(firstAxisF));  // 主轴频率输入框
	ui.lineEdit_3->setText(QString("%1").arg(secondAxisF));  //副轴幅值输入框
	ui.lineEdit_4->setText(QString("%1").arg(secondAxisA));  //副轴频率输入框

//串口
	serialPort = new QSerialPort;
	serialPortTest = new QSerialPort;

	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
	setFixedSize(this->width(), this->height());                     // 禁止拖动窗口大小

	connect(ui.openAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	connect(ui.closeAction,SIGNAL(triggered()), this, SLOT(slotTest2()));
	

}


//显示曲线
void uiTest::showCurve()
{

	QPen pp;
	/**********主轴************/
	firstAxisMap->fill(Qt::white);  //填白
	drawAxis(firstAxisMapPainter);  //绘制网格
	drawCurve(firstAxisMapPainter,firstAxisF, firstAxisA);  //绘制曲线
	ui.firstAxis->setPixmap(*firstAxisMap);    //显示画布
	/**********副轴************/
	secondAxisMap->fill(Qt::white); 
	drawAxis(secondAxisMapPainter);
	drawCurve(secondAxisMapPainter, secondAxisF, secondAxisA);
	ui.secondAxis->setPixmap(*secondAxisMap);
	//QByteArray a
}
//绘制网格
void uiTest::drawAxis(QPainter *painter)
{
	QPen p(Qt::black, 1);
	QPen p0 = painter->pen();
	p.setStyle(Qt::DashLine);
	painter->setPen(p);
	
	int y = firstAxisMapY0;
	int x = firstAxisMapX0;
	while (y < firstAxisMapY0 + firstAxisMapH)  //绘制y轴，从y0到y0+H，均匀绘制
	{
		y += firstAxisMapH / 6;                //6等分y轴
		painter->drawLine(firstAxisMapX0, y, firstAxisMapX0 + firstAxisMapW, y);
		
	}
	while (x < firstAxisMapX0 + firstAxisMapW) //绘制x轴，从x0到x0+W，均匀绘制
	{
		x += firstAxisMapW / 5;      //5等分x轴
		painter->drawLine(x, firstAxisMapY0, x,firstAxisMapY0 + firstAxisMapH);
		
	}

	painter->setPen(p0);
//	painter->drawText(0, 100, tr("0000000000"));

	

}
//绘制曲线
void uiTest::drawCurve(QPainter *painter,float f,float A)
{
	int x0 = firstAxisMapX0;    //主轴map
	int sinx, siny, sinx0, siny0;
	int y0 = firstAxisMapY0 + 0.5*firstAxisMapH;
	float tMax = 10;          //最大10s
	int tDiv = 1000;
	float dt = tMax/tDiv;   //步长为10/1000s
	float dtPix = (float)firstAxisMapW / tDiv;
	float AMaxPix = firstAxisMapH / 3;  //最大幅值像素
	float AMaxVal = 90;   //幅值最大90度
	sinx0 = x0;
	siny0 = y0;
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
	static QByteArray pastData = {};  //第一段数据
	QByteArray buffData = s->readAll();  //读取当前数据
	QByteArray readData;

	if ((!buffData.contains("{"))&(pastData.isNull()))//异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
	{
		return;
	}
	else if((buffData.contains("{"))&(!buffData.contains("}")))//第一种：有头无尾，先清空原有内容，再附加
	{
			pastData.clear();
			pastData.append(buffData);
	}
	//第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
	else if ((!buffData.contains("{"))&(!buffData.contains("}"))&(!pastData.isNull()))
	{
		pastData.append(buffData);
	}
	//第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
	else if ((!buffData.contains("{"))&(buffData.contains("}"))&(!pastData.isNull()))
	{
		pastData.append(buffData);
		readData = pastData;
		pastData.clear();
	}
	//第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
	else if ((buffData.contains("{"))&(buffData.contains("}")))
	{
		pastData.clear();
		pastData.append(buffData);
		readData = pastData;
		pastData.clear();
	}

}

void uiTest::serialSendData(QSerialPort *s, QString *str)
{
	
	if (s->isOpen() == true)
	{
		QString strData = '{'+ui.lineEdit->text() + ',' + ui.lineEdit_2->text() + ',' + ui.lineEdit_3->text() + ',' + ui.lineEdit_4->text()+'}';
		QByteArray byteData = strData.toLatin1();
		s->write(byteData);
		ui.textBrowser->append(ui.lineEdit->text());
	}
	else
	{
		QMessageBox::warning(this, CN("警告"), CN("串口未打开！"));
	}
	
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

