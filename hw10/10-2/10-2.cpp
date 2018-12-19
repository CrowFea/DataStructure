#include<iostream>
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
	char vexs[MAXSIZE];
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

void CreateUDG(MGraph &G)
{
	int v1, v2;
	int i, j, k;

	InitMGraph(G);

	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = v1;
		j = v2;
		G.arcs[i][j] = G.arcs[j][i] = 1;
	}
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

void DFS(MGraph G, int v)
{
	int w;
	visited[v] = true;
	if (!first) {
		cout << " ";
	}
	first = false;
	cout << v ;
	for (w = StartFind(G, v); w >= 0; w = ConFind(G, v, w)) {
		if (!visited[w]) {
			DFS(G, w);
		}
	}
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
			//printf("\b");  //oj¿ÉÄÜ²»Í¨¹ý
			cout << "}";
			first = true;
		}
	}
}

void BFSTraverse(MGraph G)
{
	int i,e,w;
	first = true;
	for (i = 0; i < G.vexnum; i++) {
		visited[i] = false;
	}
	SqQueue q;
	InitQueue(q);
	for (i = 0; i<G.vexnum; i++){
		if (!visited[i]){
			visited[i] = true;
			EnQueue(q,i);
			cout << "{";
			while (QueueEmpty(q)==OK){
				int v = q.base[q.front];
				DeQueue(q,e);
				if (!first) {
					cout << " ";
				}
				first = false;
				cout << v ;
				for (w = StartFind(G, v); w >= 0; w = ConFind(G, v, w)){
					if (!visited[w]){
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
}

int main()
{
	MGraph G;
	CreateUDG(G);
	DFSTraverse(G);
	cout << endl;
	BFSTraverse(G);
	cout << endl;
}


/*
²¹³ä

acm/ojÅÐ¶Ï´ð°¸µÄÔ­Àí£¬Ëü»á½«±ê×¼Êä³öÖØ¶¨Ïòµ½ÎÄ¼þ£¬È»ºó±È½ÏÎÄ¼þÊÇ·ñÏàÍ¬¡£±ÈÈçÏÂÃæµÄ³ÌÐò£º

#include <stdio.h>

int main()
{
printf("1+1=2 \b");
}
ÖØ¶¨Ïòµ½ÎÄ¼þ£¬»á·¢ÏÖ\bÊÇ×÷ÎªÒ»¸ö×Ö·ûÊä³öµ½ÎÄ¼þÀïÃæµÄ¡£

±ÈÈç£¬ÉÏÃæµÄ´úÂëÖØ¶¨Ïòºó£¬²é¿´ÎÄ¼þµÄ16½øÖÆÊÇÏÂÃæµÄÇé¿ö

312b 313d 3220 080d 0a

1  +  1   =  2  \s \b \r  \n

20¾ÍÊÇ¿Õ°×

08 ¾ÍÊÇ \b

*/