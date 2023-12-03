#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/jaysh/Downloads/Map.jpg");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString shape = ui->comboBox->currentText();
    QString year = ui->comboBox->currentText();
    QString algo = ui->comboBox->currentText();

    return;
}

