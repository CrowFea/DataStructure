#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iomanip>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       -968
#define INFEASIBLE  -1
#define OVERFLOWED   -2
#define MAXSIZE   1000000

typedef char  Status;
typedef char ElemType;
typedef int ElemType1;

typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;

typedef struct {
	ElemType1 *base;
	ElemType1  *top;
	int  stacksize;
}NuStack;

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
Status InitStack(NuStack &S)
{
	S.base = (ElemType1*)malloc(MAXSIZE * sizeof(ElemType1));
	if (!S.base) {
		exit(OVERFLOWED);
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
Status Push(NuStack &S, ElemType1 &e)
{
	if (S.top - S.base >= S.stacksize) {//Õ»Âú£¬×·¼Ó¿Õ¼ä
		S.base = (ElemType1 *)realloc(S.base, (S.stacksize + MAXSIZE) * sizeof(ElemType1));
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
	if (S.top == S.base) {
		return ERROR;
	}
	else {
		S.top--;
		
		return OK;
	}
}
Status Pop(NuStack &S)
{
	if (S.top == S.base) {
		return ERROR;
	}
	else {
		S.top--;

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
Status StackEmpty(NuStack S)
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
	if (S.top == S.base)
		return FALSE;
	else {
		e = *(S.top - 1);
	}
	return e;
}
Status GetTop(NuStack S)
{
	ElemType1 e;
	if (S.top == S.base)
		return FALSE;
	else {
		e = *(S.top - 1);
	}
	return e;
}

int Piroty(char ch)
{
	int e=0;
	switch (ch) {
	case '+': e = 1; break;
	case '-': e = 1; break;
	case '*': e = 2; break;
	case '/': e = 2; break;
	case '(': e = 0; break;
	case ')': e = 0; break;
	}
	return e;
}

int cal_Single(int m,int n,char ch)
{
	
	int e=0;
	if (ch == '/') {
		if (n == 0) {
			cout << "ERROR" << endl;
			return ERROR;
		}
	}
	switch (ch) {
	case '+': e = m+n; break;
	case '-': e = m - n; break;
	case '*': e = m*n; break;
	case '/': e = m/n; break;
	}
	
	return e;
}

int calculate(NuStack &S1, SqStack &S2)
{
	string str;
	char ch;
	int i = 0;
	cin >> str;
	bool sign = false, num = false;
	int neg = 0;
	int  j,e;
	int size = str.size();
	char tmp_operation;
	string tmp_num;
	while (i < size) {
		if (str[i] == '=') {
			break;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			num = true;
			sign = false;
			j = i;
			while (j < size && str[j] >= '0' && str[j] <= '9') { j++; }
			tmp_num = str.substr(i, j - i);
			int num = atoi(tmp_num.c_str());
			if (neg) {
				while (neg) {
					num *= -1;
					neg--;
				}
			}
			Push(S1,num);
			i = j;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (sign) {
				if ((str[i] == '*' || str[i] == '/')) {
					cout << "ERROR" << endl;
					return ERROR;
				}
				if (str[i] == '-') {
					neg ++;
					i++;
					continue;
				}
			}
			sign = true;
			num = false;
			if (StackEmpty(S2)) {
				Push(S2,str[i]);
			}
			else {
				while (!StackEmpty(S2)) {
					tmp_operation = GetTop(S2);
					if (Piroty(tmp_operation) >= Piroty(str[i])) {
						int m, n;
						n = GetTop(S1);
						Pop(S1);
						m = GetTop(S1);
						Pop(S1);
						ch = GetTop(S2);
						e=cal_Single(m, n,ch);
						if (e == ERROR) {
							return ERROR;
						}
						Push(S1, e);
						Pop(S2);
					}
					else {
						break;
					}
				}
				Push(S2,str[i]);
			}
			i++;
		}
		else {
			if (str[i] == '(') {
				Push(S2,str[i]);
			}
			else if(str[i] == ')'){
				int count = 0;
				if (count == 0) {
					if (GetTop(S2) == '(') {
						cout << "ERROR" << endl;
						return ERROR;
					}
					count++;
				}
				while (GetTop(S2) != '(') {
					tmp_operation = GetTop(S2);
					int m, n;
					n = GetTop(S1);
					Pop(S1);
					m = GetTop(S1);
					Pop(S1);
					ch = GetTop(S2);
					e = cal_Single(m, n, ch);
					if (e == ERROR) {
						return ERROR;
					}
					Push(S1, e);
					Pop(S2);
				}
				Pop(S2);
			}
			else {
				cout << "ERROR" << endl;
				return ERROR;
			}
			i++;
		}

	}
	while (!StackEmpty(S2)) {
		tmp_operation = GetTop(S2);
		int m, n;
		n = GetTop(S1);
		Pop(S1);
		m = GetTop(S1);
		Pop(S1);
		ch = GetTop(S2);
		e = cal_Single(m, n, ch);
		if (e == ERROR) {
			return ERROR;
		}
		Push(S1, e);
		Pop(S2);
	}
	return GetTop(S1);
}

int main()
{
	NuStack S1;
	SqStack S2;
	InitStack(S1);
	InitStack(S2);
	int t = calculate(S1, S2);
	if (t != ERROR) {
		cout << t << endl;
	}
	return 0;
}