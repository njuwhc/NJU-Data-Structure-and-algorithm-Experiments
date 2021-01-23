#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include"Graph.h"


//邻接表生成无向图
int main()
{
	int i;
	int visit[MAXVER] = { 0 };
	char v[MAXVER+1] = { 'A','B','C','D','E','F','G','H','I','J' };
	char e[MAXEDG][2] = { { 'A','B' },{ 'A','D' },{ 'A','E' },{ 'A','G' },\
	{'B','F'},{ 'C','F' },{ 'C','H' },{ 'C','J' },{ 'D','G' },\
	{'E','J'},{ 'G','H' },{ 'G','I' },{ 'I','J' } };
	char res[MAXVER+1] = { '0' };
	char *p = res;
	Graph Gra;
	printf("60!\n\n");
	creatGraph(&Gra, v, e);
	printf("Print  Adjacency table:\n");
	Print(&Gra);
	assert((Gra.vexnum == MAXVER) && (Gra.edgenum == MAXEDG) && (Gra.vertexs[0].val == 'A'));
	printf("\n70!\n\n");
	//Do not hardcode
	DFS(&Gra, 0, visit, &p);
	printf("DFS:\n");
	for (i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
		visit[i] = 0;
	}
	char temp1[MAXVER+1] = { 'A','B','F','C','H','G','D','I','J','E' };
	assert(strcmp(res, temp1) == 0);
	printf("\n\n80!\n\n");
	BFS(&Gra, visit, res);
	printf("BFS:\n");
	for (i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
	}
	char temp2[MAXVER + 1] = { 'A','B','D','E','G','F','J','H','I','C' };
	assert(strcmp(res, temp2) == 0);
	printf("\n\n90!\n");
	DestroyGraph(&Gra);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n\n");
	}
	system("PAUSE");
	return 0;
}
