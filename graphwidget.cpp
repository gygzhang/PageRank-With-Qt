/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "graphwidget.h"
#include "edge.h"
#include "node.h"
#include"text.h"

#include<QDebug>
#include<QThread>
#include <math.h>

#include <QKeyEvent>
#include <QRandomGenerator>

#define N 8
int c = 1;

GraphWidget::GraphWidget(QWidget *parent,QGraphicsScene *scene)
    : QGraphicsView(parent), timerId(0)
{
    scene = new QGraphicsScene(this);

    //this->t = t;
    //connect(this,SIGNAL(mysql(double*R)),this,SLOT(scaleNode(double*)));
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -100, 300, 300);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(2), qreal(2));
    setMinimumSize(1200, 800);
    setWindowTitle(tr("PageRank Iteration"));
    //scene->addEllipse(-300,-300,100,100);

    node1 = new Node(this,1);
    node2 = new Node(this,2);
    node3 = new Node(this,3);
    node4 = new Node(this,4);
    node5 = new Node(this,5);
    node6 = new Node(this,6);
    node7 = new Node(this,7);
    centerNode = new Node(this,8);
    double R[8];
    for(int i =0;i<8;i++) R[i] = 0;
    scene->addItem(new Text(this,0,R));

}

GraphWidget::~GraphWidget(){

}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}



void GraphWidget::scaleNode(double *R){
    static int a =1;
    scene()->addItem(new Text(this,a,R));
    a++;
    node1->setScale(qreal(qreal(20*R[0])));

    node2->setScale(qreal(qreal(20*R[1])));
    //QThread::sleep(1);

    node3->setScale(qreal(qreal(20*R[2])));
    //QThread::sleep(1);

    node4->setScale(qreal(qreal(20*R[3])));
    //QThread::sleep(1);

    node5->setScale(qreal(qreal(20*R[4])));
    //QThread::sleep(1);

    node6->setScale(qreal(qreal(20*R[5])));
    //QThread::sleep(1);

    node7->setScale(qreal(qreal(20*R[6])));
    //QThread::sleep(1);

    centerNode->setScale(qreal(20*R[7]));

    //QGraphicsItem * t = new Text(this,a);

    //qDebug()<<a<<"aaaa";



    //scene()->addEllipse(-300,-300,100,100);
    //scene()->addText("dieadai");
    //scene()->addItem()
//    qDebug()<<"R[0]:"<<R[0];
//    qDebug()<<"R[1]:"<<R[1];
//    qDebug()<<"R[2]:"<<R[2];
//    qDebug()<<"R[3]:"<<R[3];
//    qDebug()<<"R[4]:"<<R[4];
//    qDebug()<<"R[5]:"<<R[5];
//    qDebug()<<"R[6]:"<<R[6];
//    qDebug()<<"R[7]:"<<R[7];
    //qDebug()<<"R[8]:"<<R[0];

    /*qreal s1 = centerNode->pos().x();
    qreal s2 = centerNode->pos().y();
    qDebug()<<"8("<<s1<<","<<s2<<")";

    s1 = node1->pos().x();
    s2 = node1->pos().y();
    qDebug()<<"1("<<s1<<","<<s2<<")";

    s1 = node2->pos().x();
    s2 = node2->pos().y();
    qDebug()<<"node2("<<s1<<","<<s2<<")";

    s1 = node3->pos().x();
    s2 = node3->pos().y();
    qDebug()<<"node3("<<s1<<","<<s2<<")";

    s1 = node4->pos().x();
    s2 = node4->pos().y();
    qDebug()<<"node4("<<s1<<","<<s2<<")";

    s1 = node5->pos().x();
    s2 = node5->pos().y();
    qDebug()<<"node5("<<s1<<","<<s2<<")";

    s1 = node6->pos().x();
    s2 = node6->pos().y();
    qDebug()<<"node6("<<s1<<","<<s2<<")";

    s1 = node7->pos().x();
    s2 = node7->pos().y();
    qDebug()<<"node5("<<s1<<","<<s2<<")";*/

}


void GraphWidget::addNode(int count){
    switch(count){
    case 1:scene()->addItem(node1);
        node1->setPos(-1,0);
        break;
    case 2:scene()->addItem(node2);
        node2->setPos(8,8);
        break;
    case 3:scene()->addItem(node3);
        node3->setPos(8,-36);
        break;
    case 4:scene()->addItem(node4);
        node4->setPos(8,16);
        break;
    case 5:scene()->addItem(node5);
        node2->setPos(55,47);
        break;
    case 6:scene()->addItem(node6);
        node2->setPos(7,-24);
        break;
    case 7:scene()->addItem(node7);
        node2->setPos(-8,-16);
        break;
    case 8:scene()->addItem(centerNode);
        centerNode->setPos(-24,-16);
        break;
    case 9:scene()->addItem(new Edge(node1, node6));
        break;
    case 10:scene()->addItem(new Edge(node2, node1));
        break;
    case 11:scene()->addItem(new Edge(node1, centerNode));
        break;
    case 12:scene()->addItem(new Edge(node2, centerNode));
        break;
    case 13:scene()->addItem(new Edge(node3, centerNode));
        break;
    case 14:scene()->addItem(new Edge(node4, centerNode));
        break;
    case 15:scene()->addItem(new Edge(node5, centerNode));
        break;
    case 16:scene()->addItem(new Edge(node6, centerNode));
        break;
    case 17:scene()->addItem(new Edge(node7, centerNode));
        break;
    case 18:scene()->addItem(new Edge(node3, node4));
        break;
    case 19:scene()->addItem(new Edge(node4, node2));
        break;
    case 20:scene()->addItem(new Edge(node4, node5));
        break;
    case 21:scene()->addItem(new Edge(node6, node5));
        break;
    case 22:scene()->addItem(new Edge(node6, node7));
        break;
    case 23:scene()->addItem(new Edge(centerNode,node3));
        break;


    }
}
void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        addNode(c);
        c++;
        break;
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        shuffle();
        break;
    //default:
       // QGraphicsView::keyPressEvent(event);
    }
}
//! [3]

//! [4]
void GraphWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QList<Node *> nodes;
    foreach (QGraphicsItem *item, scene()->items()) {
        if (Node *node = qgraphicsitem_cast<Node *>(item))
            nodes << node;
    }

    foreach (Node *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (Node *node, nodes) {
        if (node->advancePosition())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}
//! [4]

#if QT_CONFIG(wheelevent)
//! [5]
void GraphWidget::wheelEvent(QWheelEvent *event)
{
    //scaleView(pow((double)2, -event->delta() / 240.0));
}
//! [5]
#endif

//! [6]
void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, QColor("#feeeed"));
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left()+0, sceneRect.top()-40,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr(" PageRank Iteration"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(20);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
   qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
//! [7]

void GraphWidget::shuffle()
{
    foreach (QGraphicsItem *item, scene()->items()) {
        if (qgraphicsitem_cast<Node *>(item))
            item->setPos(-150 + QRandomGenerator::global()->bounded(300), -150 + QRandomGenerator::global()->bounded(300));
    }
}

void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
    //*PR = 5;
    //PR = new double[8];
    //*(PR+1)=5;
    //emit valueChanged(PR);
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
