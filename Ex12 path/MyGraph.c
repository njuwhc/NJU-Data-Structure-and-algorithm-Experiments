#include "MyGraph.h"

//用数组初始化有向图，邻接矩阵建立有向有权重图
void CreateGraph(MyGraph* G, DataType (*MyMatrix)[MAXVER])
{
	int i, j;
	G->_vernum = MAXVER;
	for (i = 0; i < MAXVER; i++)
		for (j = 0; j < MAXVER; j++)
			G->_matrix[i][j] = MyMatrix[i][j];
}

//Dijkstra算法求单源最短路径,v作为起始点,D作为输出,单源到各个点的最短路径
//这个起始点也可以写进struct中
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

//Floyd-Warshall算法求所有节点对最短路径,D是输出
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

//无需改动
void PrintDijkstra(MyGraph* G, int v, ShortPathTable* D)
{
	printf("带权重有向图邻接矩阵为：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("∞ ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("以V%d为起点，每个顶点路径长度：\n", v);
	for (int i = 0; i < MAXVER; ++i)
	{
		printf("V%d：%d \n", i, D[i]._value);
	}
}

//无需改动
void PrintFloydWarshall(MyGraph* G, DistanceMatrix(*D)[MAXVER])
{
	printf("初始带权重有向图邻接矩阵为：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("∞ ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("结果带权重有向图邻接矩阵为：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((D[i][j] >= 1000) || (D[i][j] <= (-1000)))
			{
				printf("∞ ");
			}
			else
			{
				printf("%d ", D[i][j]);
			}
		}
		printf("\n");
	}
}