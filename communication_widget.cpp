#include "communication_widget.h"
#include "widget_tools.h"
#include "QDebug"

Communication_Widget::Communication_Widget(QWidget *parent) : QWidget(parent)
{
    this->resize(widget_size);
    this->setWindowModality(Qt::ApplicationModal);
    Button_Init();
    this->show();
}

void Communication_Widget::Button_Init()
{
    QRect rect = Widget_Tools::Widget_Arrange(side_margin, top_margin, widget_size, Radio_Button_Size, 3, 1, 0);
    Communication_Select_Button_UART = new QRadioButton("UART", this);
    Communication_Select_Button_UART->setGeometry(rect);
//    qDebug() << Communication_Select_Button_UART->rect();
//    qDebug() << Widget_Tools::Widget_Arrange(side_margin, top_margin, widget_size, Radio_Button_Size, 3, 1, 0);

    rect = Widget_Tools::Widget_Arrange(side_margin, top_margin, widget_size, Radio_Button_Size, 3, 2, 0);
    Communication_Select_Button_BLE = new QRadioButton("BLE", this);
    Communication_Select_Button_BLE->setGeometry(rect);

    rect = Widget_Tools::Widget_Arrange(side_margin, top_margin, widget_size, Radio_Button_Size, 3, 3, 0);
    Communication_Select_Button_TCP = new QRadioButton("TCP", this);
    Communication_Select_Button_TCP->setGeometry(rect);

}

Communication_Widget::~Communication_Widget()
{
    delete this;

}
