#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

typedef struct MGraph {
	string vexs[10];//��������
	int arcs[10][10];//�ڽӾ���
	int vexnum, arcnum;//ͼ�Ķ������ͱ���
}MGraph;



int LocateVex(MGraph G, string u)//���ض���u��ͼ��λ��
{
	for (int i = 0; i<G.vexnum; i++)
		if (u == G.vexs[i])
			return i;
	return -1;
}

void CreateUDG(MGraph &G)//��������ͼ
{
	string v1, v2;
	int i, j, k;
	cout << "�����붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥��:";
	for (i = 0; i<G.vexnum; i++)
		cin >> G.vexs[i];

	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.arcs[i][j] = 0;

	cout << "������ߣ�" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = 1;
	}
}

void CreateUDN(MGraph &G)//����������
{
	string v1, v2;
	int i, j, k;
	int w;
	cout << "�����붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥��:";
	for (i = 0; i<G.vexnum; i++)
		cin >> G.vexs[i];

	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.arcs[i][j] = -1000;

	cout << "������ߣ�" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = w;
	}
}

void CreateDG(MGraph &G)//��������ͼ
{
	string v1, v2;
	int i, j, k;
	cout << "�����붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥��:";
	for (i = 0; i<G.vexnum; i++)
		cin >> G.vexs[i];

	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.arcs[i][j] = 0;

	cout << "������ߣ�" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
	}
}

void CreateDN(MGraph &G)//����������
{
	string v1, v2;
	int i, j, k;
	int w;
	cout << "�����붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥��:";
	for (i = 0; i<G.vexnum; i++)
		cin >> G.vexs[i];

	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.arcs[i][j] = -1000;

	cout << "������ߣ�" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
	}
}

int FirstAdjVex(MGraph G, int v)//���ض���v�ĵ�һ���ڽӶ������
{
	for (int i = 0; i<G.vexnum; i++)
		if (G.arcs[v][i] == 1)
			return i;
	return -1;
}

int NextAdjVex(MGraph G, int v, int w)//���ض���v�������w����һ���ڽӶ������
{
	for (int i = w + 1; i<G.vexnum; i++)
		if (G.arcs[v][i] == 1)
			return i;
	return -1;
}

bool visited[100];

void DFS(MGraph G, int v)
{
	visited[v] = true;
	cout << G.vexs[v] << " ";
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (!visited[w])
			DFS(G, w);
}

void DFSTraverse(MGraph G)//����
{
	for (int i = 0; i<G.vexnum; i++)
		visited[i] = false;

	for (i = 0; i<G.vexnum; i++)
		if (!visited[i])
			DFS(G, i);
}

void BFSTraverse(MGraph G)//����,���������Ĳ�α���
{
	for (int i = 0; i<G.vexnum; i++)
		visited[i] = false;

	queue<int> q;

	for (i = 0; i<G.vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			q.push(i);
			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				cout << G.vexs[v] << " ";
				for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
				{
					if (!visited[w])
					{
						visited[w] = true;
						q.push(w);
					}
				}
			}
		}
	}
}

void main()
{
	MGraph g;
	CreateUDG(g);

	cout << "���ѣ�";
	DFSTraverse(g);
	cout << endl;

	cout << "���ѣ�";
	BFSTraverse(g);
	cout << endl;



}
