#include<iostream>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOWED   -2

typedef int  Status;

#define LIST_INIT_SIZE  1000000
#define LISTINCREMENT   10
typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L1, ElemType &e);
void ListPrint_Sq(SqList L);


Status InitList_Sq(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOWED);
	L.listsize = LIST_INIT_SIZE;
	L.length = 0;
	return OK;
}

Status ListInsert_Sq(SqList &L, int pos, ElemType e)
{
	ElemType *newbase;

	if (L.length >= L.listsize) {
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			return ERROR;
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;

	}
	//ElemType *p, *q;
	L.elem[L.length] = e;
	++L.length;
	return OK;

}

Status ListDelete_Sq(SqList &L1, ElemType &e)
{
	int i = 0, j = 0;
	for (i = 0; i < L1.length; i++) {
		if (L1.elem[i] != e) {
			L1.elem[j] = L1.elem[i];
			j++;
		}
	}
	L1.length -= (i - j);
	if (i == j) {
		return 0;
	}
	return 1;
}

void ListPrint_Sq(SqList L)
{
	if (L.length <= 0) {
		return;
	}
	for (int i = 0; i <= L.length - 2; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("%d\n", L.elem[L.length - 1]);

}


int main() {
	SqList L1;
	if (InitList_Sq(L1) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}

	int n, i, input;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> input;
		ListInsert_Sq(L1, i, input);
	}
	//ListPrint_Sq(L);

	ElemType elem1;
	cin >> elem1;
	if (ListDelete_Sq(L1, elem1) == 1) {
		ListPrint_Sq(L1);
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}