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

typedef struct QNode{
	ElemType *base; 
	int front;
	int rear;
	int QueueSize;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
	Q.base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!Q.base)
		exit(OVERFLOWED);
	Q.front = Q.rear = 0;
	Q.QueueSize = MAXSIZE;
	return OK;
}

Status InitQueue(SqQueue &Q,int n)
{
	Q.base = (ElemType *)malloc((n+1) * sizeof(ElemType));
	if (!Q.base)
		exit(OVERFLOWED);
	Q.front = Q.rear = 0;
	Q.QueueSize = n+1;
	return OK;
}

Status EnQueue(SqQueue &Q, ElemType elem)
{
	if ((Q.rear+1) % Q.QueueSize == (Q.front)) {
		return ERROR;
	}
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) % Q.QueueSize;
	return OK;
}

Status DeQueue(SqQueue &Q, ElemType &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.QueueSize;
	return OK;
}

Status PrintQueue(SqQueue &Q)
{
	int i;
	
	if (Q.front < Q.rear) {
		for (i = Q.front; i < Q.rear; ++i) {
			cout << Q.base[i] << " ";
		}
	}
	else {
		for (i = Q.front; i < Q.rear+Q.QueueSize; ++i) {
			cout << Q.base[i%Q.QueueSize] << " ";
		}
	}
	cout << endl;
	return OK;
}

int main()
{
	SqQueue Q;
	ElemType e;
	int n;
	cin >> n;
	InitQueue(Q,n);
	while (1) {
		char str[10];
		cin >> str;
		if (strcmp(str, "quit")==0) {
			PrintQueue(Q);
			break;
		}
		else if (strcmp(str, "dequeue")==0) {
			if (DeQueue(Q, e) == ERROR) {
				cout << "Queue is Empty" << endl;
				continue;
			}
			cout << e << endl;
		}
		else if(strcmp(str, "enqueue")==0){
			cin >> e;
			if (EnQueue(Q, e) == ERROR) {
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