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
	for (i = n; i > 0; i--) {
		p = new LNode(0);
		cin >> p->val;
		q->next = p;
		q = p;
	}
	q->next = nullptr;
	return;
}

void delete_rep(LinkList L)
{
	LNode *head, *p,*heada;
	heada = L;
	head = L->next;
	p = L->next;
	bool flag = false;
	while (head) {
		flag = false;
		while (p != head) {
			if (p->val == head->val) {
				if (head->next != nullptr) {
					heada->next = head->next;
				}
				else {
					heada->next = nullptr;
					free(head);
					return;
				}
				flag = true;
				break;
			}
			p = p->next;
		}
		LNode *q=nullptr;
		if (flag) {
			q = head;
		}
		if (head->next != nullptr) {
			head = head->next;
			if (q) {
				free(q);
			}
		}
		else {
			return;
		}
		if (!flag) {
			heada = heada->next;
		}
		p = L->next;
	}
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



int main()
{
	LinkList L;
	int n;
	cin >> n;
	initial(L, n);
	delete_rep(L);
	print_LinkList(L);
	return 0;
}