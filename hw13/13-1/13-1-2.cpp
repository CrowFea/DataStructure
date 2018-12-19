#include<iostream>
using namespace std;

#define MAXVEX 10010
#define MAXARC 500010
#define INF 2147483647

int dep;
int v1S[MAXARC], v2S[MAXARC], weightS[MAXARC], nex[MAXARC];
int group[MAXARC * 5], dist[MAXVEX + 1];


void Store(int v1, int v2, int weight)
{
	dep++;
	v2S[dep] = v2;
	weightS[dep] = weight;
	nex[dep] = v1S[v1];
	v1S[v1] = dep;
}

void SPFA(int start, int Vexnum)
{
	bool visited[MAXVEX + 1];
	int i,head = 0,tail = 1;
	for (i = 1; i <= Vexnum; i++) {
		dist[i] = INF;
		visited[i] = false;
	}
	dist[start] = 0;
	group[tail] = start;
	visited[start] = true;
	while (head <= tail) {
		head++;
		int temp = group[head];
		int k = v1S[temp];
		while (k != 0) {
			int cur = v2S[k];
			if (dist[cur]>dist[temp] + weightS[k]) {
				dist[cur] = dist[temp] + weightS[k];
				if (visited[cur] == false) {
					visited[cur] = true;
					tail++;
					group[tail] = cur;
				}
			}
			k = nex[k];
		}
		visited[temp] = false;
	}
}

int main()
{
	int Vexnum, arcnum, start, end;
	int v1, v2, weight;
	int i;
	cin >> Vexnum >> arcnum >> start >> end;
	dep = 0;
	for (i = 1; i <= arcnum; i++) {
		cin >> v1 >> v2 >> weight;
		Store(v1, v2, weight);
		Store(v2, v1, weight);
	}
	SPFA(start, Vexnum);
	cout << dist[end] << endl;
	return 0;
}
