#include "startwindow.h"
#include "ui_startwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.cpp"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::startMain() {
    bool start = ui->pushButton;

    if (start) {
        hide();
    }
}
