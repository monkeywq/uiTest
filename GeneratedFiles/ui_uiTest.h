/********************************************************************************
** Form generated from reading UI file 'uiTest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITEST_H
#define UI_UITEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiTestClass
{
public:
    QAction *openAction;
    QAction *closeAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *secondLabel;
    QLabel *secondAxis;
    QHBoxLayout *horizontalLayout_2;
    QLabel *firstlabel;
    QLabel *firstAxis;
    QTextBrowser *textBrowser;
    QComboBox *comboBox_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *uiTestClass)
    {
        if (uiTestClass->objectName().isEmpty())
            uiTestClass->setObjectName(QStringLiteral("uiTestClass"));
        uiTestClass->resize(799, 713);
        openAction = new QAction(uiTestClass);
        openAction->setObjectName(QStringLiteral("openAction"));
        openAction->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/uiTest/Resources/ICon/folder.ico"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        closeAction = new QAction(uiTestClass);
        closeAction->setObjectName(QStringLiteral("closeAction"));
        closeAction->setIcon(icon);
        centralWidget = new QWidget(uiTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(209, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, -1, -1, -1);
        secondLabel = new QLabel(centralWidget);
        secondLabel->setObjectName(QStringLiteral("secondLabel"));
        secondLabel->setMinimumSize(QSize(48, 200));
        secondLabel->setMaximumSize(QSize(48, 200));

        horizontalLayout->addWidget(secondLabel);

        secondAxis = new QLabel(centralWidget);
        secondAxis->setObjectName(QStringLiteral("secondAxis"));
        secondAxis->setMinimumSize(QSize(500, 200));
        secondAxis->setMaximumSize(QSize(500, 200));
        secondAxis->setCursor(QCursor(Qt::CrossCursor));
        secondAxis->setFrameShape(QFrame::WinPanel);

        horizontalLayout->addWidget(secondAxis);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        firstlabel = new QLabel(centralWidget);
        firstlabel->setObjectName(QStringLiteral("firstlabel"));
        firstlabel->setMinimumSize(QSize(48, 200));
        firstlabel->setMaximumSize(QSize(48, 200));

        horizontalLayout_2->addWidget(firstlabel);

        firstAxis = new QLabel(centralWidget);
        firstAxis->setObjectName(QStringLiteral("firstAxis"));
        firstAxis->setMinimumSize(QSize(500, 200));
        firstAxis->setMaximumSize(QSize(500, 200));
        firstAxis->setCursor(QCursor(Qt::CrossCursor));
        firstAxis->setFrameShape(QFrame::WinPanel);

        horizontalLayout_2->addWidget(firstAxis);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 2, 2);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(200, 20));
        comboBox_2->setMaximumSize(QSize(200, 20));

        gridLayout_2->addWidget(comboBox_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 168, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 2, 3, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 20));
        pushButton_3->setMaximumSize(QSize(50, 20));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 20));
        pushButton_7->setMaximumSize(QSize(50, 20));

        horizontalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 20));
        pushButton_8->setMaximumSize(QSize(50, 20));

        horizontalLayout_4->addWidget(pushButton_8);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(71, 20));
        checkBox->setMaximumSize(QSize(71, 20));

        verticalLayout_2->addWidget(checkBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(160, 20));
        lineEdit_5->setMaximumSize(QSize(160, 20));

        horizontalLayout_7->addWidget(lineEdit_5);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(40, 20));
        pushButton_5->setMaximumSize(QSize(40, 20));

        horizontalLayout_7->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(23, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(61, 20));
        lineEdit->setMaximumSize(QSize(61, 20));

        horizontalLayout_5->addWidget(lineEdit);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(10, 20));
        label_3->setMaximumSize(QSize(10, 20));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(61, 20));
        lineEdit_2->setMaximumSize(QSize(61, 20));

        horizontalLayout_5->addWidget(lineEdit_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(10, 20));
        label_4->setMaximumSize(QSize(10, 20));

        horizontalLayout_5->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(23, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(61, 20));
        lineEdit_3->setMaximumSize(QSize(61, 20));

        horizontalLayout_6->addWidget(lineEdit_3);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(10, 20));
        label_5->setMaximumSize(QSize(10, 20));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(61, 20));
        lineEdit_4->setMaximumSize(QSize(61, 20));

        horizontalLayout_6->addWidget(lineEdit_4);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(10, 20));
        label_6->setMaximumSize(QSize(10, 20));

        horizontalLayout_6->addWidget(label_6);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(verticalLayout_4, 4, 0, 2, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 23));
        pushButton->setMaximumSize(QSize(75, 23));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(75, 23));
        pushButton_2->setMaximumSize(QSize(75, 23));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(75, 23));
        pushButton_4->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        uiTestClass->setCentralWidget(centralWidget);
        comboBox_2->raise();
        textBrowser->raise();
        menuBar = new QMenuBar(uiTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        uiTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(uiTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        uiTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(uiTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        uiTestClass->setStatusBar(statusBar);
        toolBar = new QToolBar(uiTestClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        uiTestClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        toolBar->addAction(openAction);

        retranslateUi(uiTestClass);
        QObject::connect(checkBox, SIGNAL(stateChanged(int)), uiTestClass, SLOT(slotControlInput()));
        QObject::connect(pushButton, SIGNAL(clicked()), uiTestClass, SLOT(slotViewCurve()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), uiTestClass, SLOT(slotSerialPortInit()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), uiTestClass, SLOT(slotSerialPortSendData()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), uiTestClass, SLOT(slotSerialPortReciveData()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), uiTestClass, SLOT(slotSerialPortClose()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), uiTestClass, SLOT(slotSerialPortTestInit()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), uiTestClass, SLOT(slotSaveFile()));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotChangeGKPram()));
        QObject::connect(lineEdit_2, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotChangeFirstAxisF()));
        QObject::connect(lineEdit_2, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotChangeGKPram()));
        QObject::connect(lineEdit_3, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotChangeGKPram()));
        QObject::connect(lineEdit_4, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotChangeGKPram()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), uiTestClass, SLOT(slotSelectGKFile()));
        QObject::connect(lineEdit_5, SIGNAL(textChanged(QString)), uiTestClass, SLOT(slotSelectGKNumber()));

        QMetaObject::connectSlotsByName(uiTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *uiTestClass)
    {
        uiTestClass->setWindowTitle(QApplication::translate("uiTestClass", "UI\346\265\213\350\257\225", 0));
        openAction->setText(QApplication::translate("uiTestClass", "\346\211\223\345\274\200", 0));
        closeAction->setText(QApplication::translate("uiTestClass", "\345\205\263\351\227\255", 0));
        secondLabel->setText(QApplication::translate("uiTestClass", "\350\276\205\350\275\264\346\263\242\345\275\242", 0));
        secondAxis->setText(QString());
        firstlabel->setText(QApplication::translate("uiTestClass", "\344\270\273\350\275\264\346\263\242\345\275\242", 0));
        firstAxis->setText(QString());
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("uiTestClass", "COM1", 0)
         << QApplication::translate("uiTestClass", "COM2", 0)
         << QApplication::translate("uiTestClass", "COM3", 0)
         << QApplication::translate("uiTestClass", "COM4", 0)
         << QApplication::translate("uiTestClass", "COM5", 0)
         << QApplication::translate("uiTestClass", "COM6", 0)
        );
        pushButton_3->setText(QApplication::translate("uiTestClass", "\350\277\236\346\216\245", 0));
        pushButton_7->setText(QApplication::translate("uiTestClass", "\346\226\255\345\274\200", 0));
        pushButton_8->setText(QApplication::translate("uiTestClass", "\346\265\213\350\257\225", 0));
        checkBox->setText(QApplication::translate("uiTestClass", "\350\207\252\345\212\250\346\250\241\345\274\217", 0));
        pushButton_5->setText(QApplication::translate("uiTestClass", "\346\265\217\350\247\210", 0));
        label->setText(QApplication::translate("uiTestClass", "\344\270\273\350\275\264 \345\271\205\345\200\274\343\200\201\351\242\221\347\216\207", 0));
        label_3->setText(QApplication::translate("uiTestClass", "Pi", 0));
        label_4->setText(QApplication::translate("uiTestClass", "Hz", 0));
        label_2->setText(QApplication::translate("uiTestClass", "\350\276\205\350\275\264 \345\271\205\345\200\274\343\200\201\351\242\221\347\216\207", 0));
        label_5->setText(QApplication::translate("uiTestClass", "Pi", 0));
        label_6->setText(QApplication::translate("uiTestClass", "Hz", 0));
        pushButton->setText(QApplication::translate("uiTestClass", "\351\242\204\350\247\210", 0));
        pushButton_2->setText(QApplication::translate("uiTestClass", "\350\277\220\350\241\214", 0));
        pushButton_4->setText(QApplication::translate("uiTestClass", "\345\201\234\346\255\242", 0));
        pushButton_6->setText(QApplication::translate("uiTestClass", "\344\277\235\345\255\230\345\267\245\345\206\265", 0));
        menu->setTitle(QApplication::translate("uiTestClass", "\346\226\207\344\273\266", 0));
        toolBar->setWindowTitle(QApplication::translate("uiTestClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class uiTestClass: public Ui_uiTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITEST_H
