#ifndef WIDGET_TOOLS_H
#define WIDGET_TOOLS_H

#include <QWidget>

class Widget_Tools : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Tools(QWidget *parent = nullptr);
    static QRect &&Widget_Arrange(const quint16 &side_margin, const quint16 &top_margin, const QSize &widget_size, const QSize &size, quint8 &n, quint8 &m, quint8 &dir);
    static QRect &&Widget_Arrange(const quint16 &side_margin, const quint16 &top_margin, const QSize &widget_size, const QSize &size, quint8 &&n, quint8 &&m, quint8 &&dir);
signals:

};

#endif // WIDGET_TOOLS_H
