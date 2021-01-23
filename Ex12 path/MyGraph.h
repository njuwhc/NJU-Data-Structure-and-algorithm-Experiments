#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>//add this header file to detect memory leaks

#define MAXVER 5
#define true 1
#define false 0

//权重类型，此处为int
typedef int DataType;
typedef DataType DistanceMatrix;
typedef struct
{
	_Bool _visit;
	DataType _value;
}MyVertex;
typedef MyVertex ShortPathTable;

typedef struct
{
	int _vernum;
	DataType _matrix[MAXVER][MAXVER];
}MyGraph;

void CreateGraph(MyGraph* G, DataType(*MyMatrix)[MAXVER]);

void Dijkstra(MyGraph* G,int v,ShortPathTable* D);

void FloydWarshall(MyGraph* G, DistanceMatrix(*D)[MAXVER]);

void PrintDijkstra(MyGraph* G,int v, ShortPathTable* D);

void PrintFloydWarshall(MyGraph* G, DistanceMatrix(*D)[MAXVER]);

