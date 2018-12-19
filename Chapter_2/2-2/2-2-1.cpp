/*
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
}Ordered_list;

Status ListInsert_Sq(Ordered_list &L, ElemType e);
Status ListDelete_Sq(Ordered_list &L, ElemType &e);
void ListPrint_Sq(Ordered_list L);


Status InitList_Sq(Ordered_list &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOWED);
	L.listsize = LIST_INIT_SIZE;
	L.length = 0;
	return OK;
}

Status ListInsert_Sq(Ordered_list &L, ElemType e)
{
	ElemType *newbase;
	int pos = 0;
	if (L.length >= L.listsize) {
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			return ERROR;
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;

	}
	ElemType *p, *q;
	int i,mid=0;
	for (i = 0; i <= L.length - 1; i++) {
		if (e < L.elem[i]) {
			mid = i;
			break;
		}
	}
	if (e >= L.elem[L.length - 1]) {
		L.elem[L.length] = e;
		L.length++;
		return L.length;
	}
	p = &(L.elem[mid]);
	for (q = &(L.elem[L.length - 1]); q >= p; --q) {
		*(q + 1) = *q;
	}
	*p = e;
	++L.length;
	pos = mid + 1;
	return pos;
}

Status ListDelete_Sq(Ordered_list &L, ElemType &e)
{
	int pos=0;
	int mid=0, high = L.length - 1, low = 0;
	int i;
	for (i = 0; i < L.length ; i++) {
		if (e == L.elem[i]) {
			ElemType *q;
			for (q = &(L.elem[i]); q <= &(L.elem[L.length - 1]); ++q) {
				*q = *(q + 1);
			}
			L.length = L.length - 1;
			return i+1;
		}
	}
	return -1;

}

void ListPrint_Sq(Ordered_list L)
{
	for (int i = 0; i <= L.length - 2; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("%d\n", L.elem[L.length - 1]);

}

int main() {
	Ordered_list L;
	if (InitList_Sq(L) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}
	int input;
	for (; ; ) {
		cin >> input;
		if (input == 0) {
			break;
		}
		ListInsert_Sq(L, input);
	}
	//ListPrint_Sq(L);
	int elem;
	cin >> elem;
	cout << ListInsert_Sq(L, elem) << endl;
	//ListPrint_Sq(L);
	ElemType elem1;
	cin >> elem1;
	cout << ListDelete_Sq(L, elem1) << endl;

	ListPrint_Sq(L);

	return 0;
}
*/

