#include <stdio.h>
#include <stdlib.h>

#define MAXVUE 9
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;
typedef int Pathmatirx[MAXVUE];
typedef int ShortPathTable[MAXVUE];

struct MGraph{
    VertexType vexs[MAXVUE];
    EdgeType arc[MAXVUE][MAXVUE];
    int numVertexes,numEdges;
};

void ShortestPath_Dijkstra(struct MGraph G,int v0,Pathmatirx *P,ShortPathTable *D){
    int v,w,k,min;
    int final[MAXVUE];
    for(v=0;v<G.numVertexes;v++){
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;
    }
    (*D)[v0] = 0;
    final[v0] = 1;
    for(v=1;v<G.numVertexes;v++){
        min = INFINITY;
        for(w=0;w<G.numVertexes;w++){
            if(!final[w] && (*D)[w]<min){
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1;
        for(w=0;w<G.numVertexes;w++){
            if(!final[w] && (min + G.arc[k][w] < (*D)[w])){
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
    printf("finish");
}
void CreateMGraph(struct MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
//    printf("111\n");
    for(i = 0;i < G->numVertexes;i++){
        scanf("%s",&G->vexs[i]);
    }
    for(i=0;i < sizeof(&G->vexs);i++){
        printf("vex %s\n",&G->vexs[i]);
    }
    for(i = 0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][j] = INFINITY;
    for(k=0;k<G->numEdges;k++){
        printf("输入边（vi,vj）上的下标i，下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        G->arc[i][j] =w;
        G->arc[j][i] = G->arc[i][j];
    }
}

