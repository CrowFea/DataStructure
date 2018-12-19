/*
#include<iostream>
#include<iomanip>
using namespace std;

#define MAXSIZE 10000
#define DATA 0
#define LEFT 1
#define RIGHT 2

typedef int ElemType;

struct Node {
	ElemType node[3];
};

Node *pre;

void insert(Node *OrderT, int value) 
{
	int i = 0, pos = 0,flag=0;
	while (OrderT[i].node[DATA]) {
		if (value < OrderT[i].node[DATA]) {
			if (OrderT[i].node[LEFT]!=-1) {
				i = OrderT[i].node[LEFT];
				continue;
			}
			else {
				flag = 1;
				break;
			}
			
		}
		else {
			if (OrderT[i].node[RIGHT]!=-1) {
				i = OrderT[i].node[RIGHT];
				continue;
			}
			else {
				flag = 2;
				break;
			}
		}
	}
	
	pos = i;
	for (i=0; OrderT[i].node[DATA] != 0; i++);
	OrderT[i].node[DATA] = value;
	if (flag == 1) {
		OrderT[pos].node[LEFT] = i;
	}
	if (flag == 2) {
		OrderT[pos].node[RIGHT] = i;
	}

}

void delOrderNode(Node OrderT[], int value)
{
	int i=0,pre=0,flag=0;
	while (OrderT[i].node[DATA]) {
		if (value == OrderT[i].node[DATA]) {
			break;
		}
		else if (value < OrderT[i].node[DATA]) {
			pre = i;
			flag = 1;
			if (OrderT[i].node[LEFT]!=-1) {
				i = OrderT[i].node[LEFT];
			}
			else {
				cout << "0" << endl;
				return;
			}
		}
		else {
			pre = i;
			flag = 2;
			if (OrderT[i].node[RIGHT]!=-1) {
				i = OrderT[i].node[RIGHT];
			}
			else {
				cout << "0" << endl;
				return;
			}
		}
	}

	int pos = OrderT[i].node[LEFT];
	int delpos = i;
	if (flag == 1) {
		OrderT[pre].node[LEFT] = pos;
	}
	else {
		OrderT[pre].node[RIGHT] = pos;
	}

	if (OrderT[pos].node[RIGHT]!=-1) {
		while (OrderT[i].node[RIGHT]) {
			i = OrderT[i].node[RIGHT];
		}
		OrderT[i].node[RIGHT] = OrderT[pos].node[RIGHT];
	}

	OrderT[pos].node[RIGHT] = OrderT[delpos].node[RIGHT];

	OrderT[delpos].node[RIGHT] = -1;
	OrderT[delpos].node[LEFT] = -1;
	OrderT[delpos].node[DATA] = 0;
	cout << "1" << endl;

}

void preOrderTra(Node *OrderT,int cur,int pos,int arr[],int level)
{
	arr[0]++;
	arr[level+1]++;
	cout << OrderT[cur].node[DATA] << " ";
	if (OrderT[cur].node[LEFT] != -1) {
		preOrderTra(OrderT, OrderT[cur].node[LEFT], cur,arr,level+1);
	}
	if (OrderT[cur].node[RIGHT] != -1) {
		preOrderTra(OrderT, OrderT[cur].node[RIGHT], cur,arr, level + 1);
	}
}

void searchIns(Node *OrderT, int value)
{
	int i = 0, pre = 0, flag = 0;
	while (OrderT[i].node[DATA]) {
		if (value == OrderT[i].node[DATA]) {
			cout << "1" << endl;
			break;
		}
		else if (value < OrderT[i].node[DATA]) {
			pre = i;
			flag = 1;
			if (OrderT[i].node[LEFT] != -1) {
				i = OrderT[i].node[LEFT];
			}
			else {
				cout << "0" << endl;
				insert(OrderT, value);
				return;
			}
		}
		else {
			pre = i;
			flag = 2;
			if (OrderT[i].node[RIGHT] != -1) {
				i = OrderT[i].node[RIGHT];
			}
			else {
				cout << "0" << endl;
				insert(OrderT, value);
				return;
			}
		}
	}
}

int main()
{
	int i, n;
	int value;
	Node OrderT[MAXSIZE];
	cin >> n;
	for (i = 0; i < n; i++) {
		OrderT[i].node[DATA] = 0;
		OrderT[i].node[LEFT] = -1;
		OrderT[i].node[RIGHT] = -1;
	}
	for (i = 0; i < n; i++) {
		cin >> value;
		insert(OrderT, value);
	}


	cin >> value;
	delOrderNode(OrderT, value);
	

	searchIns(OrderT, value);

	int arr[MAXSIZE];
	for (i = 0; i <= n; i++) {
		arr[i] = 0;
	}
	preOrderTra(OrderT, 0, 0,arr,0);
	cout << endl;

	double sum = 0;
	for (i = 0; arr[i+1] != 0; i++) {
		sum += (i + 1)*arr[i+1];
	}
	if (n == 0) {
		cout << fixed << setprecision(2) << 1.00 << endl;
	}
	else {
		cout << fixed << setprecision(2) << (sum / arr[0]) << endl;
	}
	return 0;
}
*/