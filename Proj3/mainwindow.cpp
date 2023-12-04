#include "mainwindow.h"
#include "shapegen.h"
//#include "hulllib.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Point
{
    float x, y;
    Point(float inX,float inY){
        x=inX;
        y=inY;
    }
};

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

std::vector<Point> FilterData(std::string shape, std::string year, std::vector<std::vector<std::string>> &dataContainer) {

    std::vector<Point> filteredData;
    std::string q_year = "\"" + year + "\"";
    std::string q_shape = "\"" + shape + "\"";

    for (int i = 0; i < dataContainer.size(); i++) {
        if (dataContainer[i][8].compare(year) == 0 && dataContainer[i][3].compare(shape)) {
            std::string latitude = dataContainer[i][6];//.substr(1,dataContainer[i][6].size()-2);
            std::string longitude = dataContainer[i][7];//.substr(1,dataContainer[i][7].size()-2);
            filteredData.push_back(Point(::atof(longitude.c_str()),::atof(latitude.c_str())));
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


// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
std::vector<Point> jarvisMarch(std::vector<Point> points, int n)
{
    // There must be at least 3 points
    if (n < 3) return points;

    // Initialize Result
    std::vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, q,
        // x) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
            // If i is more counterclockwise than current q, then
            // update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l);  // While we don't come to first point

    return hull;

}

void MainWindow::on_pushButton_clicked()
{
    ui->customPlot->clearGraphs();
    std::vector<std::vector<std::string>> dataContainer = ReadData("ufo_sightings.csv");
    std::string shape = ui->comboBox->currentText().toStdString();
    std::string year = ui->comboBox_2->currentText().toStdString();
    std::vector<Point> filteredData = FilterData(shape, year, dataContainer);
    //ShapeGenerator outline;
    //std::vector<std::pair<float,float>> conv = outline.QuickHull(filteredData);
    std::vector<Point> conv = jarvisMarch(filteredData, filteredData.size());
    ui->customPlot->addGraph(ui->customPlot->xAxis,ui->customPlot->yAxis);
    QVector<double> x(filteredData.size());
    QVector<double> y(filteredData.size());
    for(int i=0;i<filteredData.size();i++){
        x[i] = filteredData[i].y;
        y[i] = filteredData[i].x;
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
    msg.setText(QString::fromStdString(std::to_string(filteredData[0].x)));
    msg.exec();

    for(int i = 0; i < conv.size(); i++){
        QCPItemLine *line = new QCPItemLine(ui->customPlot);
        line->setPen(QPen(Qt::red));
        if(i == conv.size()-1){
            line->start->setCoords(conv[i].x, conv[i].y);
            line->end->setCoords(conv[0].x, conv[0].y);
        }else{
            line->start->setCoords(conv[i].x, conv[i].y);
            line->end->setCoords(conv[i+1].x, conv[i+1].y);
        }

        ui->customPlot->replot();
        delay();

    }
    
    return;
}

