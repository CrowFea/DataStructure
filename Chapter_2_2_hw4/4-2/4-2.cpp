#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2

typedef int  Status;
typedef int ElemType;

typedef struct LNode {
	ElemType coef;
	ElemType exp;
	struct LNode *next;
	LNode(ElemType x, ElemType y) :coef(x), exp(y), next(nullptr) {}
} LNode, *LinkList;

void initial(LinkList &L, ElemType n)
{
	LNode *p;
	L = new LNode(0, 0);
	p = L;
	while (n) {
		p->next = new LNode(0, 0);
		p = p->next;
		cin >> p->coef >> p->exp;
		n--;
	}
	p->next = nullptr;
}

void add(LinkList L1, LinkList L2, LinkList &L3)
{
	LNode *p, *p1, *p2;
	L3 = new LNode(0, 0);
	p1 = L1->next;
	p2 = L2->next;
	p = L3;

	while (p1 && p2) {
		if (p1->exp > p2->exp) {

			p->next = new LNode(p2->coef, p2->exp);
			p = p->next;
			p2 = p2->next;
		}
		else if (p1->exp < p2->exp) {

			p->next = new LNode(p1->coef, p1->exp);
			p = p->next;
			p1 = p1->next;
		}
		else {

			p->next = new LNode(p1->coef + p2->coef, p1->exp);
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1) {

		p->next = new LNode(p1->coef, p1->exp);
		p = p->next;
		p1 = p1->next;
	}
	while (p2) {

		p->next = new LNode(p2->coef, p2->exp);
		p = p->next;
		p2 = p2->next;
	}
}

void mutiply(LinkList L1, LinkList L2, LinkList &L3)
{
	LNode *p, *p1, *p2,*t;
	
	L3 = new LNode(0, 0);

	p = L3;
	p1 = L1->next;
	p2 = L2->next;

	while (p1) {
		LinkList Lt;
		Lt = new LNode(0, 0);
		t = Lt;
		while (p2) {
			t->next = new LNode(p1->coef*p2->coef, p1->exp+p2->exp);
			t = t->next;
			p2 = p2->next;
		}
		p2 = L2->next;
		add(Lt, L3, L3);
		p1 = p1->next;
	}

}

void print(LinkList L)
{
	LNode *p;
	p = L->next;
	if (!p){
		printf("0 0");
	}
	else{
		while (p){
			cout << p->coef << " " << p->exp << endl;
			p = p->next;
		}
	}
	return;
}

int main()
{
	LinkList L1, L2, L3;
	int n;
	cin >> n;
	initial(L1, n);
	cin >> n;
	initial(L2, n);

	mutiply(L1, L2,L3);
	print(L3);

	return 0;
}
