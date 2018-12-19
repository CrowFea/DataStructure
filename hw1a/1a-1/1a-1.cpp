
#include<iostream>
#include<string.h>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2
#define MAXSIZE   1000
#define EMPTY   -100

typedef int  Status;
typedef int ElemType;

typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
	S.stacksize = MAXSIZE;
	S.base = (ElemType*)malloc(S.stacksize * sizeof(ElemType));
	if (!S.base) {
		exit(OVERFLOWED);
	}
	S.top = S.base;
	return OK;
}

Status Push(SqStack &S, ElemType &e)
{
	if (S.top - S.base >= S.stacksize) {
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base) {
		return ERROR;
	}
	else {
		S.top--;
		e = *S.top;
		cout << e << endl;
		return OK;
	}
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Status ReadAll(SqStack S)
{
	if (S.base == NULL) {
		return ERROR;
	}
	if (S.top == S.base) {
		return ERROR;
	}
	ElemType *p;
	p = S.top;
	while (p > S.base) {
		p--;
		cout << *p << " ";
	}
	cout << endl;
	return OK;
}

Status HMove(ElemType **Tower)
{
	int from, to;
	bool flag = true;
	cin >> from >> to;
	from--;
	to--;
	if (Tower[from][1] == EMPTY) {
		cout << from+1 << " IS EMPTY" << endl;
		flag = false;
	}
	if (Tower[to][Tower[to][0]] != EMPTY) {
		cout << to+1 << " IS FULL" << endl;
		flag = false;
	}
	int loc1, loc2;
	for (loc1 = 1; loc1 <= MAXSIZE; loc1++) {
		if (Tower[from][loc1 + 1] == EMPTY) {
			break;
		}
	}
	for (loc2 = 1; loc2 <= MAXSIZE; loc2++) {
		if (Tower[to][loc2] == EMPTY) {
			break;
		}
	}
	if (Tower[to][1] !=EMPTY) {
		if (Tower[from][loc1] > Tower[to][loc2-1]) {
			cout << "ILLEGAL" << endl;
			return ERROR;
		}
	}
	if (flag) {
		Tower[to][loc2] = Tower[from][loc1];
		Tower[from][loc1] = EMPTY;

		cout << Tower[to][loc2] << endl;
	}
	return OK;
}

Status HDisplay(ElemType **Tower,int choice)
{
	choice--;
	int i=1;
	SqStack S;
	InitStack(S);
	while (1) {
		if (Tower[choice][i] == EMPTY) {
			if (i == 1) {
				cout << 0 << endl;
				return EMPTY;
			}
			break;
		}
		Push(S, Tower[choice][i]);
		i++;
	}
	ReadAll(S);
	return OK;
}

Status Hanoi(ElemType **Tower,int n)
{
	while (1) {
		char str[10];
		cin >> str;
		if (strcmp(str, "MOVE")==0) {
			HMove(Tower);
		}
		else if (strcmp(str, "DISPLAY")==0) {
			int choice;
			cin >> choice;
			HDisplay(Tower,choice);
		}
		else if (strcmp(str, "QUIT")==0) {
			int choice;
			for (choice = 0; choice < n; choice++) {
				HDisplay(Tower, choice+1);
			}
			return OK;
		}
		else {
			cin.ignore(1024, '\n');
			cin.clear();
			continue;
		}
	}
	return OK;
}


int main()
{
	int n, k,n1;
	cin >> n >> k;
	n1 = n;
	ElemType **Tower;
	int i = 0, j = 0;

	Tower = new ElemType* [n]; 
	for (i = 0; i<n; i++){
		Tower[i]=new ElemType[MAXSIZE];  
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < MAXSIZE; j++) {
			Tower[i][j] = EMPTY;
		}
	}
	i = 0; 
	j = 0;
	while (n1) {
		cin >> Tower[i][0];
		if (!cin.good()) {
			cin.ignore(1024, '\n');
			cin.clear();
			continue;
		}
		i++;
		n1--;
	}
	i = 0;
	j = 1;
	while (k) {
		cin >> Tower[i][j];
		if (!cin.good()) {
			cin.ignore(1024, '\n');
			cin.clear();
			continue;
		}
		j++;
		k--;
	}

	Hanoi(Tower, n);
	return 0;

}

