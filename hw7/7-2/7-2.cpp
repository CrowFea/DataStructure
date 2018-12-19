#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define FULL   -2
#define MAXSIZE		10000
#define OVERFLOWED	-2

typedef int  Status;
typedef int ElemType;

typedef struct QNode {
	int data;
	QNode *next;
}QNode,*QueuePtr;
 

struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
};


Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	if (!Q.front) {
		return ERROR;
	}
	Q.front->next = NULL;
	return OK;
}

Status InitQueue(LinkQueue &Q,int n) {
	n = 1000;
	Q.front = Q.rear = new QNode;
	if (!Q.front) {
		return ERROR;
	}
	Q.front->next = NULL;
	while (n>=1) {
		Q.rear->next = new QNode;
		Q.rear = Q.rear->next;
		n--;
	}
	Q.rear = Q.front;
	return OK;
}


void DestroyQueue(LinkQueue &Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		delete (Q.front);
		Q.front = Q.rear;
	}
}


Status EmptyQueue(LinkQueue Q) 
{
	if (Q.front == Q.rear) {
		return TRUE;
	}
	return FALSE;
}

Status GetQueueLength(LinkQueue Q)
{
	int length=0;
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		p = p->next;
		length++;
	}
	return length;
}

Status EnQueue(LinkQueue &Q, int value, int n)
{
	int t = GetQueueLength(Q);
	if (n<=t) {
		return ERROR;
	}
	Q.rear->data = value;
	if (Q.rear->next) {
		Q.rear = Q.rear->next;
	}
	else {
		Q.rear = NULL;
	}
	return OK;
}


Status DeQueue(LinkQueue &Q, int &value) 
{
	if (Q.front == Q.rear) {
		return ERROR;
	}
	value = Q.front->data;
	Q.front = Q.front->next;


	return OK;
}




Status PrintQueue(LinkQueue Q) 
{
	if (Q.front == Q.rear) {
		return ERROR;
	}
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}


int main()
{
	LinkQueue Q;
	ElemType e;
	int n;
	cin >> n;
	InitQueue(Q,n);
	while (1) {
		char str[10];
		cin >> str;
		if (strcmp(str, "quit") == 0) {
			PrintQueue(Q);
			break;
		}
		else if (strcmp(str, "dequeue") == 0) {
			if (DeQueue(Q, e) == ERROR) {
				cout << "Queue is Empty" << endl;
				continue;
			}
			cout << e << endl;
		}
		else if (strcmp(str, "enqueue") == 0) {
			cin >> e;
			if (EnQueue(Q, e,n) == ERROR) {
				cout << "Queue is Full" << endl;
				continue;
			}
		}
		else {
			cin.clear();
			continue;
		}
	}

	return 0;
}