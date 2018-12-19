/*
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define FULL   -2
#define MAXSIZE		1000

typedef int  Status;
typedef string ElemType;

typedef struct StaticL {
	ElemType data;
	int cur;
}SLinkList;

Status input_initial(SLinkList L[], int m, int n);

void initial(SLinkList L[], int m, int n)
{
	
	L[0].data = "N/A";
	L[0].cur = -1;
	L[1].data = "N/A";
	L[1].cur = 2;
	
	L[m-1].data = "N/A";
	L[m - 1].cur = -1;
	int i;
	for (i = 2; i < m - 1; i++) {
		L[i].data= "N/A";
		L[i].cur = i + 1;
	}
	if (n != 0) {
		L[0].cur = 2;
		L[1].cur = 2 + n;
		//L[m - 1].cur = -1;
		L[2 + n - 1].cur = -1;
	}
	if (n + 2 >= m) {
		L[1].cur = -1;
	}
	input_initial(L, m,n);
	return;
}

Status input_initial(SLinkList L[], int m,int n)
{
	int pos = 0;
	int count = 2;
	if (n == 0) {
		//char ch;
		//cin >> ch;
		//cin.ignore(1024, '\n');
		//cin.clear();
		return OK;
	}
	while (n) {
		if (count>=m) {
			cin.ignore(1024, '\n');
			cin.clear();
			return FULL;
		}
		cin >> L[L[pos].cur].data;
		pos = L[pos].cur;
		count++;
		n--;
	}

	cin.ignore(1024, '\n');
	cin.clear();
	return OK;
}

Status getLength(SLinkList L[])
{
	int i;
	int count = 0;
	for (i = L[0].cur; i != -1; i = L[i].cur) {
		count++;
	}
	return count;
}

Status append(SLinkList L[], string val,int tarpos,int m)
{
	int i;
	bool flag = false;
	for (i = 2; i < m; i++) {
		if (L[i].data == "N/A") {
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "FULL" << endl;
		return ERROR;
	}
	if (tarpos > getLength(L) || tarpos <= 0) {
		cout << INFEASIBLE << endl;
		return ERROR;
	}

	for (i = 2; i < m; i++) {
		if (L[i].data == "N/A") {
			L[i].data = val;
			break;
		}
	}
	L[1].cur = 0;
	if (tarpos == 1) {
		L[i].cur = L[0].cur;
		L[0].cur = i ;
		return OK;
	}
	else {
		while (tarpos) {
			if (tarpos == 1) {
				L[i].cur = L[L[1].cur].cur;
				L[L[1].cur].cur = i;
			}
			L[1].cur = L[L[1].cur].cur;
			tarpos--;
		}
	}
	L[1].cur = -1;
	for (i = 2; i < m; i++) {
		if (L[i].data == "N/A") {
			L[1].cur=i;
			break;
		}
	}

	return OK;
}

void delElem(SLinkList L[], int m, int tarpos)
{
	if (L[0].cur == -1) {
		cout << "EMPTY" << endl;
		return;
	}
	if (tarpos > getLength(L) || tarpos <= 0) {
		cout << INFEASIBLE << endl;
		return;
	}
	L[1].cur = 0;
	if (tarpos == 1) {
		int t = 0;
		t= L[L[0].cur].cur;
		cout << L[L[0].cur].data << endl;
		L[L[0].cur].cur = -1;
		L[L[0].cur].data = "N/A";
		L[0].cur = t;
		return;
	}
	else {
		while (tarpos) {
			if (tarpos == 1) {
				int t;
				t = L[L[L[1].cur].cur].cur;
				cout << L[L[L[1].cur].cur].data << endl;
				L[L[L[1].cur].cur].cur = -1;
				L[L[L[1].cur].cur].data = "N/A";
				L[L[1].cur].cur = t;
			}
			L[1].cur = L[L[1].cur].cur;
			tarpos--;
		}
	}
	L[1].cur = -1;
	int i;
	for (i = 2; i < m; i++) {
		if (L[i].data == "N/A") {
			L[1].cur = i;
			break;
		}
	}
	return;
}




void locate(SLinkList L[], int m,ElemType tar)
{
	int i,count=1;
	for (i = L[0].cur; i != -1; i = L[i].cur) {
		if (L[i].data == tar) {
			cout << count << endl;
			return;
		}
		count++;
	}
	cout << INFEASIBLE << endl;
	return;
}
void print2(SLinkList L[], int m);

void append_tail(SLinkList L[], int m, ElemType tar)
{
	int i;
	bool flag = false;
	for (i = 2; i < m ; i++) {
		if (L[i].data == "N/A") {
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "FULL" << endl;
		return;
	}
	
	if (!getLength(L)) {
		L[2].data = tar;
		L[2].cur = -1;
		L[0].cur = 2;
		L[1].cur = 3;
		return;
	}

	for (i = L[0].cur; L[i].cur != -1; i = L[i].cur);
	int j;
	for (j = 2; j < m; j++) {
		if (L[j].data == "N/A") {
			L[j].data = tar;
			L[j].cur = -1;
			break;
		}
	}
	L[i].cur = j;
	for (j = 2; j < m; j++) {
		if (L[j].data == "N/A") {
			L[1].cur = j;
			break;
		}
	}
	print2(L, m);
	return;
}

void print1(SLinkList L[],int m)
{
	int i;
	bool flag = false;
	
	for (i = 2; i < m; i++) {
		if (L[i].data == "N/A") {
			flag = true;
			break;
		}
	}
	if (!flag) {
		L[1].cur = -1;
	}
	
	for (i = 0; i < m; i++) {
		cout << i << " : " << L[i].data << " : " << L[i].cur << "		";
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}
	}
	if (m % 3) {
		cout << endl;
	}
}

void print2(SLinkList L[], int m)
{
	int i;
	for (i = L[0].cur; i !=-1; i=L[i].cur) {
		cout << L[i].data << " " ;
	}
	cout << endl;
}

int main()
{
	SLinkList L[MAXSIZE];
	int m, n;
	cin >> m >> n;
	initial(L, m, n);
	print1(L, m);
	int pos;
	string str;
	while (1) {
		cin >> pos >> str;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	
	if (append(L, str, pos, m)) {
		//print1(L, m);
		print2(L, m);
		
	}
	while (1) {
		cin >> pos;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	delElem(L, m, pos);
	


	//print1(L, m);
	//print2(L, m);
	cin >> str;
	locate(L, m, str);
	cin >> str;
	append_tail(L, m, str);
	
	//print2(L, m);
	//cout << "FULL" << endl;
	print1(L, m);
	return 0;
}*/