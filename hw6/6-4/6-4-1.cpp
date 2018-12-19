#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

#define STACK_INIT_SIZE 100000
#define STACKINCREMENT  100
#define OVERFLOWED -1
#define OK 1
#define ERROR 0
#define MAXSIZE   1000000

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
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

Status GetTop(SqStack S, ElemType &e) {
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

Status Count(SqStack S) {
	return(S.top - S.base);
}

Status Push(SqStack &S, ElemType e, int max) {
	if (Count(S) >= max) {
		return ERROR;
	}
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S.base) {
			return OVERFLOWED;
		}
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, ElemType &e) {
	if (S.top == S.base) 
		return ERROR;
	e = *(--S.top);
	return OK;
}

bool compare(int a, int b) {
	if (a == '*' || a == '/') {
		if (b == '*' || b == '/') {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

Status Trans(char str[],int arr2[],int arr1[],SqStack &S)
{
	int len = strlen(str);
	int i,t,tx,len1 = 0;
	bool flag = true;
	for (i = 0; i < len - 1; i++) {
		tx = str[i];
		if (tx >= '0'&&tx <= '9')
			if (i > 0 && str[i - 1] >= '0'&&str[i - 1] <= '9') {
				arr2[len1 - 1] = arr2[len1 - 1] * 10 + str[i] - '0';
			}
			else {
				arr2[len1++] = str[i] - '0';
			}
		else if (tx != '+'&&tx != '-'&&tx != '*'&&tx != '/'&&tx != '('&&tx != ')') {
			printf("ERROR");
			flag = false;
			break;
		}
		else {
			if (Count(S) == 0 || tx == '(') Push(S, tx, 1000000);
			else if (tx == ')') {
				t = 0;
				while (t != '(') {
					Pop(S, t);
					if (t != '(') {
						arr1[len1] = 1;
						arr2[len1++] = t;
					}
				}
			}
			else {
				t = 0;
				while (1) {
					GetTop(S, t);
					if (t == '(' || compare(tx, t) || Count(S) == 0) {
						Push(S, tx, 1000000);
						break;
					}
					else {
						Pop(S, t);
						arr1[len1] = 1;
						arr2[len1++] = t;
					}
				}
			}
		}
	}

	for (i = 0; i <= Count(S); i++) {
		Pop(S, t);
		arr1[len1] = 1;
		arr2[len1++] = t;
	}

	int sum = 0, x, y;
	for (i = 0; i < len1; i++) {
		if (flag == false) break;
		if (arr1[i] == 0) {
			Push(S, arr2[i], 100000);
		}
		else {
			Pop(S, y);
			Pop(S, x);
			switch (arr2[i]) {
			case'+':
				sum = x + y;
				Push(S, sum, 100000);
				break;
			case'-':
				sum = x - y;
				Push(S, sum, 100000);
				break;
			case'*':
				sum = x * y;
				Push(S, sum, 100000);
				break;
			case'/':
				if (y == 0) {
					cout << "ERROR" << endl;
					flag = false;
				}
				else {
					sum = x / y;
					Push(S, sum, 100000);
				}
				break;
			default: break;
			}
		}
	}
	Pop(S, sum);
	if (flag == true) {
		cout << sum << endl;
	}
}

int main() {
	SqStack S;
	InitStack(S);
	char str[MAXSIZE];
	int arr2[MAXSIZE];
	int arr1[MAXSIZE];
	int i;
	for (i = 0; i <= MAXSIZE; i++) {
		arr1[i] = 0;
	}
	int t = 0;
	cin>> str;
	Trans(str, arr2, arr1, S);
	return 0;
}
