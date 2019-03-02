#include "text.h"
#include <QStyleOption>
#include <QPainter>
#include <QGraphicsScene>
int count = 1;

Text::Text(GraphWidget *graphWidget,int times,double *PR)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    this->times = times;
    this->PR = PR;
    newPos.setX(0);
    newPos.setY(0);

}

QRectF Text::boundingRect() const
{
    qreal adjust = 0;
    return QRectF( -10 - adjust, -10 - adjust, 230 + adjust, 250 + adjust);
}

void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{


    //长时间按压
    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, QColor("#1d953f"));
    }
    painter->setBrush(gradient);
    //写字的颜色
    painter->setPen(QPen(Qt::black, 1));
    painter->drawRect(0,215,100,20);
    painter->drawText(0,230," Iteration "+QString::number(times));
    //painter->drawRect(120,57,50,20);
    painter->drawRect(120,0,100,20);
    painter->drawText(120,15," Node 1: "+QString::number(PR[0],'f',5));
    painter->drawRect(120,22,100,20);
    painter->drawText(120,22+15," Node 2: "+QString::number(PR[1],'f',5));
    painter->drawRect(120,44,100,20);
    painter->drawText(120,15+44," Node 3: "+QString::number(PR[2],'f',5));
    painter->drawRect(120,66,100,20);
    painter->drawText(120,15+66," Node 4: "+QString::number(PR[3],'f',5));
    painter->drawRect(120,90,100,20);
    painter->drawText(120,15+90," Node 5: "+QString::number(PR[4],'f',5));
    painter->drawRect(120,112,100,20);
    painter->drawText(120,15+112," Node 6: "+QString::number(PR[5],'f',5));
    painter->drawRect(120,134,100,20);
    painter->drawText(120,15+134," Node 7: "+QString::number(PR[6],'f',5));
    painter->drawRect(120,156,100,20);
    painter->drawText(120,15+156," Node 8: "+QString::number(PR[7],'f',5));
    painter->drawRect(120,178,100,20);
    painter->drawText(120,15+178," 误差: "+QString::number(PR[8],'f',5));



}

QPainterPath Text::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}
