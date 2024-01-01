#include "widget_tools.h"
#include <QDebug>

Widget_Tools::Widget_Tools(QWidget *parent) : QWidget(parent)
{

}

QRect &&Widget_Tools::Widget_Arrange(const quint16 &side_margin, const quint16 &top_margin, const QSize &widget_size, const QSize &size, quint8 &n, quint8 &m, quint8 &dir)
{
    QRect point = {};
    quint16 gap_margin_x = (widget_size.width() - 2 * side_margin - n * size.width()) / (n - 1);
    quint16 gap_margin_y = (widget_size.height() - 2 * top_margin - n * size.height()) / (n - 1);
    point.setX(side_margin + (gap_margin_x + size.width()) * (m - 1) * (1 - dir));
    point.setY(top_margin + (gap_margin_y + size.height()) * (m - 1) * dir);
    point.setWidth(size.width());
    point.setHeight(size.height());
    return std::move(point);
}

QRect &&Widget_Tools::Widget_Arrange(const quint16 &side_margin, const quint16 &top_margin, const QSize &widget_size, const QSize &size, quint8 &&n, quint8 &&m, quint8 &&dir)
{
    QRect point = {};
    quint16 gap_margin_x = (widget_size.width() - 2 * side_margin - n * size.width()) / (n - 1);
    quint16 gap_margin_y = (widget_size.height() - 2 * top_margin - n * size.height()) / (n - 1);
    point.setX(side_margin + (gap_margin_x + size.width()) * (m - 1) * (1 - dir));
    point.setY(top_margin + (gap_margin_y + size.height()) * (m - 1) * dir);
    point.setWidth(size.width());
    point.setHeight(size.height());
//    qDebug() << point;
    return std::move(point);
}
