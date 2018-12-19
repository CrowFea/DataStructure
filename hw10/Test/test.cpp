#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef int E;
typedef char T;
#define DefaultVertices 30
bool visited[DefaultVertices] = { 0 };
int first;
class Graph {
public:
	const E maxWeight = 10000;
	Graph(int sz = DefaultVertices) {};
	bool GraphEmpty()const {
		if (numEdges == 0)return true;
		else return false;
	}
	bool GraphFull()const {
		if (numVertices == maxVertices || numEdges == maxVertices * ((maxVertices - 1) / 2))return true;
		else return false;
	}
	int NumberOfVertices() { return  numVertices; }
	int NumberOfEdges() { return numEdges; }
	virtual T getValue(int i) = 0;
	virtual int getFirstNeighbor(int v) = 0;
	virtual int getNextNeighbor(int v, int w) = 0;
	virtual bool insertEdge(int v1, int v2, E cost) = 0;
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(T vertex) = 0;
};
class Graphmtx :public Graph {
private:
	T * VerticesList;
public:
	E * *Edge;
	int getVertexPos(T vertex) {
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == vertex)return i;
	}
	Graphmtx(int sz = DefaultVertices);
	~Graphmtx() { delete[]VerticesList; delete[]Edge; }
	T getValue(int i) {
		return i >= 0 && i < numVertices ? VerticesList[i] : NULL;
	}
	E getWeight(int v1, int v2) {
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	bool insertVertex(const T& cost);
	bool insertEdge(int v1, int v2, E cost);
	void DFS(int v);
	void DFSTraverse();
};

Graphmtx::Graphmtx(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];
	Edge = (E**)new E*[maxVertices];
	for (i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	for (i = 0; i < maxVertices; i++)
	{
		for (j = 0; j < maxVertices; j++)
		{
			Edge[i][j] = (i == j) ? 0 : maxWeight;
		}
	}
}

int Graphmtx::getFirstNeighbor(int v)
{
	if (v != -1) {
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)return col;
	}
	return -1;
}

int Graphmtx::getNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1) {
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)return col;
	}
	return -1;
}

bool Graphmtx::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)return false;
	VerticesList[numVertices] = vertex;
	numVertices++;
	return true;
}

bool Graphmtx::insertEdge(int v1, int v2, E cost)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight) {
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}

//深度优先遍历（递归）
void Graphmtx::DFS( int v)
{
	int w;
	visited[v] = true;
	if (!first) {
		cout << " ";
	}
	first = false;
	cout << v;
	for (w = getFirstNeighbor(v); w >= 0 && w<NumberOfVertices(); w = getNextNeighbor(v, w)) {
		if (!visited[w]) {
			DFS( w);
		}
	}
}

void Graphmtx::DFSTraverse()
{
	int i;
	for (i = 0; i < numVertices; i++) {
		visited[i] = false;
	}

	for (i = 0; i < numVertices; i++) {
		if (!visited[i]) {
			cout << "{";
			DFS(i);
			cout << "}";
			first = true;
		}
	}
}
int main()
{
	Graphmtx G;
	int bian, dian, i, j, k, count = 0, mark = 1;
	E e1, e2;
	int a[20] = { 0 };
	cin >> dian >> bian;
	for (int i = 0; i < dian; i++)
	{
		G.insertVertex(i + '0');
	}
	for (int i = 0; i < bian; i++)
	{
		cin >> e1 >> e2;
		G.insertEdge(e1, e2, 1);
		G.insertEdge(e2, e2, 1);
	}
	j = 0;
	for (i = 0; i<dian; i++)
	{
		for (j = 0; j<dian; j++)
		{
			if (G.Edge[i][j] == G.maxWeight)
				printf("%6d", 0);
			else
				printf("%6d", G.Edge[i][j]);
		}
		printf("\n");
	}
	i = 0;
	k = 0;
	j = 0;
	G.DFSTraverse();
}

