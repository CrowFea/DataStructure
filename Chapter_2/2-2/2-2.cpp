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
	if (e <= L.elem[0]) {
		p = &(L.elem[0]);
		for (q = &(L.elem[L.length - 1]); q >= p; --q) {
			*(q + 1) = *q;
		}
		*p = e;
		++L.length;
		pos = 1;
		return pos;
	}
	if (e >= L.elem[L.length - 1]) {
		p = &(L.elem[L.length]);
		*p = e;
		++L.length;
		pos = L.length;
		return pos;
	}
	int  high = L.length - 1, low = 0;
	int mid = (low + high) / 2;
	while (high - low > 0) {
		if (e > L.elem[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
		if (mid == high || mid == low) {
			break;
		}
	}
	p = &(L.elem[mid + 1]);
	for (q = &(L.elem[L.length - 1]); q >= p; --q) {
		*(q + 1) = *q;
	}
	*p = e;
	++L.length;
	pos = mid + 2;
	return pos;
}

Status ListDelete_Sq(Ordered_list &L, ElemType &e)
{
	int pos;
	int mid, high = L.length - 1, low = 0;
	if (e == L.elem[low]) {
		pos = 1;
		ElemType *q;
		e = L.elem[pos - 1];
		for (q = &(L.elem[pos - 1]); q <= L.elem+L.length-1; ++q) {
			*q = *(q + 1);
		}
		L.length = L.length - 1;
		return pos;
	}
	if (e == L.elem[high]) {
		pos = L.length;
		ElemType *q;
		e = L.elem[pos - 1];
		for (q = &(L.elem[pos - 1]); q <= L.elem + L.length - 1; ++q) {
			*q = *(q + 1);
		}
		L.length = L.length - 1;
		return pos;
	}
	while (high - low > 0) {
		mid = (high + low) / 2;
		if (e == L.elem[mid]) {
			pos = mid + 1;
			break;
		}
		if (e > L.elem[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
		if (mid == high || mid == low) {
			return -1;
		}
	}
	ElemType *q;
	e = L.elem[pos - 1];
	for (q = &(L.elem[pos - 1]); q <= L.elem + L.length - 1; ++q) {
		*q = *(q + 1);
	}
	L.length = L.length - 1;
	return pos;

}

void ListPrint_Sq(Ordered_list L)
{
	if (L.length <= 0) {
		cout << endl;
		return;
	}
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