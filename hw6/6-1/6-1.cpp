#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW   -2

typedef int  Status;
typedef int ElemType;

typedef struct{
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
	S.base = (ElemType*)malloc(S.stacksize * sizeof(ElemType));
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	return OK;
}

Status Push(SqStack &S, ElemType &e)
{
	if (S.top - S.base >= S.stacksize) {
		cout << "Stack is Full" << endl;
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base) {
		cout << "Stack is Empty" << endl;
		return ERROR;
	}
	else{
		S.top--;
		e = *S.top;
		cout << e << endl;
		return OK;
	}
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base) {
		return ERROR;
	}
	else {
		return TRUE;
	}
}

Status ReadAll(SqStack S)
{
	if (S.base == NULL) {
		return ERROR;
	}
	if (S.top == S.base) {
		cout << "Stack is Empty" << endl;
		return ERROR;
	}
	ElemType *p;
	p = S.top;
	while (p > S.base){
		p--;
		cout << *p << " ";
	}
	cout << endl;
	return OK;
}

int main()
{
	char str[10];
	SqStack S;
	int num;
	cin >> S.stacksize;
	InitStack(S);
	while (1) {
		cin >> str;
		if (strcmp(str, "push")==0) {
			cin >> num;
			Push(S,num);
			continue;
		}
		if (strcmp(str, "pop")==0) {
			Pop(S, num);
			continue;
		}
		if (strcmp(str, "quit")==0) {
			ReadAll(S);
			break;
		}
	}
	return 0;
}