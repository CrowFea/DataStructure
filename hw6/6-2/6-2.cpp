#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW   -2
#define MAXSIZE   100

typedef char  Status;
typedef char ElemType;

typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
	S.base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(SqStack &S, ElemType &e)
{
	if (S.top - S.base >= S.stacksize) {//Õ»Âú£¬×·¼Ó¿Õ¼ä
		S.base = (ElemType *)realloc(S.base, (S.stacksize + MAXSIZE) * sizeof(ElemType));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += MAXSIZE;
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
	while (p > S.base) {
		p--;
		cout << *p ;
	}
	cout << endl;
	return OK;
}

int getStrLength(char *str)
{
	int i=0;
	while (str[i]) {
		i++;
	}
	return i;
}


Status Trans(SqStack &S,int be,int af,char *str)
{
	int i,len,temp=0;
	i = 0;
	len = getStrLength(str)-1;
	while (str[i]) {
		int value = 0;
		if (str[i] >= '0' &&  str[i] < '9') {
			value = str[i] - 48;
		}
		if (str[i] >= 'A' && str[i] <= 'F') {
			value = str[i] - 65 + 10;
		}
		if (str[i] >= 'a' && str[i] <= 'f') {
			value = str[i] - 97 + 10;
		}
		temp+= int(value*pow(be, len));
		len--;
		i++;
	}
	while (temp) {
		int value = 0;
		value = temp % af;
		char ch;
		if (value>=0 &&  value<=9) {
			ch = value + 48;
		}
		if (value >= 10 && value <= 15) {
			ch = value + 65-10;
		}
		Push(S, ch);
		temp /= af;
	}
	return OK;
}

int main()
{
	char str[10];
	SqStack S;
	int be,af;
	InitStack(S);
	cin >> be >> af;
	cin >> str;
	Trans(S, be, af,str);
	ReadAll(S);
	return 0;
}