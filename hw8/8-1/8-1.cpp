#include <iostream>
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
typedef char ElemType;

typedef struct Node{
	ElemType data;
	struct Node *lchild, *rchild;
}*BiTree, BiTNode;

void CreateBiTree(BiTree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return;
}

void InOrderTraverse(BiTree T)
{
	if (T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
	
}

void PreOrderTraverse(BiTree T)
{
	if (T){
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	
}

void PostOrderTraverse(BiTree T)
{
	if (T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
	
}

void LevelOrderTraverse(BiTree T)
{
	int front, rear;
	BiTNode *que[MAXSIZE];
	front = rear = 0;
	BiTNode *q;
	if (T){
		rear = (rear + 1) % MAXSIZE;
		que[rear] = T;
		while (front != rear){
			front = (front + 1) % MAXSIZE;
			q = que[front];
			cout << q->data;
			if (q->lchild != 0){
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->lchild;
			}
			if (q->rchild != 0){
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->rchild;
			}
		}
	}
	cout << endl;
	return;
}

void TreePrint(BiTree T,int level)
{
	int i;
	if (!T){
		return;
	}
	TreePrint(T->rchild, level + 1);	
	for (i = 0; i<level; i++){
		cout<<"     ";
	}
	cout<<T->data<<endl;	
	TreePrint(T->lchild, level + 1);	
}


int Depth(BiTree T)
{
	if (T == NULL)
		return 0;
	else{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m>n) return (m + 1);
		else return (n + 1);
	}
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	cout << endl;
	InOrderTraverse(T);
	cout << endl;
	PostOrderTraverse(T);
	cout << endl;
	LevelOrderTraverse(T);
	int level = 0;
	TreePrint(T, level);
	
	return 0;
}