/*
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
#define OVERFLOWED   -2
#define MAXSIZE   1000

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
		exit(OVERFLOWED);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(SqStack &S, ElemType &e)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType *)realloc(S.base, (S.stacksize + MAXSIZE) * sizeof(ElemType));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += MAXSIZE;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S)
{
	ElemType e;
	if (S.top == S.base) {
		return ERROR;
	}
	else {
		e = *S.top;
		S.top--;
		return e;
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

Status GetTop(SqStack S)
{
	ElemType e;
	if (S.top == S.base) {
		return FALSE;
	}
	else {
		e = *(S.top - 1);
	}
	return e;
}

int getStrLength(char *str)
{
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

void Station(char *instr,char *outstr)
{
	if (getStrLength(outstr) != getStrLength(instr)) {
		cout << "no" << endl;
		return;
	}
	
	int i, j=0;
	ElemType e=0;
	char input[MAXSIZE] = { 0 }, out[MAXSIZE]= { 0 };
	SqStack S;
	InitStack(S);

	for (i = 0; i<getStrLength(outstr); i++) {
		if (!StackEmpty(S)) {
			e = GetTop(S);
			if (e == outstr[i]) {
				Pop(S);
				continue;
			}
		}
		while (instr[j] != outstr[i]) {
			if (j >= getStrLength(instr)) {
				break;
			}
			Push(S, instr[j]);
			j++;
		}
		j++;
	}
	if (i == j && StackEmpty(S)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	while (!StackEmpty(S)){
		Pop(S);
	}
	return ;
}

int main()
{
	char instr[MAXSIZE];
	cin >> instr;
	int n=1,i = getStrLength(instr);
	while (i != 1) {
		n *= i;
		i -- ;
	}
	cin.ignore(1, '\n');
	int len= getStrLength(instr);
	while (n) {
		char outstr[MAXSIZE];

		cin.getline(outstr,len);
		//cin.ignore(1024, '\n');
		Station(instr, outstr);

		n--;
	}
	return 0;
}
*/