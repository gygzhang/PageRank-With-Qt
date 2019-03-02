#ifndef TEXT_H
#define TEXT_H

#include<QGraphicsItem>
class GraphWidget;


class Text:public QGraphicsItem
{
public:
    Text(GraphWidget *graphWidget,int times,double *PR);
protected:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    GraphWidget *graph;
    QPointF newPos;
    int  times;
    double *PR;
};

#endif // TEXT_H
