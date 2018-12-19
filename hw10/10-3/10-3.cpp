#include<iostream>
using namespace std;

#define MAXSIZE 100
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2

typedef int Status;
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

Status InitQueue(SqQueue &Q, int n)
{
	Q.base = (ElemType *)malloc((n + 1) * sizeof(ElemType));
	if (!Q.base)
		exit(OVERFLOWED);
	Q.front = Q.rear = 0;
	Q.QueueSize = n + 1;
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

Status DeQueue(SqQueue &Q, ElemType &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.QueueSize;
	return OK;
}

Status QueueEmpty(SqQueue &Q)
{
	if (Q.front == Q.rear)
		return ERROR;
	return OK;
}

typedef struct LNode {
	ElemType data;
	int num;
	int weight;
	LNode *next;
}VextexNode, *AdjList;

typedef struct MGraph {
	//char vexs[MAXSIZE];
	//int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
	AdjList List[MAXSIZE];
}MGraph;

Status InitMGraph(MGraph &G)
{
	int i;
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i < G.vexnum; i++) {
		G.List[i] = new VextexNode();
		G.List[i]->data = i;
		G.List[i]->next = NULL;
	}

	return 0;
}

void CreatAdjList(MGraph &G, ElemType i, ElemType j)
{
	AdjList p1;
	p1 = G.List[i];
	if (p1->next!=NULL) {
		while (p1->next != NULL) {
			if (j > p1->next->data) {
				AdjList p2=p1->next;
				p1->next = new VextexNode();
				p1 = p1->next;
				p1->data = j;
				p1->num = j;
				p1->next = p2;
				return;
			}
			p1 = p1->next;
		}
	}
	
	p1->next = new VextexNode();
	p1 = p1->next;
	p1->data = j;
	p1->num = j;
	p1->next = NULL;

	return;
}

void CreateUDG(MGraph &G)
{

	int i, j, k;

	InitMGraph(G);

	for (k = 0; k < G.arcnum; k++)
	{
		cin >> i >> j;
		CreatAdjList(G, i, j);
		CreatAdjList(G, j, i);
	}
}

bool visited[100];
bool first = true;

void DFS(MGraph G, int v)
{
	int w;
	visited[v] = true;
	if (!first) {
		cout << " ";
	}
	first = false;
	cout << v;
	AdjList p;
	p = G.List[v];
	while(p->next!=NULL){
		p = p->next;
		w = p->data;
		if (!visited[w]) {
			DFS(G, w);
		}
	}
	return;
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		visited[i] = false;
	}

	for (i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			cout << "{";
			DFS(G, i);
			cout << "}";
			first = true;
		}
	}
	return;
}

void BFSTraverse(MGraph G)
{
	int i, e, w;
	first = true;
	for (i = 0; i < G.vexnum; i++) {
		visited[i] = false;
	}
	SqQueue q;
	InitQueue(q);
	for (i = 0; i<G.vexnum; i++) {
		if (!visited[i]) {
			visited[i] = true;
			EnQueue(q, i);
			cout << "{";
			while (QueueEmpty(q) == OK) {
				int v = q.base[q.front];
				DeQueue(q, e);
				if (!first) {
					cout << " ";
				}
				first = false;
				cout << v;
				AdjList p = G.List[v];
				while(p->next){
					p = p->next;
					w = p->data;
					if (!visited[w]) {
						visited[w] = true;
						EnQueue(q, w);
					}
				}
			}
			//printf("\b");
			cout << "}";
			first = true;
		}
	}
	return;
}

int main()
{
	MGraph G;
	CreateUDG(G);
	DFSTraverse(G);
	cout << endl;
	BFSTraverse(G);
	cout << endl;
	return 0;
	
}
