#include<iostream>
using namespace std;

#define OK 1
#define ERROR -1
#define maxl 100001
#define INFINITY 2147483646
#define MAXSIZE 100

typedef int ElemType;
typedef char VertexType;
typedef int Status;


typedef struct {
	VertexType vexs[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
}MGraph;

typedef struct ANode {
	int adjvex;
	struct ANode *nextarc;
	ElemType data;
}ANode, *ListNode;

typedef struct Node {
	VertexType data;
	ANode *firstarc;
}Node, AdjList[MAXSIZE];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}GraphList;

Status CreateUDG(GraphList &G) {
	int v1, v2;
	int w;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i<G.vexnum; i++) {
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i<G.arcnum; i++) {
		cin >> v1 >> v2;
		ListNode p1, p2;

		p1 = new ANode();
		p1->nextarc = G.vertices[v1].firstarc;
		p1->adjvex = v2;
		p1->data = 1;
		G.vertices[v1].firstarc = p1;

		p2 = new ANode();
		p2->nextarc = G.vertices[v2].firstarc;
		p2->adjvex = v1;
		p2->data = 1;
		G.vertices[v2].firstarc = p2;
	}
	return OK;
}

void DFS(GraphList G, int v, int visit[]) {
	cout << v;
	ListNode p = G.vertices[v].firstarc;
	int q;
	while (p != NULL) {
		q = p->adjvex;
		if (!visit[q]) {
			visit[q] = 1;
			cout << " ";
			DFS(G, q, visit);
		}
		p = p->nextarc;
	}
}

void DFSTraverse(GraphList G)
{
	int visit[MAXSIZE];
	int num = G.vexnum;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		visit[i] = 0;
	}
	for (int i = 0; i<num; i++) {
		if (!visit[i]) {
			cout << '{';
			visit[i] = 1;
			DFS(G, i, visit);
			cout << '}';
		}
	}
}

void BFS(GraphList G, int v, int visit[]) 
{
	int queue[MAXSIZE];
	int head = 1;
	int tail = 1;
	queue[tail] = v;
	tail++;
	bool flag = false;
	int v1, q;
	while (head<tail) {
		v1 = queue[head];
		if (flag == false) {
			cout << v1;
			flag = true;
		}
		else cout << " " << v1;
		ListNode p = G.vertices[v1].firstarc;
		while (p != NULL) {
			q = p->adjvex;
			if (!visit[q]) {
				visit[q] = 1;
				queue[tail] = q;
				tail++;
			}
			p = p->nextarc;
		}
		head++;
	}
}

void BFSTraverse(GraphList G)
{
	int visit[MAXSIZE];
	int num = G.vexnum;	int i;
	for (i = 0; i < G.vexnum; i++) {
		visit[i] = 0;
	}
	for (int i = 0; i<num; i++) {
		if (!visit[i]) {
			cout << '{';
			visit[i] = 1;
			BFS(G, i, visit);
			cout << '}';
		}
	}
}

int main() {
	GraphList G;
	CreateUDG(G);
	DFSTraverse(G);
	cout << endl;
	BFSTraverse(G);
	cout << endl;
	return 0;
}
