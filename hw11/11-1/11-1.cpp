/*
#include<iostream>
#include<iomanip>
using namespace std;

#define MAXSIZE 100
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2

typedef int Status;
typedef char ElemType;

typedef struct LNode {
	ElemType data;
	int num;
	int weight;
	LNode *next;
}VextexNode, *AdjList;

typedef struct MGraph {
	char vexs[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
	//AdjList List[MAXSIZE];
}MGraph;

Status InitMGraph(MGraph &G)
{
	int i, j;
	cin >> G.vexnum >> G.arcnum;

	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = EMPTY;
		}
	}
	return 0;
}

int LocateVex(MGraph G, int u)
{
	for (int i = 0; i < G.vexnum; i++)
		if (u-1 == i) {
			return i;
		}
	return -1;
}



void CreateUDN(MGraph &G)
{
	int v1, v2;
	int i, j, k;
	int w;

	InitMGraph(G);
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G,v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
}

void PrintMar(MGraph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			cout << setw(4) << G.arcs[i][j];
		}
		cout << endl;
	}
	return;
}

struct Assis_array {
	int start; 
	int end;  
	int weight;  
};


void Prim(MGraph g, int begin) {

	
	Assis_array *close_edge = new Assis_array[g.vexnum];

	int j,sum=0;

	for (j = 0; j < g.vexnum; j++) {
		if (j != begin - 1) {
			close_edge[j].start = begin - 1;
			close_edge[j].end = j;
			close_edge[j].weight = g.arcs[begin - 1][j];
		}
	}
	close_edge[begin - 1].weight = -1;
	for (j = 1; j < g.vexnum; j++) {

		int min = INT_MAX;
		int k;
		int index=0;
		for (k = 0; k < g.vexnum; k++) {
			if (close_edge[k].weight != -1) {
				if (close_edge[k].weight < min&&close_edge[k].weight != 0) {
					min = close_edge[k].weight;
					index = k;
				}
			}
		}
		close_edge[index].weight = -1;
	
		sum += g.arcs[close_edge[index].start][close_edge[index].end];
		cout << sum<<endl;

		
		for (k = 0; k < g.vexnum; k++) {
			if (g.arcs[close_edge[index].end][k] <close_edge[k].weight) {
				close_edge[k].weight = g.arcs[close_edge[index].end][k];
				close_edge[k].start = close_edge[index].end;
				close_edge[k].end = k;
			}
		}
	}
}

int main()
{
	MGraph G;

	CreateUDN(G);
	PrintMar(G);
	Prim(G, 1);
	return 0;
}
*/