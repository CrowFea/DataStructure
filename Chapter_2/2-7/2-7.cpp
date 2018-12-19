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
	LNode *p,*q;
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

LNode *reverse(LNode *head)
{
	if (head->next == nullptr&&head->next->next == nullptr) {
		return head;
	}
	LNode *tail = head->next;
	LNode *p = tail->next;
	while (p != nullptr){
		tail->next = p->next;
		p->next = head->next;
		head->next = p;
		p = tail->next;
	}
	return head;
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

void print_LinkList_3(LinkList L)
{
	LNode *head;
	head = L;
	head = head->next;
	while (head) {
		if (head->val % 3 == 0) {
			cout << head->val << " ";
		}
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
	LNode *p;
	p = reverse(L);
	print_LinkList(p);
	p = reverse(L);
	print_LinkList_3(p);
	return 0;
}