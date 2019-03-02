#include "pagerank_thread.h"
#include"graphwidget.h"

#include<QDebug>
#define N 8
pagerank_thread::pagerank_thread(GraphWidget *g)
{
    connect(this,SIGNAL(mysgl(double *)),g,SLOT(scaleNode(double *)));
}

void pagerank_thread::run(){
    QThread::sleep(18);
    create_website(&G);
    double d = 0.85;
    double R[N+1];
    for (int i = 0; i < N; i++) {
        *(R+i) = 1.0 / N;
    }
    R[8]=0.000;
    emit mysgl(R);
    QThread::sleep(2);
    int outlink[N] = { 0 };
    outlink[0] = 2;
    outlink[1] = 2;
    outlink[2] = 2;
    outlink[3] = 3;
    outlink[4] = 1;
    outlink[5] = 3;
    outlink[6] = 1;
    outlink[7] = 1;
    bool cal = 1;
        double cvg = 1e-111;
        while (cal) {
            double temp[N] = { 0 };
            double prev[N] = { 0 };
            double tcvg = 0;
            for (int i = 0; i < N+1; i++)
            {
                prev[i] = R[i];
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G.arcs[j][i].adj==1) {
                        double  aa= (double)R[j] / outlink[j];
                        temp[i] += aa;
                    }
                }
                R[i] = (1 - d) / N + d * temp[i];
            }

            for (int i = 0; i < N; i++) {
                tcvg = tcvg + (R[i] - prev[i]);
            }
            if(tcvg<0)
            R[8]= -tcvg;
            else R[8] = tcvg;
            emit mysgl(R);
            QThread::sleep(1);
        }
}



/*void pagerank_thread::pagerank_iter(){
    double d = 0.85;
    double R[N];
    for (int i = 0; i < N; i++) {
        *(R+i) = 1.0 / N;
    }
    int outlink[N] = { 0 };
    outlink[0] = 2;
    outlink[1] = 2;
    outlink[2] = 2;
    outlink[3] = 3;
    outlink[4] = 1;
    outlink[5] = 3;
    outlink[6] = 1;
    outlink[7] = 1;
    //outlink[0] = 2;
    bool cal = 1;
        double cvg = 1e-111;
        while (cal) {
            double temp[N] = { 0 };
            double prev[N] = { 0 };
            double tcvg = 0;
            for (int i = 0; i < N; i++)
            {
                prev[i] = R[i];
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G.arcs[j][i].adj==1) {
                        double  aa= (double)R[j] / outlink[j];
                        temp[i] += aa;
                    }
                }
                R[i] = (1 - d) / N + d * temp[i];
            }
            emit valueChanged(R);
            QThread::sleep(3000);
            for (int i = 0; i < N; i++) {
                tcvg = tcvg + (R[i] - prev[i]);
            }
            if (tcvg - cvg < 1e-36) break;
        }

}
*/

int pagerank_thread::LOC(MGraph G, double a) {
    /*for (int i = 0; i < G.vexnum; i++) {
        if (a == G.vexs[i]) return i;
    }*/
    return 0;
}

void pagerank_thread::create_website(MGraph *G){
    G->vexnum = 8;
    G->arcnum = 14;
    for (int i = 0; i < G->vexnum; i++) G->vexs[i] = i+1;
    for (int i = 0; i < G->vexnum; i++)
            for (int j = 0; j < G->vexnum; j++) {
                G->arcs[i][j].adj = INT_MAX;
                G->arcs[i][j].info = nullptr;
            }
    G->arcs[0][5].adj = 1;
    G->arcs[0][7].adj = 1;
    G->arcs[1][0].adj = 1;
    G->arcs[0][7].adj = 1;
    G->arcs[2][3].adj = 1;
    G->arcs[2][7].adj = 1;
    G->arcs[3][1].adj = 1;
    G->arcs[3][4].adj = 1;
    G->arcs[3][7].adj = 1;
    G->arcs[4][7].adj = 1;
    G->arcs[5][7].adj = 1;
    G->arcs[5][6].adj = 1;
    G->arcs[6][7].adj = 1;
    G->arcs[7][2].adj = 1;
}

