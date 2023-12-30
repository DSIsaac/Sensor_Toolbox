#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(QSize(1080, 720));
    Button_Style_Init();
    Data_Page_Init();
    Sensor_Set_Page_Init();
    Algorithm_Set_Page_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Button_Style_Init()
{
//    Button_Style = new QStyle();
    Button_Style = new QString("QPushButton{background-color : transparent; border-width : 0px; border-radius : 20px; icon-size: 200px}"
                               "QPushButton:hover{background-color : #dcdcdc; border-width : 1px; border-color : #000000; border-radius : 20px}"
                               "QPushButton:pressed{background-color : #78ddff; border-width : 1px; border-radius : 20px}"
                               );
     qDebug() << *Button_Style;
}

void MainWindow::Data_Page_Init()
{
    QIcon icon(":/mainwindow/res/icon/data.svg");
    Data_Page = new QPushButton(icon, "", this);
    Data_Page->setFixedSize(QSize(200, 200));
    Data_Page->setStyleSheet(*Button_Style);
    Data_Page->setGeometry(side_margin, 360 - 100, top_margin, 200);
    Data_Page->setToolTip("数据显示");
}

void MainWindow::Sensor_Set_Page_Init()
{
    QIcon icon(":/mainwindow/res/icon/setting.svg");
    Sensor_Set_Page = new QPushButton(icon, "", this);
    Sensor_Set_Page->setFixedSize(QSize(200, 200));
    Sensor_Set_Page->setStyleSheet(*Button_Style);
    Sensor_Set_Page->setGeometry(side_margin + (1080 - 2 * side_margin - 600) / 2 + Sensor_Set_Page->width(), top_margin, 200, 200);
    Sensor_Set_Page->setToolTip("传感器设置");

}

void MainWindow::Algorithm_Set_Page_Init()
{
    Algorithm_Set_Page = new QPushButton(QString(""), this);
    Algorithm_Set_Page->setFixedSize(QSize(200, 200));
    Algorithm_Set_Page->setStyleSheet(*Button_Style);
    Algorithm_Set_Page->setGeometry(side_margin + (1080 - 2 * side_margin - 600) + Algorithm_Set_Page->width() * 2, top_margin, 200, 200);
    Algorithm_Set_Page->setToolTip("算法设置");
}
