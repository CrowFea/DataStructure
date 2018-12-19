#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2	
#define MAXSIZE 10000
#define MAXQSIZE	10000	

typedef int ElemType;
typedef int Status;
typedef int QElemType;

bool *visited;

class SqQueue {
protected:
	int        rear;		
	int        maxsize;
public:
	int        front;	
	QElemType *base;
	SqQueue();	
	SqQueue(int n);
	~SqQueue();	
	Status	ClearQueue();
	Status	QueueEmpty();
	int	QueueLength();
	Status	GetHead(QElemType &e);
	Status	EnQueue(QElemType e);
	Status	DeQueue(QElemType &e);
	Status	QueueTraverse(Status(*visit)(QElemType e));
};

SqQueue::SqQueue()
{
	base = new QElemType[MAXQSIZE];
	if (base == NULL)
		exit(OVERFLOW);
	front = rear = 0;
	maxsize = MAXQSIZE;
}

SqQueue::SqQueue(int n)
{
	base = new QElemType[n + 1];
	if (base == NULL)
		exit(OVERFLOW);
	front = rear = 0;
	maxsize = n + 1;
}

SqQueue::~SqQueue()
{
	delete base;
}

Status	SqQueue::ClearQueue()
{
	front = rear = 0;
	return OK;
}

Status	SqQueue::QueueEmpty()
{
	if ((rear - front + maxsize) % maxsize == 0){
		return OK;
	}
	else
	{
		return FALSE;
	}
}

Status	SqQueue::EnQueue(QElemType e)
{
	if ((rear + 1) % maxsize == front)
		return FALSE;
	base[rear] = e;
	rear = (rear + 1) % maxsize;
	return OK;
}

Status	SqQueue::DeQueue(QElemType &e)
{
	if (front == rear)
		return ERROR;
	e = base[front];
	front = (front + 1) % maxsize;
	return OK;
}

struct Edge
{
	int dest;
	ElemType cost;
	Edge *link;
	Edge() {}
	Edge(int num, ElemType weight) :dest(num), cost(weight), link(NULL) {}
	bool operator !=(Edge &R)const { return(dest != R.dest) ? true : false; }
};

struct  Vertex
{
	char data;
	Edge *adj;
};

class Graph {
public:
	
	Graph(int size = MAXSIZE) {};
	bool GraphEmpty()const {
		if (numEdges == 0)return true;
		else return false;
	}
	bool GraphFull()const {
		if (numVertices == maxVertices || numEdges == maxVertices * ((maxVertices - 1) / 2))return true;
		else return false;
	}

	virtual char getValue(int i) = 0;
	virtual int StartFind(int v) = 0;
	virtual int ConFind(int v, int w) = 0;
	virtual bool insertEdge(int v1, int v2, ElemType cost) = 0;
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(char vertex) = 0;
};

class GLinkList :public Graph 
{
public:
	Vertex * NodeTable;
	int getVertexPos(char vertex) {
		for (int i = 0; i < numVertices; i++)
			if (NodeTable[i].data == vertex)return i;
	}
	GLinkList(int size = MAXSIZE);
	~GLinkList();
	char getValue(int i) {
		return i >= 0 && i < numVertices ? NodeTable[i].data : NULL;
	}
	int StartFind(int v);
	int ConFind(int v, int w);
	bool insertVertex(const char& cost);
	bool insertEdge(int v1, int v2, ElemType cost);
	int BFS(int i);
	void BFST();
};

GLinkList::GLinkList(int size)
{
	maxVertices = size;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex[maxVertices];
	if (NodeTable == NULL) { 
		exit(-1); 
	}
	for (int i = 0; i < maxVertices; i++) {
		NodeTable[i].adj = NULL;
	}
}

GLinkList::~GLinkList()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge *p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p; p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;
}

int GLinkList::StartFind(int v)
{
	if (v != -1) {
		Edge *p = NodeTable[v].adj;
		if (p != NULL)return p->dest;
	}
	return -1;
}

int GLinkList::ConFind(int v, int w)
{
	if (v != -1) {
		Edge *p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}

bool GLinkList::insertVertex(const char& vertex)
{
	if (numVertices == maxVertices)return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}

bool GLinkList::insertEdge(int v1, int v2, ElemType weight)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices) {
		Edge *q, *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
			p = p->link;
		if (p != NULL)return false;
		p = new Edge; q = new Edge;
		p->dest = v2; p->cost = weight;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1; q->cost = weight;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;
}

int GLinkList::BFS(int input)
{
	int e, w, count = 1, tail;
	memset(visited, 0, numVertices);
	SqQueue q;
	int level = 0;
	int last = input;
	visited[input] = true;
	q.EnQueue(input);
	while (q.QueueEmpty() != OK) {
		int v = q.base[q.front];
		q.DeQueue(e);
		for (w = StartFind(v); w >= 0 && w<numVertices; w = ConFind(v, w)) {
			if (!visited[w]) {
				visited[w] = true;
				count++;
				tail = w;
				q.EnQueue(w);
			}
		}
		if (v == last) {
			level++;
			last = tail;
		}
		if (6 <= level) {
			return count;
		}
	}
	return count;
}

void GLinkList::BFST()
{
	int counter;
	for (int i = 0; i < numVertices; i++) {
		counter = BFS(i);
		memset(visited, 0, numVertices);
		cout << i + 1 << ": " << setiosflags(ios::fixed) << setprecision(2)
			<< ((float)counter / numVertices) * 100 << "%" << endl;
	}
}

int main()
{
	GLinkList G;
	int arc, vertex;
	ElemType v1, v2;
	cin >> vertex >> arc;
	visited = new bool[vertex];
	for (int i = 0; i < vertex; i++){
		G.insertVertex(i + '0');
	}
	for (int i = 0; i < arc; i++){
		cin >> v1 >> v2;
		G.insertEdge(v1 - 1, v2 - 1, 1);
		G.insertEdge(v2 - 1, v1 - 1, 1);
	}
	G.BFST();
	delete visited;
	return 0;
}
