#include <iostream>
#include <string.h>
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

void SetStack(SqStack &S,int n)
{
	S.base = new ElemType[n + 1];
	if (S.base == NULL)
		exit(OVERFLOWED);
	S.top = S.base;
	S.stacksize = n;
}

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

Status StackFULL(SqStack S)
{
	if (S.top - S.stacksize == S.base){
		return 1;
	}
	return 0;
}

Status GetHead(SqStack S,ElemType &e)
{
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

void Hanoi(int n, int k)
{
	ElemType e = 0, e1 = 0;
	int i, j, mark = 0;
	SqStack   Q[1000];
	for (i = 0; i < n; i++){
		cin >> j;
		SetStack(Q[i],j);
	}
	for (i = 0; i < k; i++){
		cin >> j;
		Push(Q[0],j);
	}
	while (1){
		char chr[MAXSIZE];
		mark = 0;
		cin >> chr;
		if (strcmp(chr, "QUIT") == 0){
			for (i = 0; i < n; i++){
				if (StackEmpty(Q[i]) == TRUE) {
					cout << 0 << endl;
				}
				else {
					ReadAll(Q[i]);
				}
			}
			break;
		}
		else if (strcmp(chr, "DISPLAY") == 0){
			cin >> i;
			if (StackEmpty(Q[i - 1]) == TRUE) {
				cout << 0 << endl;
			}
			else {
				ReadAll(Q[i - 1]);
			}
		}
		else if (strcmp(chr, "MOVE") == 0){
			cin >> i >> j;
			if (StackEmpty(Q[i - 1]) == TRUE){
				cout << i << " IS EMPTY"<<endl;
				mark = 1;
			}
			if (StackFULL(Q[j - 1]) == TRUE){
				cout << j << " IS FULL"<<endl;
				mark = 1;
			}
			if (GetHead(Q[i - 1],e) == TRUE && GetHead(Q[j - 1], e1) == TRUE){
				if (e > e1){
					cout << "ILLEGAL"<<endl;
					mark = 1;
				}
			}
			if (mark == 0){
				Pop(Q[i - 1],e);
				Push(Q[j - 1],e);
			}
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	Hanoi(n, k);
	return 0;
}

