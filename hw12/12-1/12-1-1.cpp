#include<iostream>  
#include<malloc.h>  
using namespace std;

#define MAXSIZE 100 

int PRE[MAXSIZE];
int BEHIND[MAXSIZE];
int point = 0; 
bool is_DAG = true;
				  
int visited[MAXSIZE];
				  
typedef struct{
	char Vex[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vexNum; 
	int arcNum; 
}MGraph;

void dfs(MGraph *G, int i)
{
	visited[i] = -1;
	PRE[i] = ++point;
	for (int j = 1; j <= G->vexNum; j++){
		if (G->arcs[i][j] != 0){
			if (visited[j] == -1){
				is_DAG = false;
			}
			else if (visited[j] == 0)
				dfs(G, j);
		}
	}
	BEHIND[i] = ++point;
	visited[i] = 1;
}

void DFS(MGraph *G)
{
	int i;
	for (i = 1; i <= G->vexNum; i++){
		visited[i] = 0;
		PRE[i] = 0;
		BEHIND[i] = 0;
	} 
	for (i = 1; i <= G->vexNum; i++)
	{
		if (visited[i] == 0){
			dfs(G, i);

		}
	}
}
void createGraph(MGraph *G)
{

	cin >> G->vexNum;
	cin >> G->arcNum;
	int i, j;
	for (i = 1; i <= G->vexNum; i++) {
		for (j = 1; j <= G->vexNum; j++) {
			G->arcs[i][j] = 0;
		}
	}
	for (int k = 1; k <= G->arcNum; k++){
		cin >> i >> j;
		G->arcs[i][j] = 1;
	}
}
int main()
{

	int group;
	cin >> group;
	while (group) {
		MGraph *G;
		G = (MGraph*)malloc(sizeof(MGraph));
		createGraph(G);
		DFS(G);

		if (is_DAG)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		group--;
		is_DAG = true;
	}
	return 0;
}