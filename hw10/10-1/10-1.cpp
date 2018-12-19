#include<iostream>
#include<iomanip>
using namespace std;

#define MAXSIZE 100
#define EMPTY 0
#define ERROR -1
#define TRUE 1
#define OK 1
#define OVERFLOWED -2

typedef int Status;
typedef char ElemType;

typedef struct LNode{
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
		cin >> G.vexs[i];
		G.List[i] = new VextexNode();
		G.List[i]->data = G.vexs[i];
		G.List[i]->next= NULL;
	}
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = EMPTY;
		}
	}
	return 0;
}

int LocateVex(MGraph G, char u)
{
	for (int i = 0; i < G.vexnum; i++)
		if (u==G.vexs[i]) {
			return i;
		}
	return -1;
}

void CreatAdjList(MGraph &G, char v1, char v2)
{
	int i, j;
	i = LocateVex(G, v1);
	j = LocateVex(G, v2);

	AdjList p1;
	p1 = G.List[i];
	while (p1->next!=NULL) {
		p1=p1->next;
	}
	p1->next = new VextexNode();
	p1 = p1->next;
	p1->data = j;
	p1->num = j;
	p1->weight = G.arcs[i][j];
	p1->next = NULL;

	return;
}

void CreateUDG(MGraph &G)
{
	char v1, v2;
	int i, j, k;

	InitMGraph(G);

	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = 1;
		CreatAdjList(G, v1, v2);
		CreatAdjList(G, v2, v1);
	}
}

void CreateUDN(MGraph &G)
{
	char v1, v2;
	int i, j, k;
	int w;

	InitMGraph(G);
	for (k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = w;
		CreatAdjList(G, v1, v2);
		CreatAdjList(G, v2, v1);
	}
}

void CreateDG(MGraph &G)
{
	char v1, v2;
	int i, j, k;

	InitMGraph(G);


	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
		CreatAdjList(G, v1, v2);
	}
	return;
}

void CreateDN(MGraph &G)
{
	char v1, v2;
	int i, j, k;
	int w;

	InitMGraph(G);
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		CreatAdjList(G, v1, v2);

	}
}

void PrintMar(MGraph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			cout << setw(4) << G.arcs[i][j];
		}
		cout << endl;
	}
	return;
}

void shellSort(int arr[], int len) {
	int j = 0, tmp = 0;
	for (int d = len / 2; d >0; d /= 2) {
		for (int i = d; i <len; i++) {
			j = i - d;      
			tmp = arr[i];
			while (j >= 0 && arr[j]<tmp) {
				arr[j + d] = arr[j];
				j -= d;
			}
			arr[j + d] = tmp;
		}
	}
}

void shellSort2(int arr[][2], int len) {
	int j = 0, tmp = 0,tmp1=0;
	for (int d = len / 2; d >0; d /= 2) {
		for (int i = d; i <len; i++) {
			j = i - d;
			tmp = arr[i][0];
			tmp1 = arr[i][1];
			while (j >= 0 && arr[j][0]<tmp) {
				arr[j + d][0] = arr[j][0];
				arr[j + d][1] = arr[j][1];
				j -= d;
			}
			arr[j + d][0] = tmp;
			arr[j + d][1] = tmp1;
		}
	}
}

void PrintList(MGraph G)
{
	int i,k,j=0;
	
	for (i = 0; i < G.vexnum; i++) {
		int sort[MAXSIZE] = { -1 };
		j = 0;
		AdjList p;
		p = G.List[i];
		cout << p->data << "-->";
		while (p->next!=NULL) {
			p = p->next;
			sort[j] = p->num;
			j++;
		}
		shellSort(sort, j);
		for (k = 0; k < j; k++) {
			cout << sort[k] << " ";
		}
		cout << endl;
	}
	return;
}

void PrintListU(MGraph G)
{
	int i,k,j=0;

	for (i = 0; i < G.vexnum; i++) {
		int sort[MAXSIZE][2];
		j = 0;
		AdjList p;
		p = G.List[i];
		cout << p->data << "-->";
		while (p->next != NULL) {
			p = p->next;
			sort[j][0] = p->num;
			sort[j][1] = p->weight;
			j++;
		}
		shellSort2(sort, j);
		for (k = 0; k < j; k++) {
			cout << sort[k][0] << ","<<sort[k][1]<<" ";
		}
		cout << endl;
	}
	return;
}

int main()
{
	MGraph G;
	int choice,i;
	cin >> choice;
	switch (choice)
	{
		case 1:	
			CreateDG(G);
			break;
		case 2:	
			CreateDN(G);
			break;
		case 3:	
			CreateUDG(G);
			break;
		case 4:	
			CreateUDN(G);
			break;
		default:
			break;
	}
	for (i = 0; i < G.vexnum; i++) {
		cout << G.vexs[i] << " ";
	}
	cout << endl;
	PrintMar(G);
	if (choice % 2==1) {
		PrintList(G);
	}
	else {
		PrintListU(G);
	}
	return 0;
}
