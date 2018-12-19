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
#define MAXSIZE   1000000

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
		cout << "Stack is Empty" << endl;
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
		return ERROR;
	}
	else {
		return TRUE;
	}
}

Status GetTop(SqStack S)
{
	ElemType e;
	if (S.top == S.base)
		return FALSE;
	else {
		e = *(S.top - 1);
	}
	return e;
}

void Match()
{
	char ch,res,e;
	bool find = false;
	SqStack S;
	InitStack(S);
	while ((ch = getchar()) != EOF) {
		if (ch == '(' || ch == '{' || ch == '[') {
			Push(S, ch);
			continue;
		}
		if (ch == ')') {
			if (StackEmpty(S)) {
				e = GetTop(S);
				if (e == '(') {
					Pop(S);
					continue;
				}
				else {
					if (!find) {
						res = e;
						find = true;
						continue;
					}
				}
			}
			else {
				if (!find) {
					res = ch;
					find = true;
					continue;
				}
			}
		}
		if (ch == ']') {
			if (StackEmpty(S)) {
				e = GetTop(S);
				if (e == '[') {
					Pop(S);
					continue;
				}
				else {
					if (!find) {
						res = e;
						find = true;
						continue;
					}
				}
			}
			else {
				if (!find) {
					res = ch;
					find = true;
					continue;
				}
			}
		}
		if (ch == '}') {
			if (StackEmpty(S)) {
				e = GetTop(S);
				if (e == '{') {
					Pop(S);
					continue;
				}
				else {
					if (!find) {
						res = e;
						find = true;
						continue;
					}
				}
			}
			else {
				if (!find) {
					res = ch;
					find = true;
					continue;
				}
			}
		}
	}

	if (StackEmpty(S)) {
		res = GetTop(S);
		cout << "no" << endl;
		cout << res << "ÆÚ´ýÓÒÀ¨ºÅ" << endl;
	}
	else {
		if (find) {
			cout << "no" << endl;
			cout << res << "ÆÚ´ý×óÀ¨ºÅ" << endl;
		}
		else {
			cout << "yes" << endl;
		}
	}
	return;
}

int main()
{
	Match();
	return 0;
}