#include "mainwindow.h"
//#include "shapegen.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

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
        if (dataContainer[i][3].compare(shape) == 0 || shape == "-Select-") {
            if (dataContainer[i][8].compare(year) == 0) {
                std::string latitude = dataContainer[i][6];//.substr(1,dataContainer[i][6].size()-2);
                std::string longitude = dataContainer[i][7];//.substr(1,dataContainer[i][7].size()-2);
                filteredData.push_back({::atof(latitude.c_str()), ::atof(longitude.c_str())});
            }
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
    bool alphaShape = ui->radioButton_2->isChecked();
    bool convexHull = ui->radioButton->isChecked();

    if (year == "-Select-") {
        QMessageBox msg;
        msg.setText("Please select a year.");
        msg.exec();
        return;
    }

    if (filteredData.size() == 0) {
        QMessageBox msg;
        msg.setText("There are no matches for this search. Please select a different one.");
        msg.exec();
        return;
    }

    for(int i = 0; i < filteredData.size(); i++){
        x[i] = filteredData[i].second;
        y[i] = filteredData[i].first;
    }

    ui->customPlot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->customPlot->graph(0)->setName("Outline of ");
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->xAxis->setRange(-123,-68);
    ui->customPlot->yAxis->setRange(27,46);

    if (alphaShape == true) {
        ui->customPlot->replot();
        // run alpha shape algorithm
    } else if (convexHull == true) {
        ui->customPlot->replot();
        // run convex hull algorithm
    } else {
        QMessageBox msg;
        msg.setText("Please select an algorithm.");
        msg.exec();
        return;
    }

    /*QMessageBox msg;
    msg.setText(QString::fromStdString(std::to_string(filteredData[0].first)));
    msg.exec();
<<<<<<< HEAD
    return; */
=======

    int x_val = -120;
    int y_val = 35;
    int x_val_1 = -120;
    int y_val_2 = 35;
    for(int i = 0; i < 100; i++){
        QCPItemLine *line = new QCPItemLine(ui->customPlot);
        line->setPen(QPen(Qt::red));
        line->start->setCoords(x_val, y_val);
        line->end->setCoords(x_val_1, y_val_2);
        x_val++;
        y_val++;
        x_val_1 += 2;
        y_val_2 += 2;

        ui->customPlot->replot();
        delay();

    }
    
    return;
>>>>>>> 7bb391c6a068b078116b83aac946d66198b65d84
}

