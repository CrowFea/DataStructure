#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       -968
#define INFEASIBLE  -1
#define OVERFLOWED   -2
#define MAXSIZE   1000000

typedef char Status;

typedef int ElemType;	

typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;


Status InitSqStack(SqStack &S)
{
	S.base = new ElemType[MAXSIZE + 1];
	if (S.base == NULL)
		exit(OVERFLOWED);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status InitSqStack(SqStack &S,int n)
{
	S.base = new ElemType[n + 1];
	if (S.base == NULL)
		exit(OVERFLOWED);
	S.top = S.base;
	S.stacksize = n;
	return OK;
}


Status ClearStack(SqStack &S)
{
	S.stacksize = 0;
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base){
		return TRUE;
	}
	return FALSE;
}

Status StackLength(SqStack S)
{
	return S.top - S.base;
}

Status GetTop(SqStack S,ElemType &e)
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, ElemType e)
{
	if (S.top - S.base >= S.stacksize){
		return FALSE;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base){
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

Status Station()
{
	ElemType e;
	
	int i, j = 0;
	char chr[2][1000] = { 0 };
	SqStack S;
	InitSqStack(S);
	cin.getline(chr[0], 1000);
	while (1){
		j = 0;
		memset(chr[1], 0, 1000);
		cin.getline(chr[1], 1000);
		cin.clear();
		if (chr[1][0] == 0){
			break;
		}
		for (i = 0; chr[1][i] != 0; i++){
			if (GetTop(S,e) == OK && e == chr[1][i]){
				Pop(S,e);
			}
			else{
				while (chr[0][j] != chr[1][i]){
					Push(S,chr[0][j]);
					j++;
				}
				j++;
			}
		}
		if (i == j && StackEmpty(S)){
			cout << "yes" << endl;
		}
		else{
			cout << "no"<<endl;
		}
		while (!StackEmpty(S))
		{
			Pop(S,e);
		}
	}
	ClearStack(S);
	return OK;
}

int main()
{
	Station();
	return 0;
}