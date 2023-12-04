#include "mainwindow.h"
//#include "shapegen.h"
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
        if (dataContainer[i][8].compare(year) == 0 && dataContainer[i][3].compare(shape)) {
            std::string latitude = dataContainer[i][6];//.substr(1,dataContainer[i][6].size()-2);
            std::string longitude = dataContainer[i][7];//.substr(1,dataContainer[i][7].size()-2);
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
    ui->customPlot->setBackground(QBrush(Qt::transparent));
    ui->customPlot->axisRect()->setBackground(QBrush(Qt::transparent));
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
    //ShapeGenerator outline;
    //outline.ConvexHull(filteredData);
    ui->customPlot->addGraph(ui->customPlot->xAxis,ui->customPlot->yAxis);
    QVector<double> x(filteredData.size());
    QVector<double> y(filteredData.size());
    for(int i=0;i<filteredData.size();i++){
        x[i] = filteredData[i].second;
        y[i] = filteredData[i].first;
    }

    ui->customPlot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->customPlot->graph(0)->setName("Outline of ");
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->xAxis->setRange(-125,-70);
    ui->customPlot->yAxis->setRange(28,50);
    ui->customPlot->replot();

    QMessageBox msg;
    msg.setText(QString::fromStdString(std::to_string(filteredData[0].first)));
    msg.exec();
    return;
}

