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

void initial(LinkList &L, int n)
{
	LNode *p, *q;
	L = new LNode(0);
	q = L;
	int i;
	for (i = 1; i <=n; i++) {
		p = new LNode(0);
		p->val = i;
		q->next = p;
		q = p;
	}
	q->next = L->next;
	return;
}

void Josephus(LinkList L,int n, int s, int m)
{
	initial(L, n);
	LNode *p,*q;
	int i;
	q = L;
	p = L->next;
	bool flag = true;
	while (L->next) {
		if (flag) {
			for (i = 1; i < s; i++) {
				p = p->next;
				q = q->next;
			}
			flag = false;
		}
		for (i = 1; i < m; i++) {
			p = p->next;
			q = q->next;
		}
		if (p != q) {
			cout << p->val << " ";
			LNode *t;
			t = p;
			q->next = p->next;
			p = p->next;
			free(t);
		}
		if (p == q) {
			cout << p->val << endl;
			free(p);
			return;
		}
	}
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


int main()
{
	LinkList L;
	L = new LNode(0);
	int n,s,m;
	cin >> n>>s>>m;
	Josephus(L, n, s, m);
	

	return 0;
}