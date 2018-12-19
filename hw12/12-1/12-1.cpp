/*
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define MAXSIZE 100
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2

typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	int num;
	int weight;
	LNode *next;
}VextexNode, *AdjList;

typedef struct MGraph {
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
	AdjList List[MAXSIZE];
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
		if (u == i+1) {
			return i;
		}
	return -1;
}

void CreatAdjList(MGraph &G, int v1, int v2)
{
	int i, j;
	i = LocateVex(G, v1);
	j = LocateVex(G, v2);

	AdjList p1;
	p1 = G.List[i];
	while (p1->next != NULL) {
		p1 = p1->next;
	}
	p1->next = new VextexNode();
	p1 = p1->next;
	p1->data = j;
	p1->num = j;
	p1->weight = G.arcs[i][j];
	p1->next = NULL;

	return;
}

void CreateDG(MGraph &G)
{
	int v1, v2;
	int i, j, k;

	InitMGraph(G);
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
	}
	return;
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

int StartFind(MGraph G, int v)
{
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1) {
			return i;
		}
	}
	return -1;
}

int ConFind(MGraph G, int v, int w)
{
	for (int i = w + 1; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1) {
			return i;
		}
	}
	return -1;
}

bool visited[100];
bool first = true;
ElemType Vex[MAXSIZE];

Status DFS(MGraph G, int v)
{
	int w;
	visited[v] = true;
	int i;
	for (i = 0; i <G.vexnum; i++) {
		if (Vex[i] == v) {
			return 1;
		}
		if (Vex[i] == -1) {
			Vex[i] = v;
			break;
		}
	}
	for (w = StartFind(G, v); w >= 0; w = ConFind(G, v, w)) {
		if (!visited[w]) {
			visited[v] = true;
			if (DFS(G, w) == 1) {
				return 1;
			}

		}
	}
	return 0;
}

Status DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		visited[i] = false;
	}

	for (i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			if (DFS(G, i) == 1) {
				return 1;
			}
		}
	}
	return 0;
}



int main()
{
	MGraph G;
	CreateDG(G);
	int i;
	for (i = 0; i < G.vexnum; i++) {
		Vex[i] = -1;
	}
	PrintMar(G);
	cout<<DFSTraverse(G)<<endl;
	return 0;
}
*/