#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 100
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2
#define INFEASIBLE  -1

typedef int Status;
typedef int ElemType;

typedef struct MGraph {
	
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
	
}MGraph;

void CreateUDG(MGraph &G)
{
	int i, j;
	G.vexnum = 5;
	G.arcnum = 8;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = EMPTY;
		}
	}

	G.arcs[0][1] = G.arcs[1][0] = 1;
	G.arcs[0][2] = G.arcs[2][0] = 1;
	G.arcs[0][4] = G.arcs[4][0] = 1;
	G.arcs[1][4] = G.arcs[4][1] = 1;
	G.arcs[1][2] = G.arcs[2][1] = 1;
	G.arcs[3][2] = G.arcs[2][3] = 1;
	G.arcs[4][2] = G.arcs[2][4] = 1;
	G.arcs[4][3] = G.arcs[3][4] = 1;

	return;
}

void DFS(MGraph G, int v,int depth,string s)
{
	if (depth >= 8) {
		cout << s << endl;
	}

	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1) {
			G.arcs[v][i] = 0;
			G.arcs[i][v] = 0;

			DFS(G, i, depth + 1, s + char(i + 49));
			G.arcs[v][i] = 1;
			G.arcs[i][v] = 1;
		}
		
	}
	return;
}


int main()
{
	MGraph G;
	string s="1";
	CreateUDG(G);
	DFS(G, 0, 0, s);

	return 0;
}
