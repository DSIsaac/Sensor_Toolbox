#include "communication_widget.h"
#include "widget_tools.h"
#include "QDebug"

Communication_Widget::Communication_Widget(QWidget *parent) : QWidget(parent)
{
    this->setBaseSize(widget_size);
    this->resize(widget_size);
//    this->setAttribute(Qt::WA_DeleteOnClose);
    Button_Init();
    this->hide();

}

void Communication_Widget::Button_Init()
{
    Communication_Select_Button_Group = new QGroupBox("通信方式", this);
    Communication_Select_Button_Group->resize(Radio_Button_Group_Size);
    Communication_Select_Button_Group->setStyleSheet(
                "QGroupBox{border-color:#0a0a0a; border-width:1px; border-style:solid; margin: 10px;}"
                "QGroupBox::title{bottom: 5px; subcontrol-position: center top;}");

    Communication_Select_Button_Hbox = new QHBoxLayout();

    Communication_Select_Button_UART = new QRadioButton("UART", this);
//    QRect rect = Widget_Tools::Widget_Arrange(side_margin, top_margin, widget_size, Radio_Button_Size, 3, 1, 0);
//    Communication_Select_Button_UART->setGeometry(rect);
    Communication_Select_Button_UART->setChecked(true);

    Communication_Select_Button_BLE = new QRadioButton("BLE", this);
    Communication_Select_Button_TCP = new QRadioButton("TCP", this);

    Communication_Select_Button_Hbox->addStretch(1);
    Communication_Select_Button_Hbox->addWidget(Communication_Select_Button_UART);
    Communication_Select_Button_Hbox->addStretch(2);
    Communication_Select_Button_Hbox->addWidget(Communication_Select_Button_BLE);
    Communication_Select_Button_Hbox->addStretch(2);
    Communication_Select_Button_Hbox->addWidget(Communication_Select_Button_TCP);
    Communication_Select_Button_Hbox->addStretch(1);
    Communication_Select_Button_Group->setLayout(Communication_Select_Button_Hbox);

}

Communication_Widget::~Communication_Widget()
{
    delete this;
}
