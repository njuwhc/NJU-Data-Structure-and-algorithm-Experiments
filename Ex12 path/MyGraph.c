#include "MyGraph.h"

//�������ʼ������ͼ���ڽӾ�����������Ȩ��ͼ
void CreateGraph(MyGraph* G, DataType (*MyMatrix)[MAXVER])
{
	int i, j;
	G->_vernum = MAXVER;
	for (i = 0; i < MAXVER; i++)
		for (j = 0; j < MAXVER; j++)
			G->_matrix[i][j] = MyMatrix[i][j];
}

//Dijkstra�㷨��Դ���·��,v��Ϊ��ʼ��,D��Ϊ���,��Դ������������·��
//�����ʼ��Ҳ����д��struct��
void Dijkstra(MyGraph* G,int v,ShortPathTable* D) 
{
	int i, u, w;
	for (i = 0; i < MAXVER; i++)
	{
		D[i]._value = G->_matrix[v][i];
		D[i]._visit = 0;
	}
	D[v]._value = 0; D[v]._visit = 1;

	for (int j = 1; j < MAXVER; j++)
	{
		int min = INT_MAX;
		for (w = 0; w < MAXVER; w++)
			if (!D[w]._visit)
			if(D[w]._value < min)
			{
				i = w;
				min = D[w]._value;
			}
		D[i]._visit = 1;
		for (u = 0; u < MAXVER; u++)
			if (!D[u]._visit && (min + G->_matrix[i][u] < D[u]._value) && G->_matrix[i][u]!=INT_MAX)
			{
				D[u]._value = min + G->_matrix[i][u];
			}
	}
}

//Floyd-Warshall�㷨�����нڵ�����·��,D�����
void FloydWarshall(MyGraph* G, DistanceMatrix(*D)[MAXVER])
{
	int u, v, w;
	for (v = 0; v < G->_vernum; v++)
		for (w = 0; w < G->_vernum; w++) {
			D[v][w] = G->_matrix[v][w];
		}


	for (u = 0; u < G->_vernum; u++)
		for (v = 0; v < G->_vernum; v++)
			for (w = 0; w < G->_vernum; w++)
				if (D[v][u] + D[u][w] < D[v][w] && (D[v][u] + D[u][w])>0)
					D[v][w] = D[v][u] + D[u][w];
	for (w = 0; w < G->_vernum; w++)
		D[w][w] = INT_MAX;
}

//����Ķ�
void PrintDijkstra(MyGraph* G, int v, ShortPathTable* D)
{
	printf("��Ȩ������ͼ�ڽӾ���Ϊ��\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("�� ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("��V%dΪ��㣬ÿ������·�����ȣ�\n", v);
	for (int i = 0; i < MAXVER; ++i)
	{
		printf("V%d��%d \n", i, D[i]._value);
	}
}

//����Ķ�
void PrintFloydWarshall(MyGraph* G, DistanceMatrix(*D)[MAXVER])
{
	printf("��ʼ��Ȩ������ͼ�ڽӾ���Ϊ��\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("�� ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("�����Ȩ������ͼ�ڽӾ���Ϊ��\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((D[i][j] >= 1000) || (D[i][j] <= (-1000)))
			{
				printf("�� ");
			}
			else
			{
				printf("%d ", D[i][j]);
			}
		}
		printf("\n");
	}
}