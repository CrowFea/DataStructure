
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
Status Merge_Sq(Ordered_list &L1, Ordered_list &L2, Ordered_list &L3);
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

Status Merge_Sq(Ordered_list &L1, Ordered_list &L2, Ordered_list &L3)
{
	int i=0, j=0;
	while (i != L1.length&&j != L2.length) {
		if (L1.elem[i] < L2.elem[j]) {
			L3.elem[i + j] = L1.elem[i];
			L3.length++;
			i++;
		}
		else {
			L3.elem[i + j] = L2.elem[j];
			j++;
			L3.length++;
		}
	}
	if (i == L1.length&&j == L2.length) {
		return 0;
	}
	if (i == L1.length) {
		for (; j < L2.length; j++) {
			L3.elem[i + j] = L2.elem[j];
			L3.length++;
		}
	}
	else {
		for (; i < L1.length; i++) {
			L3.elem[i + j] = L1.elem[i];
			L3.length++;
		}
	}
	return 0;
}

void ListPrint_Sq(Ordered_list L)
{
	for (int i = 0; i <= L.length - 2; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("%d\n", L.elem[L.length - 1]);

}

int main() {
	Ordered_list L1,L2,L3;
	if (InitList_Sq(L1) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}
	int input;
	for (; ; ) {
		cin >> input;
		if (input == 0) {
			break;
		}
		ListInsert_Sq(L1, input);
	}
	//ListPrint_Sq(L1);
	if (InitList_Sq(L2) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}
	for (; ; ) {
		cin >> input;
		if (input == 0) {
			break;
		}
		ListInsert_Sq(L2, input);
	}
	//ListPrint_Sq(L2);
	if (InitList_Sq(L3) != OK) {
		printf("InitList_Sq: ³õÊ¼»¯Ê§°Ü£¡£¡£¡\n");
		return -1;
	}

	Merge_Sq(L1, L2, L3);

	ListPrint_Sq(L3);

	return 0;
}


