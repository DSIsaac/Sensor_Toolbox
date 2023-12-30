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

    QPushButton *Data_Page, *Sensor_Set_Page, *Algorithm_Set_Page;
    QString *Button_Style;
    const quint16 top_margin = 360 - 100;
    const quint16 side_margin = 120;

private:
    void Button_Style_Init();
    void Data_Page_Init();
    void Sensor_Set_Page_Init();
    void Algorithm_Set_Page_Init();
};
#endif // MAINWINDOW_H
