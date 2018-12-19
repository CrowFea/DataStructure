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

typedef struct ListNode{
	ElemType val;
	ListNode *next;
	ListNode(int x) :val(x),next(nullptr) {}
}ListNode,*LinkList ;

void creat(ListNode *L,int n)
{
	ListNode *p; 	
	L = new ListNode(0);
	int i;
	for (i = n; i > 0; i--) {
		p = new ListNode(0);
		if (!p)			
			exit(0);		
		cin >> p->val;
		p->next = L->next;		
		L->next = p;				
	}
}


void printList(ListNode *head){
	if (head->next == nullptr){
		cout << INFEASIBLE << endl;
		return;
	}
	ListNode *p = head->next;
	int i = 0;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}


ElemType getListLength(ListNode *head){
	int len = 0;
	ListNode *p = head->next;
	while (p != nullptr)
	{
		++len;
		p = p->next;

	}
	return len;
}


ListNode *insertList(ListNode *head, int pos, ElemType data)
{
	ListNode *newNode = new ListNode(data);

	ListNode *p = head;
	int i = 1;
	while (p != nullptr&&i<pos){
		p = p->next;
		++i;
	}
	newNode->next = p->next;
	p->next = newNode;
	return head;
}

ListNode *deleteNode(ListNode *head, int pos)
{
	ListNode *p = head;
	if (p->next == nullptr){
		cout << INFEASIBLE << endl;
		return nullptr;
	}
	ListNode *node = nullptr;
	int i = 1;
	bool flag = false;
	while (p != nullptr&&i<pos){
		p = p->next;
		++i ;
	}
	if (p != nullptr&&p->next != nullptr){
		node = p->next;
		p->next = node->next;
		delete node;
		flag = true;
	}
	if (!flag) {
		cout << INFEASIBLE << endl;
	}
	return head;
}


int main()
{
	ListNode *head = new ListNode(0);
	int n;
	cin >> n;
	creat(head,n);
	//printList(head);
	int pos, target;
	cin >> pos >> target;
	insertList(head, pos, target);
	printList(head);
	cin >> pos;
	deleteNode(head, pos);
	printList(head);

	return 0;


}
*/