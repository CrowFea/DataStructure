
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
	while (1) {
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

void qsortList(LNode *headPre, LNode*head, LNode*tail);
LNode* partitionList(LNode* lowPre, LNode* low, LNode* high);

LNode *quickSortList(LNode *head) 
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	LNode tmpHead(0); 
	tmpHead.next = head;
	qsortList(&tmpHead, head, NULL);
	return tmpHead.next;
}
void qsortList(LNode *headPre, LNode*head, LNode*tail)
{
	if (head != tail && head->next != tail)	{
		LNode* mid = partitionList(headPre, head, tail);
		qsortList(headPre, headPre->next, mid);
		qsortList(mid, mid->next, tail);
	}
}
LNode* partitionList(LNode* lowPre, LNode* low, LNode* high)
{
	int key = low->val;
	LNode node1(0), node2(0);
	LNode* little = &node1, *big = &node2;
	for (LNode*i = low->next; i != high; i = i->next) {
		if (i->val < key) {
			little->next = i;
			little = i;
		}
		else {
			big->next = i;
			big = i;
		}
	}
	big->next = high;
	little->next = low;
	low->next = node2.next;
	lowPre->next = node1.next;
	return low;
}

void Merge(LinkList L1, LinkList L2, LinkList L3)
{
	LNode *p, *q, *t;
	p = L1->next;
	q = L2->next;
	t = L3;
	t->next = L1->next;
	while (t->next) {
		t = t->next;
	}
	t->next = L2->next;
}

int main()
{
	LinkList L1, L2, L3;
	initial_ordered(L1);
	initial_ordered(L2);
	L3 = new LNode(0);
	Merge(L1, L2, L3);
	L3 = quickSortList(L3);
	print_LinkList(L3);
	return 0;
}