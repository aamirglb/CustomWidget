#include "customwidget.h"
#include <QPainter>
#include <QMouseEvent>

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
}

void CustomWidget::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    QRect r1 = rect().adjusted(10, 10, -10, -10);
    painter.setPen(QColor("#33B5E5"));
    painter.drawRect(r1);

    QRect r2(QPoint(0, 0), QSize(20, 20));
    if(m_lastPos.isNull()) {
        r2.moveCenter(r1.center());
    } else {
        r2.moveCenter(m_lastPos);
    }
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor("#FFBB33")));
    painter.drawRect(r2);
//    painter.fillRect(r2, QColor("#FFBB33"));
}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
    update();
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
    update();
}

CustomWidget::~CustomWidget()
{
}

