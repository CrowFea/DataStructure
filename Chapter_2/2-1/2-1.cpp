#include<iostream>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOWED   -2

typedef int  Status;

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType; 

typedef struct {
	ElemType* elem;   
	int length;       
	int listsize;     
}SqList;

Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
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
	if (pos >= 1 && pos <= L.length + 1){
		if (L.length >= L.listsize){
			newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
			if (!newbase) {
				return ERROR;
			}
			L.elem = newbase;
			L.listsize += LISTINCREMENT;

		}
		ElemType *p, *q;
		p = &(L.elem[pos - 1]);
		for (q = &(L.elem[L.length - 1]); q >= p; --q){
			*(q + 1) = *q;
		}
		*p = e;
		++L.length;
		return OK;
	}
	else {
		return OVERFLOWED;
	}
}

Status ListDelete_Sq(SqList &L, int pos, ElemType &e)
{
	if (pos >= 1 && pos <= L.length){
		ElemType *q;
		e = L.elem[pos - 1];
		for (q = &(L.elem[pos - 1]); q <= &(L.elem[L.length - 1]); ++q){
			*q = *(q + 1);
		}
		L.length = L.length - 1;
		return OK;
	}
	else {
		return OVERFLOWED;
	}
}

int ListLocate_Sq(SqList L, ElemType e)
{
	int a = -1;
	for (int i = 0; i <= L.length - 1; i++){
		if (L.elem[i] == e){
			a = i;
			break;
		}
	}
	if (a >= 0 && a <= L.length - 1) {
		return a + 1;
	}
	else {
		return ERROR;
	}
}

void ListPrint_Sq(SqList L)
{
	for (int i = 0; i <= L.length - 2; i++){
		printf("%d ", L.elem[i]);
	}
	printf("%d\n", L.elem[L.length - 1]);

}


int main() {
	SqList L;
	if (InitList_Sq(L) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}
	int n, i, input;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> input;
		ListInsert_Sq(L, i, input);
	}
	ListPrint_Sq(L);
	int pos, elem;
	cin >> pos >> elem;
	if (ListInsert_Sq(L, pos, elem) == 1) {
		ListPrint_Sq(L);
	}
	else {
		cout << -1 << endl;
	}

	ElemType elem1;
	cin >> pos;
	if (ListDelete_Sq(L, pos, elem1) == 1) {
		ListPrint_Sq(L);
	}
	else {
		cout << -1 << endl;
	}
	cin >> elem1;
	pos = ListLocate_Sq(L, elem1);
	if (pos >= 1 && pos <= L.length)
		cout << pos << endl;
	else
		cout << -1 << endl;
	return 0;
}


