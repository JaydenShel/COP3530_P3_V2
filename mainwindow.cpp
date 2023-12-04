#include "mainwindow.h"
#include "shapegen.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> ReadData(std::string filename) {
    std::vector<std::vector<std::string>> dataContainer;
    std::fstream fin;

    fin.open(filename);

    std::string temp;

    while (fin >> temp) {
        std::string line, val;
        while (getline(fin, line)) {
            std::vector<std::string> row;
            std::stringstream s(line);
            while (std::getline(s, val, ',')) {
                row.push_back(val);
            }
            dataContainer.push_back(row);
        }
    }

    return dataContainer;
}

std::vector<std::pair<float, float>> FilterData(std::string shape, std::string year, std::vector<std::vector<std::string>> &dataContainer) {

    std::vector<std::pair<float, float>> filteredData;
    std::string q_year = "\"" + year + "\"";
    std::string q_shape = "\"" + shape + "\"";

    for (int i = 0; i < dataContainer.size(); i++) {
        if (dataContainer[i][8].compare(q_year) == 0 && dataContainer[i][3].compare(q_shape)) {
            std::string latitude = dataContainer[i][6].substr(1,dataContainer[i][6].size()-2);
            std::string longitude = dataContainer[i][7].substr(1,dataContainer[i][7].size()-2);
            filteredData.push_back({::atof(latitude.c_str()), ::atof(longitude.c_str())});
        }
    }


    return filteredData;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("map_image.png");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<std::vector<std::string>> dataContainer = ReadData("ufo_sightings.csv");
    std::string shape = ui->comboBox->currentText().toStdString();
    std::string year = ui->comboBox_2->currentText().toStdString();
    std::vector<std::pair<float, float>> filteredData = FilterData(shape, year, dataContainer);
    ShapeGenerator outline;
    outline.ConvexHull(filteredData);


    QMessageBox msg;
    msg.setText(QString::fromStdString("fail"));
    msg.exec();
    return;
}

