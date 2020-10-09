#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.c"

void CreateMGraph(struct MGraph *G);

void ShortestPath_Dijkstra(struct MGraph G,int v0,Pathmatirx *P,ShortPathTable *D);
int main()
{
    struct MGraph mgr;
    struct MGraph *G;
    G = &mgr;
    printf("Hello world!\n");
    CreateMGraph(G);
    printf("param finish!\n");
    Pathmatirx path[9];
    Pathmatirx *p;
    p = &path;
    ShortPathTable tb[9];
    ShortPathTable *d;
    d = &tb;
    ShortestPath_Dijkstra(mgr,0,p,d);
    return 0;
}
