#ifndef PAGERANK_THREAD_H
#define PAGERANK_THREAD_H
#include<QThread>
#include"graphwidget.h"

#define INT_MAX _CRT_INT_MAX
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN }GraphKind;

typedef void* InfoType;
typedef double VertexTpye;
typedef int  VRType;
typedef struct ArcCell {
    VRType adj;
    InfoType info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexTpye vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind;
}MGraph;

class GraphWidget;

class pagerank_thread:public QThread
{
    Q_OBJECT
public:
    double *PR;
    pagerank_thread(GraphWidget *g);
    void create_website(MGraph *G);
    int LOC(MGraph G, double a);

private:
    MGraph G;

    GraphWidget GW;
    void run();

signals:
    void valueChanged(double *);
    void mysgl(double *r);

public slots:
    //void scaleNode(double *r);

};

#endif // PAGERANK_THREAD_H
