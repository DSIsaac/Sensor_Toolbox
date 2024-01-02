#ifndef COMMUNICATION_WIDGET_H
#define COMMUNICATION_WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QHBoxLayout>
class Communication_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Communication_Widget(QWidget *parent = nullptr);
    ~Communication_Widget();
    void Button_Init();
public:

private:

private:
    QGroupBox *Communication_Select_Button_Group = nullptr;
    QHBoxLayout *Communication_Select_Button_Hbox = nullptr;
    QRadioButton *Communication_Select_Button_UART = nullptr;
    QRadioButton *Communication_Select_Button_BLE = nullptr;
    QRadioButton *Communication_Select_Button_TCP = nullptr;

    const quint16 top_margin = 20;
    const quint16 side_margin = 30;
    const QSize Radio_Button_Group_Size = QSize(420, 80);
    const QSize Radio_Button_Size = QSize(60, 50);
    const QSize widget_size = QSize(420, 600);
signals:

};

#endif // COMMUNICATION_WIDGET_H
