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

typedef struct LNode{
	ElemType val;
	struct LNode * next;
	LNode(int x) :val(x), next(nullptr) {}
}LNode,*LinkList;

Status getLength(LinkList L);

void initial(LinkList &L,int n)
{
	LNode *p;
	L = new LNode(0);
	int i;
	for (i = n; i > 0; i--) {
		p = new LNode(0);
		if (!p) {
			exit(0);
		}
		cin >> p->val;
		p->next = L->next;
		L->next = p;
	}
	
	return ;
}

Status insert(LinkList &L, int pos, ElemType target)
{
	if (pos > getLength(L)+1) {
		return INFEASIBLE;
	}
	int count = 0;
	LNode *head,*p=nullptr;
	head = L;
	if (head->next) {
		p = head->next;
	}
	if (pos <= 0) {
		return INFEASIBLE;
	}
	while (head) {
		count++;
		if (count == pos) {
			head->next = (LinkList)malloc(sizeof(LNode));
			head = head->next;
			head->val = target;
			if (p) {
				head->next = p;
			}
			else {
				head->next = nullptr;
			}
			return OK;
		}
		head = head->next;
		if (count>getLength(L)) {
			head->next = nullptr;
			return INFEASIBLE;
		}
		if (p->next) {
			p = p->next;
		}
		else {
			p->next = nullptr;
			p = p->next;
		}
	}
	return INFEASIBLE;
}

Status delete_LinkList(LinkList &L, int pos)
{
	if (pos > getLength(L)) {
		return INFEASIBLE;
	}

	LNode *head;
	head = L;
	LNode *p;
	p = L->next;
	int count = 0;
	while (head) {
		count++;
		if (count == pos) {
			LNode *q;
			q = p;
			if (p) {
				p = p->next;
				head->next = p;
			}
			else {
				head->next = nullptr;
				free (p);
			}
			free(q);
			return OK;
		}
		head = head->next;
		if (!head) {
			return INFEASIBLE;
		}
		if (p->next) {
			p = p->next;
		}
		else {
			p->next = nullptr;
		}
	}
	return INFEASIBLE;
}

Status locate(LinkList L, int target)
{
	LNode *head;
	head = L;
	int count = 0;
	while (head) {
		if (head->val == target) {
			return count;
		}
		head = head->next;
		count++;
	}
	return INFEASIBLE;
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
		cout << head->val << " " ;
		head = head->next;
	}
	cout << endl;
	return;
}

int main()
{
	LinkList L;
	int pos,target, n;
	cin >> n;
	initial(L, n);


	print_LinkList(L);
	cin >> pos >> target;
	if (insert(L, pos, target) == OK) {
		print_LinkList(L);
	}
	else {
		cout << INFEASIBLE << endl;
	}
	cin >> pos;
	if (delete_LinkList(L,pos) == OK) {
		print_LinkList(L);
	}
	else {
		cout << INFEASIBLE << endl;
	}
	cin >> target;
	
	cout<<locate(L,target)<<endl;

	cout << getLength(L) << endl;
	return 0;
}