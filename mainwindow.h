#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStyle>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton *Data_Page_Button, *Sensor_Set_Page_Button, *Algorithm_Set_Page_Button;
    QString *Button_Style;
    const quint16 top_margin = 360 - 100;
    const quint16 side_margin = 120;
    const QSize widget_size = QSize(1080, 720);

private:
    void Button_Style_Init();
    void Data_Page_Button_Init();
    void Sensor_Set_Page_Button_Init();
    void Algorithm_Set_Page_Button_Init();

private slots:
//    void Data_Page_Button_Pressed_Slot();
};
#endif // MAINWINDOW_H
