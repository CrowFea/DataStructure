#include<iostream>
using namespace std;

#define MAXSIZE		100
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2

typedef int  Status;
typedef int ElemType;

typedef struct QNode {
	ElemType *base;
	int front;
	int rear;
	int QueueSize;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
	Q.base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!Q.base)
		exit(OVERFLOWED);
	Q.front = Q.rear = 0;
	Q.QueueSize = MAXSIZE;
	return OK;
}

Status EnQueue(SqQueue &Q, ElemType elem)
{
	if ((Q.rear + 1) % Q.QueueSize == (Q.front)) {
		return ERROR;
	}
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) % Q.QueueSize;
	return OK;
}

Status DeQueue(SqQueue &Q)
{
	if (Q.front == Q.rear)
		return ERROR;
	
	Q.front = (Q.front + 1) % Q.QueueSize;
	return OK;
}

Status QueueEmpty(SqQueue &Q)
{
	if (Q.front == Q.rear)
		return OK;
	return FALSE;
}

typedef struct ArcNode {
	int adjvex;                  
	int weight;               
	struct ArcNode *next;
}ArcNode;                   

typedef struct Node {
	int date;               
	int info;               
	ArcNode *first;           
}Node, AdjList[MAXSIZE];        

typedef struct {
	AdjList vertices;
	int vexnum;            
	int arcnum;            
}MGraph;
int arr[MAXSIZE]; 

void CreateDG(MGraph *G)
{
	int i;
	cin >> G->vexnum >> G->arcnum;
	for (i = 1; i <= G->vexnum; i++){
		G->vertices[i].date = i;
		G->vertices[i].info = 0;
		G->vertices[i].first = NULL;
	}
	for (i = 0; i < G->arcnum; i++){
		int vi, vj, w;
		cin >> vi >> vj >> w;
		ArcNode *arc = new ArcNode;
		arc->adjvex = vj;
		arc->weight = w;
		arc->next = G->vertices[vi].first;
		G->vertices[vi].first = arc;
		G->vertices[vj].info++;
	}
	return;
}

bool topo(MGraph G)
{
	SqQueue Q;
	InitQueue(Q);
	int i,sum = 0, flag[MAXSIZE];                       
	for (i = 0; i < MAXSIZE; i++) {
		flag[i] = false;
	}
	for (i = 1; i <= G.vexnum; i++) {
		if (G.vertices[i].info == 0) {
			EnQueue(Q, i);
			flag[i] = 1;
		}
	}
	
	while(!QueueEmpty(Q)){
		int t = Q.base[Q.front];
		sum++; 
		DeQueue(Q);
		arr[sum] = t;
		ArcNode *pos = G.vertices[t].first;
		while (pos != NULL) {
			G.vertices[pos->adjvex].info--;
			pos = pos->next;
		}

		for (i = 1; i <= G.vexnum; i++) {
			if (G.vertices[i].info == 0 && !flag[i]) {
				EnQueue(Q, i);
				flag[i] = 1;
			}
		}
	}
	return sum == G.vexnum ? true : false;
}
void CriticalPath(MGraph G)
{
	int ve[MAXSIZE], vl[MAXSIZE];
	int i;
	for (i = 1; i <= G.vexnum; i++) {
		ve[i] = 0;
	}
	for (i = 1; i <= G.vexnum; i++){
		ArcNode *pos = G.vertices[arr[i]].first;
		while (pos != NULL) {
			int t = pos->adjvex;
			if (ve[arr[i]] + pos->weight > ve[t]) {
				ve[t] = ve[arr[i]] + pos->weight;
			}
			pos = pos->next;
		}
	}

	for (i = 1; i <= G.vexnum; i++) {
		vl[i] = ve[arr[G.vexnum]];
	}

	cout << ve[arr[G.vexnum]] << endl;

	for (i = G.vexnum; i >= 1; i--){
		ArcNode *pos = G.vertices[arr[i]].first;
		while (pos != NULL) {
			int t = pos->adjvex;
			if (vl[t] - pos->weight < vl[arr[i]])
				vl[arr[i]] = vl[t] - pos->weight;
			pos = pos->next;
		}
	}

	for (i = 1; i <= G.vexnum; i++){
		ArcNode *pos = G.vertices[i].first;
		while (pos != NULL) {
			int t = pos->adjvex;
			int e = ve[i];
			int l = vl[t] - pos->weight;
			if (e == l) {
				cout << i << "->" << t << endl;
			}
			pos = pos->next;
		}
	}

}

int main()
{
	MGraph G;
	CreateDG(&G);
	if (!topo(G)){
		cout << 0 << endl;
		return 0;
	}
	CriticalPath(G);
	return 0;
}