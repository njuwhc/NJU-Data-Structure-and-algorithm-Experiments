#include"Graph.h"
#include"Queue.h"
#include<stdlib.h>

/*
Function:  Creat an undirected graph
Args:
*G:    Pointer to a gragh
*ver:  An array of vertex value
*edge: An array of edges
Description: Construct a graph which is stored in the form of an adjacency list
*/
void creatGraph(Graph* G, VertexType ver[], VertexType edge[][2])
{
    G->vexnum = MAXVER;
    G->edgenum = MAXEDG;
    int i, j, k, v, e;
    VertexType s1, s2;
    ENode* p1, * q, * p2;
    for (i = 0; i < G->vexnum; i++) 
    {
        G->vertexs[i].val = ver[i];
        G->vertexs[i].first_edge = NULL;
    }
    for (k = 0; k < G->edgenum; k++)
    {
        s1 = edge[k][0];
        s2 = edge[k][1];
        p1 = (ENode*)malloc(sizeof(ENode));
        p2 = (ENode*)malloc(sizeof(ENode));
        for (i = 0; i < G->vexnum; i++)
        {
            if (G->vertexs[i].val == s1)
                v = i;
            if (G->vertexs[i].val == s2)
                e = i;
        }
        p1->v_id = e;
        p1->next_edge = NULL;
        if (G->vertexs[v].first_edge == NULL)
            G->vertexs[v].first_edge = p1;
        else
        {
            q = G->vertexs[v].first_edge;
            while (q->next_edge)
                q = q->next_edge;
            q->next_edge = p1;
        }

        p2->v_id = v;
        p2->next_edge = NULL;
        if (G->vertexs[e].first_edge == NULL)
            G->vertexs[e].first_edge = p2;
        else
        {
            q = G->vertexs[e].first_edge;
            while (q->next_edge)
                q = q->next_edge;
            q->next_edge = p2;
        }

    }



}

/*
Function:    Tranverse the graph Depth-first
Args:
*G:      Pointer to a gragh
*k:      Current index of vertex node
*_visit: An array helping judging whether the vertex is visited
*ret:    An array storing the vertexs in Depth-first consequence
Description: None
*/
//全连接图可以不用循环
void DFS(Graph* G, int k, int* _visit, char** ret)
{
    ENode* p;
    if (k < 0 || k >= G->vexnum)
        return;
    else
    {
        _visit[k] = 1;
        *(ret)[0] = G->vertexs[k].val;
        *(ret) = (*ret) + 1;
        //printf("%c ",G->vertexs[k].val);
        p = G->vertexs[k].first_edge;
        while (p != NULL) {
            if (_visit[p->v_id] == 0) {
                DFS(G, p->v_id, _visit, ret);
            }
            p = p->next_edge;
        }
    }

}

/*
Function:    Tranverse the graph Breadth-first
Args:
*G:      Pointer to a gragh
*_visit: An array helping judging whether the vertex is visited
*ret:    An array storing the vertexs in Breadth-first consequence
Description: None
*/
void BFS(Graph* G, int* _visit, char res[])
{
    PQueue q;
    ENode* p;
    q = CreatQueue(MAXVER);
    int w = 0, num = 0, v = 0;

    _visit[v] = 1;
    res[num++] = G->vertexs[v].val;
    Insert(q, v);
    while (Length(q) > 0)
    {
        Delete(q, &w);
        p = G->vertexs[w].first_edge;
        while (p != NULL)
        {
            if (_visit[p->v_id] == 0)
            {
                res[num++] = G->vertexs[p->v_id].val;
                _visit[p->v_id] = 1;
                Insert(q, p->v_id);
            }
            p = p->next_edge;
        }
    }
    DestroyQueue(q);
}

/*
Function:    Destroy a graph
Args:
*G:      Pointer to a gragh
Description: None
*/
void DestroyGraph(Graph*G)
{
    ENode* ptr, * temp;
    VNode* p;
    int i;
    for (i = 0; i < G->vexnum; i++)
    {
        ptr = G->vertexs[i].first_edge;
        while (ptr)
        {
            temp = ptr;
            ptr = ptr->next_edge;
            temp->next_edge = NULL;
            free(temp);
        }
    }
    for (i = 0; i < G->vexnum; i++)
    {
        G->vertexs[i].first_edge = NULL;
    }

}

/*
Function: Print adjacency list
Args:    G:  Pointer to a gragh
Description: None
*/
//完成print函数后，可以用来自查
void Print(Graph*G)
{
    int i, j;
    ENode* p;
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c: ", G->vertexs[i].val);
        p = G->vertexs[i].first_edge;
        while (p)
        {
            printf("%c ", G->vertexs[p->v_id]);
            p = p->next_edge;
        }
        printf("\n");
    }
}
