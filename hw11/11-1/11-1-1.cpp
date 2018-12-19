#include<iostream>
#include<string>
using  namespace std;

#define MAXSIZE 10000

struct MGraph {
	int vexnum;  
	int edge;   
	int ** arc; 
};

void CreateUDG(MGraph & G) {
	cin >> G.vexnum >> G.edge;  
	G.arc = new int*[G.vexnum];
	int i = 0;
	for (i = 0; i < G.vexnum; i++) {
		G.arc[i] = new int[G.vexnum];
		for (int k = 0; k < G.vexnum; k++) {
			G.arc[i][k] = MAXSIZE;         
		}
	}

	for (i = 0; i < G.edge; i++) {
		int start;
		int end;
		cin >> start>> end;    
		int weight;
		cin >> weight;
		G.arc[start - 1][end - 1] = weight;
		G.arc[end - 1][start - 1] = weight;
	}
}

struct temp {
	int start; 
	int end;  
	int weight;  
};

int Prim(MGraph G, int begin) {

	temp *U = new temp[G.vexnum];

	int j,sum=0;

	for (j = 0; j < G.vexnum; j++) {
		if (j != begin - 1) {
			U[j].start = begin - 1;
			U[j].end = j;
			U[j].weight = G.arc[begin - 1][j];
		}
	}
	U[begin - 1].weight = -1;

	for (j = 1; j < G.vexnum; j++) {

		int min = MAXSIZE;
		int k;
		int index=-1;

		for (k = 0; k < G.vexnum; k++) {
			if (U[k].weight != -1) {
				if (U[k].weight < min) {
					min = U[k].weight;
					index = k;
				}
			}
		}

		if (index == -1) {
			return -1;
		}

		U[index].weight = -1;

		sum += G.arc[U[index].start][U[index].end];

		for (k = 0; k < G.vexnum; k++) {
			if (G.arc[U[index].end][k] <U[k].weight) {
				U[k].weight = G.arc[U[index].end][k];
				U[k].start = U[index].end;
				U[k].end = k;
			}
		}
	}
	return sum;
}

int main()
{
	MGraph G;
	CreateUDG(G);
	cout << Prim(G, 1) << endl;
	return 0;
}
