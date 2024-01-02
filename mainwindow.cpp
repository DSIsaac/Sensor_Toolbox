#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>
#include "communication_widget.h"
#include "widget_tools.h"
#include "QRadioButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(QSize(1080, 720));
    Button_Style_Init();
    Data_Page_Button_Init();
    Sensor_Set_Page_Button_Init();
    Algorithm_Set_Page_Button_Init();
    Communication_Set_Widget = new Communication_Widget();
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

void MainWindow::Data_Page_Button_Init()
{
    QIcon icon(":/mainwindow/res/icon/data.svg");
    Data_Page_Button = new QPushButton(icon, "", this);
    Data_Page_Button->setFixedSize(QSize(200, 200));
    Data_Page_Button->setStyleSheet(*Button_Style);
    Data_Page_Button->setGeometry(side_margin, 360 - 100, top_margin, 200);
    Data_Page_Button->setToolTip("数据显示");

    connect(Data_Page_Button, &QPushButton::released, this, [this](){
//        Communication_Widget *widget = new Communication_Widget();
        this->Communication_Set_Widget->setWindowModality(Qt::ApplicationModal);
        this->Communication_Set_Widget->show();

    });
}

void MainWindow::Sensor_Set_Page_Button_Init()
{
    QIcon icon(":/mainwindow/res/icon/setting.svg");
    Sensor_Set_Page_Button = new QPushButton(icon, "", this);
    Sensor_Set_Page_Button->setFixedSize(QSize(200, 200));
    Sensor_Set_Page_Button->setStyleSheet(*Button_Style);
    Sensor_Set_Page_Button->setGeometry(side_margin + (1080 - 2 * side_margin - 600) / 2 + Sensor_Set_Page_Button->width(), top_margin, 200, 200);
    Sensor_Set_Page_Button->setToolTip("传感器设置");

}

void MainWindow::Algorithm_Set_Page_Button_Init()
{
    Algorithm_Set_Page_Button = new QPushButton(QString(""), this);
    Algorithm_Set_Page_Button->setFixedSize(QSize(200, 200));
    Algorithm_Set_Page_Button->setStyleSheet(*Button_Style);
    Algorithm_Set_Page_Button->setGeometry(side_margin + (1080 - 2 * side_margin - 600) + Algorithm_Set_Page_Button->width() * 2, top_margin, 200, 200);
    Algorithm_Set_Page_Button->setToolTip("算法设置");
}
