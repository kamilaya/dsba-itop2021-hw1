#include "logo.h"

#include <QPainter>

Logo::Logo(QWidget* parent)
    : QWidget(parent)
{

}

void Logo::paintEvent(QPaintEvent* /* event */)
{
    QPainter painter(this);


    painter.setBrush(QBrush(Qt::darkRed, Qt::SolidPattern));
    QRect r1(105, 80, 140, 70);
    painter.drawRect(r1);
    painter.setBrush(QBrush(Qt::GlobalColor::darkRed, Qt::BrushStyle::Dense3Pattern));
    painter.drawEllipse(QPoint(175,80), 70, 70);
}
