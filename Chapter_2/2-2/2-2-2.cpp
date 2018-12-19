#include<iostream>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

#define LIST_INIT_SIZE  10000
#define LISTINCREMENT   10
typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}Ordered_list;

Status InitList_sq(Ordered_list &L) {
	L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_sq(Ordered_list &L, int i, int e) 
{
	if (i<1 || i>L.length + 1) {
		return ERROR;
	}
	if (L.length >= L.listsize) {
		int *newbase;
		newbase = (int*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *q, *p;
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete_sq(Ordered_list &L, int i, int &e)
{
	if (i<1 || i>L.length) {
		return ERROR;
	}
	int *p, *q;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}
	--L.length;
	return OK;
}

Status ListLocate_sq(Ordered_list L, int y) 
{
	int i = 1;
	while (i <= L.length&&L.elem[i - 1] != y) {
		i++;
	}
	if (L.elem[i - 1] == y && i - 1<L.length) {
		return i;
	}
	else {
		return -1;
	}
}

Status ListFind_sq(Ordered_list L, int e) 
{
	int low = 0, high = L.length - 1;
	if (L.elem[high]<e) {
		return(high + 2);
	}
	if (L.elem[high] == e) {
		return(high + 1);
	}
	if (L.elem[low] >= e) {
		return(low + 1);
	}
	int mid = (low + high) / 2;
	while (low != high) {
		if (L.elem[mid]>e) {
			high = mid - 1;
		}
		else {
			low = mid;
		}
		mid = (low + high) / 2;
		if (low == high - 1) {
			break;
		}
	}
	int temp = high;
	if (L.elem[high] == e) {
		return(temp + 1);
	}
	if (L.elem[high]<e) {
		return(temp + 2);
	}
	if (L.elem[0] == e) {
		return(1);
	}
	while (L.elem[temp] >= e) {
		temp--;
	}
	return (temp + 2);
}

void PrintList_sq(int flag, Ordered_list L) 
{
	if (flag <= 0) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i<L.length; i++) {
		cout << L.elem[i] << " ";
	}
	cout << endl;
}

int main() {
	bool first = true;
	Ordered_list L;
	InitList_sq(L);
	int num = 0;
	int place;
	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		if (first) {
			ListInsert_sq(L, L.length + 1, num);
			first = FALSE;
		}
		else {
			place = ListFind_sq(L, num);
			ListInsert_sq(L, place, num);
		}
	}
	cin >> num;
	place = ListFind_sq(L, num);
	cout << place << endl;
	ListInsert_sq(L, place, num);
	cin >> num;
	place = ListLocate_sq(L, num);
	cout << place << endl;
	if (place != -1) {
		ListDelete_sq(L, place, num);
	}
	PrintList_sq(1, L);
	return 0;
}
