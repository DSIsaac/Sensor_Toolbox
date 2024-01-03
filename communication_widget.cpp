#include "communication_widget.h"
#include "widget_tools.h"
#include <QDebug>
#include <QSizePolicy>

Communication_Widget::Communication_Widget(QWidget *parent) : QWidget(parent)
{
    this->setBaseSize(widget_size);
    this->resize(widget_size);
//    this->setAttribute(Qt::WA_DeleteOnClose);
    Interface_Init();
    this->hide();

}

void Communication_Widget::Interface_Init()
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

    QSizePolicy Size_Policy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    UART_Config_Group = new QGroupBox("串口设置", this);
    UART_Config_Group->setGeometry(QRect(QPoint(0, Radio_Button_Group_Size.height()), UART_Config_Group_Size));
    UART_Config_Group->setStyleSheet(
                "QGroupBox{border-color:#0a0a0a; border-width:1px; border-style:solid; margin: 10px; margin-top: 5px;}"
                "QGroupBox::title{bottom: 5px; subcontrol-position: center top;}");
    UART_Config_Group_Layout = new QGridLayout();
    UART_Config_Com_Port_Label = new QLabel("端口号");
//    UART_Config_Com_Port_Label->setSizePolicy(Size_Policy);

    UART_Config_Baudrate_Label = new QLabel("波特率");
//    UART_Config_Baudrate_Label->setSizePolicy(Size_Policy);

    UART_Config_Com_Port_Select = new QComboBox();
//    UART_Config_Com_Port_Select->setSizePolicy(Size_Policy);

    UART_Config_Baudrate_Edit = new QLineEdit();
//    UART_Config_Baudrate_Edit->setSizePolicy(Size_Policy);

//    UART_Config_Group_Layout->setColumnStretch(0, 0);
    UART_Config_Group_Layout->addWidget(UART_Config_Com_Port_Label, 1, 1, 1, 1);
    UART_Config_Group_Layout->addWidget(UART_Config_Com_Port_Select, 1, 2, 1, 5);
//    UART_Config_Group_Layout->setColumnStretch(0, 1);
    UART_Config_Group_Layout->addWidget(UART_Config_Baudrate_Label, 2, 1, 1, 1);
    UART_Config_Group_Layout->addWidget(UART_Config_Baudrate_Edit, 2, 2, 1, 5);
    UART_Config_Group_Layout->setMargin(15);
    UART_Config_Group_Layout->setRowMinimumHeight(1, 40);
    UART_Config_Group_Layout->setRowMinimumHeight(2, 40);

    UART_Config_Group->setLayout(UART_Config_Group_Layout);

    Communication_Method_Group = new QGroupBox("通信协议", this);
    Communication_Method_Group->setGeometry(QRect(QPoint(0, Radio_Button_Group_Size.height() + UART_Config_Group->height()), Communication_Method_Group_Size));
    Communication_Method_Group->setStyleSheet(
                "QGroupBox{border-color:#0a0a0a; border-width:1px; border-style:solid; margin: 10px; margin-top: 5px;}"
                "QGroupBox::title{bottom: 5px; subcontrol-position: center top;}");
    Communication_Method_Group_Layout = new QGridLayout();
    Communication_Method_Tips_Label = new QLabel("");
    Communication_Method_Tips_Label->setSizePolicy(Size_Policy);
    Communication_Method_JSON_Format = new QRadioButton("JSON");
    Communication_Method_Frame_Format = new QRadioButton("协议帧");

    Communication_Method_Group_Layout->addWidget(Communication_Method_JSON_Format, 1, 3, 1, 1);
    Communication_Method_Group_Layout->addWidget(Communication_Method_Frame_Format, 1, 8, 1, 1);
    Communication_Method_Group_Layout->addWidget(Communication_Method_Tips_Label, 2, 1, 1, 10);
    Communication_Method_Group_Layout->setRowStretch(10, 1);
    Communication_Method_Group->setLayout(Communication_Method_Group_Layout);

    connect(Communication_Method_JSON_Format, &QRadioButton::toggled, this, Communication_Method);
}

void Communication_Widget::Communication_Method()
{
    qDebug() << "触发";
    if(Communication_Method_JSON_Format->isChecked()){
        Communication_Method_Tips_Label->setText("使用JSON格式进行通信");
    }
    else{
         Communication_Method_Tips_Label->setText("使用协议帧格式进行通信");
    }
}

Communication_Widget::~Communication_Widget()
{
    delete this;
}
