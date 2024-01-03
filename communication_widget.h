#ifndef COMMUNICATION_WIDGET_H
#define COMMUNICATION_WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

class Communication_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Communication_Widget(QWidget *parent = nullptr);
    ~Communication_Widget();
    void Interface_Init();

public:

private:

private:
    QGroupBox *Communication_Select_Button_Group = nullptr;
    QHBoxLayout *Communication_Select_Button_Hbox = nullptr;
    QRadioButton *Communication_Select_Button_UART = nullptr;
    QRadioButton *Communication_Select_Button_BLE = nullptr;
    QRadioButton *Communication_Select_Button_TCP = nullptr;

    QGroupBox *UART_Config_Group = nullptr;
    QGridLayout *UART_Config_Group_Layout = nullptr;
    QLabel *UART_Config_Com_Port_Label = nullptr;
    QLabel *UART_Config_Baudrate_Label = nullptr;
    QComboBox *UART_Config_Com_Port_Select = nullptr;
    QLineEdit *UART_Config_Baudrate_Edit = nullptr;

    QGroupBox *Communication_Method_Group = nullptr;
    QGridLayout *Communication_Method_Group_Layout = nullptr;
    QLabel *Communication_Method_Tips_Label = nullptr;
    QRadioButton *Communication_Method_JSON_Format = nullptr;
    QRadioButton *Communication_Method_Frame_Format = nullptr;


    const QSize widget_size = QSize(420, 600);
    const quint16 top_margin = 20;
    const quint16 side_margin = 30;

    const QSize Radio_Button_Group_Size = QSize(420, 80);
    const QSize Radio_Button_Size = QSize(60, 50);
    const QSize UART_Config_Group_Size = QSize(420, 150);
    const QSize Communication_Method_Group_Size = QSize(420, 200);
    const QSize Bottom_Button_Group_Size = QSize(420, 600 - 200 - 150 - 80);


signals:

public slots:
    void Communication_Method();
};

#endif // COMMUNICATION_WIDGET_H
