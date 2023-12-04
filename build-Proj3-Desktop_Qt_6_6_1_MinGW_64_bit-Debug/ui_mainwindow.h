/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QWidget *widget;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(819, 646);
        MainWindow->setStyleSheet(QString::fromUtf8("background: rgb(202, 255, 204)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(-20, 540, 871, 64));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background: rgb(63, 114, 70)"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 60, 831, 481));
        label->setStyleSheet(QString::fromUtf8("background: rgb(99, 175, 104)"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, -20, 841, 80));
        widget->setMinimumSize(QSize(841, 0));
        widget->setStyleSheet(QString::fromUtf8("background:rgb(63, 114, 70)"));
        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(400, 30, 91, 31));
        radioButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0)"));
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(510, 30, 91, 31));
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0)\n"
""));
        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(100, 30, 81, 31));
        comboBox->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font-family: OCR-A-Extended;\n"
"font-size: 12px;"));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(250, 30, 81, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font-family: OCR-A-Extended;\n"
"font-size: 12px;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(670, 30, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)\n"
""));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");
        customPlot->setGeometry(QRect(10, 70, 791, 461));
        MainWindow->setCentralWidget(centralwidget);
        widget->raise();
        plainTextEdit->raise();
        label->raise();
        customPlot->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 819, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "                       																						UFO Map", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Alpha Shape:", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Convex Hull:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "-Select-", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Cigar", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Cone", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Diamond", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Disk", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Egg", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Oval", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "Teardrop", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "Changing", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "Fireball", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "Formation", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "Flash", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "Light", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("MainWindow", "Other", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("MainWindow", "Unknown", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "-Select-", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "1910", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "2012", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "2011", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "2010", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "2009", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "2008", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "2007", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "2006", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("MainWindow", "2005", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("MainWindow", "2004", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("MainWindow", "2003", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("MainWindow", "2002", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("MainWindow", "2001", nullptr));
        comboBox_2->setItemText(14, QCoreApplication::translate("MainWindow", "2000", nullptr));
        comboBox_2->setItemText(15, QCoreApplication::translate("MainWindow", "1999", nullptr));
        comboBox_2->setItemText(16, QCoreApplication::translate("MainWindow", "1998", nullptr));
        comboBox_2->setItemText(17, QCoreApplication::translate("MainWindow", "1997", nullptr));
        comboBox_2->setItemText(18, QCoreApplication::translate("MainWindow", "1996", nullptr));
        comboBox_2->setItemText(19, QCoreApplication::translate("MainWindow", "1995", nullptr));
        comboBox_2->setItemText(20, QCoreApplication::translate("MainWindow", "1994", nullptr));
        comboBox_2->setItemText(21, QCoreApplication::translate("MainWindow", "1993", nullptr));
        comboBox_2->setItemText(22, QCoreApplication::translate("MainWindow", "1992", nullptr));
        comboBox_2->setItemText(23, QCoreApplication::translate("MainWindow", "1991", nullptr));
        comboBox_2->setItemText(24, QCoreApplication::translate("MainWindow", "1990", nullptr));
        comboBox_2->setItemText(25, QCoreApplication::translate("MainWindow", "1989", nullptr));
        comboBox_2->setItemText(26, QCoreApplication::translate("MainWindow", "1988", nullptr));
        comboBox_2->setItemText(27, QCoreApplication::translate("MainWindow", "1987", nullptr));
        comboBox_2->setItemText(28, QCoreApplication::translate("MainWindow", "1986", nullptr));
        comboBox_2->setItemText(29, QCoreApplication::translate("MainWindow", "1985", nullptr));
        comboBox_2->setItemText(30, QCoreApplication::translate("MainWindow", "1984", nullptr));
        comboBox_2->setItemText(31, QCoreApplication::translate("MainWindow", "1983", nullptr));
        comboBox_2->setItemText(32, QCoreApplication::translate("MainWindow", "1982", nullptr));
        comboBox_2->setItemText(33, QCoreApplication::translate("MainWindow", "1981", nullptr));
        comboBox_2->setItemText(34, QCoreApplication::translate("MainWindow", "1980", nullptr));
        comboBox_2->setItemText(35, QCoreApplication::translate("MainWindow", "1979", nullptr));
        comboBox_2->setItemText(36, QCoreApplication::translate("MainWindow", "1978", nullptr));
        comboBox_2->setItemText(37, QCoreApplication::translate("MainWindow", "1977", nullptr));
        comboBox_2->setItemText(38, QCoreApplication::translate("MainWindow", "1976", nullptr));
        comboBox_2->setItemText(39, QCoreApplication::translate("MainWindow", "1975", nullptr));
        comboBox_2->setItemText(40, QCoreApplication::translate("MainWindow", "1974", nullptr));
        comboBox_2->setItemText(41, QCoreApplication::translate("MainWindow", "1973", nullptr));
        comboBox_2->setItemText(42, QCoreApplication::translate("MainWindow", "1972", nullptr));
        comboBox_2->setItemText(43, QCoreApplication::translate("MainWindow", "1971", nullptr));
        comboBox_2->setItemText(44, QCoreApplication::translate("MainWindow", "1970", nullptr));
        comboBox_2->setItemText(45, QCoreApplication::translate("MainWindow", "1969", nullptr));
        comboBox_2->setItemText(46, QCoreApplication::translate("MainWindow", "1968", nullptr));
        comboBox_2->setItemText(47, QCoreApplication::translate("MainWindow", "1967", nullptr));
        comboBox_2->setItemText(48, QCoreApplication::translate("MainWindow", "1966", nullptr));
        comboBox_2->setItemText(49, QCoreApplication::translate("MainWindow", "1965", nullptr));
        comboBox_2->setItemText(50, QCoreApplication::translate("MainWindow", "1964", nullptr));
        comboBox_2->setItemText(51, QCoreApplication::translate("MainWindow", "1963", nullptr));
        comboBox_2->setItemText(52, QCoreApplication::translate("MainWindow", "1962", nullptr));
        comboBox_2->setItemText(53, QCoreApplication::translate("MainWindow", "1961", nullptr));
        comboBox_2->setItemText(54, QCoreApplication::translate("MainWindow", "1960", nullptr));
        comboBox_2->setItemText(55, QCoreApplication::translate("MainWindow", "1959", nullptr));
        comboBox_2->setItemText(56, QCoreApplication::translate("MainWindow", "1958", nullptr));
        comboBox_2->setItemText(57, QCoreApplication::translate("MainWindow", "1957", nullptr));
        comboBox_2->setItemText(58, QCoreApplication::translate("MainWindow", "1956", nullptr));
        comboBox_2->setItemText(59, QCoreApplication::translate("MainWindow", "1955", nullptr));
        comboBox_2->setItemText(60, QCoreApplication::translate("MainWindow", "1954", nullptr));
        comboBox_2->setItemText(61, QCoreApplication::translate("MainWindow", "1953", nullptr));
        comboBox_2->setItemText(62, QCoreApplication::translate("MainWindow", "1952", nullptr));
        comboBox_2->setItemText(63, QCoreApplication::translate("MainWindow", "1951", nullptr));
        comboBox_2->setItemText(64, QCoreApplication::translate("MainWindow", "1950", nullptr));
        comboBox_2->setItemText(65, QCoreApplication::translate("MainWindow", "1949", nullptr));
        comboBox_2->setItemText(66, QCoreApplication::translate("MainWindow", "1948", nullptr));
        comboBox_2->setItemText(67, QCoreApplication::translate("MainWindow", "1947", nullptr));
        comboBox_2->setItemText(68, QCoreApplication::translate("MainWindow", "1946", nullptr));
        comboBox_2->setItemText(69, QCoreApplication::translate("MainWindow", "1945", nullptr));
        comboBox_2->setItemText(70, QCoreApplication::translate("MainWindow", "1944", nullptr));
        comboBox_2->setItemText(71, QCoreApplication::translate("MainWindow", "1943", nullptr));
        comboBox_2->setItemText(72, QCoreApplication::translate("MainWindow", "1942", nullptr));
        comboBox_2->setItemText(73, QCoreApplication::translate("MainWindow", "1941", nullptr));
        comboBox_2->setItemText(74, QCoreApplication::translate("MainWindow", "1940", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
