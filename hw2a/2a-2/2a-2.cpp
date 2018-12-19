#include<iostream>
#include<string>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2
#define MAXSIZE 100

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
		return ERROR;
	}
	ElemType *p;
	p = S.top;
	while (p > S.base) {
		p--;
		cout << *p;
	}
	cout << endl;
	return OK;
}


typedef struct{
	ElemType weight;
	ElemType parent;
	ElemType Child;
} Node, *HuffmanTree;


typedef char *HuffmanCode;

void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
{
	int m = 2 * n - 1;
	int i;
	*huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
	for (i = 1; i <= m; i++){
		cin>>(*huffmanTree)[i].weight;
		cin >> (*huffmanTree)[i].parent;
		cin>>(*huffmanTree)[i].Child;
	}

	return;
}

void creatHuffmanCode2(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
{
	int i;
	int temp;
	int p;
	

	for (i = 1; i <= n; i++) {
		SqStack S;
		InitStack(S);
		//cout << i << " ";
		for (p = i; (*huffmanTree)[p].parent != 0;p = (*huffmanTree)[p].parent) {
			if ((*huffmanTree)[p].Child == 0) {
				temp = 0;

			}
			else {
				temp = 1;
			}
			Push(S, temp);
		}
		cout << i << " ";
		ReadAll(S);
		//cout << endl;
	}

	
	return;
}

int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n ;

	cin >> n;

	w = (int *)malloc((n + 1) * sizeof(int));


	createHuffmanTree(&HT, w, n);
	creatHuffmanCode2(&HT, &HC, n);

	return 0;
}