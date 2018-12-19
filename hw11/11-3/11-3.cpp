/*
#include<iostream>
#include<iomanip>
using namespace std;

#define DU 6
#define MAXSIZE 10000
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2
#define INFEASIBLE  -1

typedef int Status;
typedef int ElemType;

typedef struct MGraph {
	int **arcs;
	int vexnum, arcnum;

}MGraph;

void CreateUDG(MGraph &G)
{
	int v1, v2,i;
	cin >> G.vexnum >> G.arcnum;
	G.arcs = (int**)malloc((G.vexnum + 1) * sizeof(int*));
	for (i = 0; i <= G.vexnum; i++) {
		G.arcs[i] = (int*)malloc((G.vexnum +1) * sizeof(int));
	}
	for (i = 0; i<G.arcnum; i++){
		cin >> v1 >> v2;
		G.arcs[v1][v2] = 1;
		G.arcs[v2][v1] = 1;
	}

}

int BFS(MGraph G,int i)
{
	int q[MAXSIZE + 3], tail, v, j;
	bool *visit=new bool[G.vexnum];

	for (j = 0; j <= G.vexnum; j++) {
		visit[j] = false;
	}
	visit[i] = true;
	int front = -1,rear = -1;
	int count = 1;
	int level = 0;
	int last = i;
	q[++rear] = i;
	while (front<rear){
		v = q[++front];
		for (j = 1; j <= G.vexnum; j++) {
			if (!visit[j] && G.arcs[v][j] == 1) {
				q[++rear] = j;
				visit[j] = 1;
				count++;
				tail = j;
			}
		}
		if (v == last){
			level++;
			last = tail;
		}
		if (DU <= level){
			return count;
		}
	}
	free(visit);
	return count;
}

int main()
{
	MGraph G;
	int i,counter;
	CreateUDG(G);
	for (i = 1; i <= G.vexnum; i++){
		counter = BFS(G,i);
		cout << i<<": "<<setiosflags(ios::fixed) << setprecision(2) 
			<< ((float)counter / G.vexnum) * 100 <<"%"<< endl;
	}
	free(G.arcs);
	return 0;
}
*/