/*
#include<iostream>
using namespace std;


#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2
#define INFEASIBLE  -1
#define MAXVEX 10010
#define MAXARC 500010
#define INF 2147483647

typedef int Status;
typedef int ElemType;


typedef struct MGraph {
	int vexnum, arcnum;
	int v1[MAXVEX];
	int v2[MAXARC];
	int weight[MAXARC];
}MGraph;

int nex[MAXARC];
int army[MAXARC * 5], d[MAXVEX + 1];

void spfa(int startP, MGraph G)
{
	int head = 0,tail = 1;
	bool can[MAXVEX + 1];
	for (int i = 1; i <= G.arcnum; i++) {
		d[i] = INF;
		can[i] = false;
	}
	d[startP] = 0;
	army[tail] = startP;
	can[startP] = true;
	while (head <= tail) {
		head++;
		int p = army[head];
		int k = G.v1[p];
		while (k != 0) {
			int q = G.v2[k];
			if (d[q]>d[p] + G.weight[k]) {
				d[q] = d[p] + G.weight[k];
				if (can[q] == false) {
					can[q] = true;
					tail++;
					army[tail] = q;
				}
			}
			k = nex[k];
		}
		can[p] = false;
	}
}

int main()
{

	MGraph G;
	int startP, endP;
	int i;
	cin >> G.vexnum >> G.arcnum >> startP >> endP;
	int dep = 0;
	for (i = 1; i <= G.arcnum; i++) {
		cin >> G.v1[i] >> G.v2[i] >> G.weight[i];
		
		dep++;
		
		
		nex[dep] = h[G.v1[i]];
		h[G.v1[i]] = dep;
	}
	spfa(startP,G);
	cout << d[endP] << endl;
	return 0;
}

*/