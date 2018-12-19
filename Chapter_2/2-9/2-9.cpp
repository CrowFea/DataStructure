/*
#include<iostream>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2

typedef int  Status;

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;

typedef struct LNode {
	ElemType val;
	struct LNode * next;
	LNode(int x) :val(x), next(nullptr) {}
}LNode, *LinkList;

Status getLength(LinkList L);

void initial_ordered(LinkList &L)
{
	LNode *p, *q;
	L = new LNode(0);
	q = L;
	int num;
	while(1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		p = new LNode(0);
		p->val = num;;
		q->next = p;
		q = p;
	}
	q->next = nullptr;
	return;
}


Status getLength(LinkList L)
{
	LNode *head;
	head = L->next;
	int count = 0;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}

void print_LinkList(LinkList L)
{
	LNode *head;
	head = L;
	head = head->next;
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

void insert(LinkList L, ElemType target)
{
	LNode *head, *p;
	head = L->next;
	p = L;
	while (head) {
		if (target < head->val) {
			p->next = new LNode(target);
			p = p->next;
			p->next = head;
			return;
		}
		head = head->next;
		p = p->next;
	}
	p->next = new LNode(0);
	p = p->next;
	p->val = target;
	p->next = nullptr;
}

void Merge(LinkList L1, LinkList L2, LinkList L3)
{
	LNode *p, *q,*t;
	p = L1->next;
	q = L2->next;
	t = L3;

	while (p&&q) {
		if (p->val < q->val) {
			t->next = new LNode(0);
			t = t->next;
			t->val = p->val;
			p = p->next;
		}
		else {
			t->next = new LNode(0);
			t = t->next;
			t->val = q->val;
			q = q->next;
		}
	}

	if (q) {
		while (q) {
			insert(L3, q->val);
			q = q->next;
		}
	}
	if (p) {
		while (p) {
			insert(L3, p->val);
			p= p->next;
		}
	}
}

int main()
{
	LinkList L1, L2, L3;
	initial_ordered(L1);
	initial_ordered(L2);
	L3 = new LNode(0);
	Merge(L1, L2, L3);
	print_LinkList(L3);
	return 0;
}*/