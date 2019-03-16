#include "uiTest.h"
#include <QMessageBox>
#include <QLabel>
#include <math.h>
#include <QFileDialog>
#include <QtCore/QTextStream>
#include <QTime>
void uiTest::slotSerialPortTestInit()
{
	QString name = "COM6";
	serialPortInit(serialPortTest, &name);
}
void uiTest::slotSerialPortClose()
{
	QString name = ui.comboBox_2->currentText();
	QString str;
	serialPortClose(serialPort, &name);
	currentTime = QTime::currentTime();
	str = "serial port is closed  " + currentTime.toString("hh:mm:ss");
	ui.textBrowser->append(str);
	ui.pushButton_2->setDisabled(true);
}
void uiTest::slotSerialPortSendData()
{
	QString s = "OK";
	ui.pushButton_2->setDisabled(true);
	ui.pushButton_4->setEnabled(true);
	serialSendData(serialPort, &s);
}
void uiTest::slotSerialPortInit()
{
	QString name = ui.comboBox_2->currentText();
	serialPortInit(serialPort, &name);
	if (serialPort->isOpen() == true)
	{
		ui.pushButton_2->setEnabled(true);
	}
}
void uiTest::slotControlInput()
{
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
}
void uiTest::slotTest2()
{
	QMessageBox::about(NULL, "Message", "Close");
}
void uiTest::slotOpenFile()
{
}

void uiTest::slotSaveFile()
{
	QString s1;
	int choose;
	//s1 = QString("%1").arg(firstAxisA);
	s1 = CN("主轴幅值")+" " + QString("%1").arg(firstAxisA) + " "+CN("主轴频率") +" "+QString("%1").arg(firstAxisF) 
		+ " " + CN("副轴幅值") + " " + QString("%1").arg(secondAxisA) + " " + CN("副轴频率") + " " + QString("%1").arg(secondAxisF);
	choose=QMessageBox::question(this, CN("保存"), CN("是否保存该工况？"), QMessageBox::Yes | QMessageBox::No);
	if (choose == QMessageBox::Yes)
	{
		saveFileAsTxt(s1);
	}

}
void uiTest::slotViewCurve()
{
	if (ui.checkBox->isChecked() == false)
	{
		firstAxisA = ui.lineEdit->text().toFloat();
		firstAxisF = ui.lineEdit_2->text().toFloat();
		secondAxisA = ui.lineEdit_3->text().toFloat();
		secondAxisF = ui.lineEdit_4->text().toFloat();
		showCurve();
	}
	else
	{
		GKNumber = ui.lineEdit_5->text().toInt();
		setGKNumber();
		ui.lineEdit->setText(QString::number(firstAxisA));
		ui.lineEdit_2->setText(QString::number(firstAxisF));
		ui.lineEdit_3->setText(QString::number(secondAxisA));
		ui.lineEdit_4->setText(QString::number(secondAxisF));
		showCurve();
	}
}
void uiTest::slotChangeGKPram()
{
	firstAxisA = ui.lineEdit->text().toFloat();
	firstAxisF = ui.lineEdit_2->text().toFloat();
	secondAxisA = ui.lineEdit_3->text().toFloat();
	secondAxisF = ui.lineEdit_4->text().toFloat();
}
void uiTest::slotSelectGKFile()
{
	openFileAsTxt(GKNumber);
}
void uiTest::slotSelectGKNumber()
{
	GKNumber = ui.lineEdit_5->text().toInt();
	GKNumber = ui.lineEdit_5->text().toInt();
	//QMessageBox::about(NULL, "OK", "OK");

}
void uiTest::slotStopSys()
{
	if (serialPort->isOpen() == true)
	{
		QMessageBox::about(this, "about", "OK");
		ui.pushButton_2->setEnabled(true);
		ui.pushButton_4->setDisabled(true);
		QString strData = "{s}";
		QByteArray byteData = strData.toLatin1();
		serialPort->write(byteData);
	}
}
