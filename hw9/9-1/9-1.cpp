/*
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
#define LINK 0
#define THREAD 1

typedef int  Status;
typedef char ElemType;

typedef struct Node {
	ElemType data;
	struct Node *lchild, *rchild;
	int ltag, rtag;
}*ThrBiTree, ThrBiTNode;

void CreateThrBiTree(ThrBiTree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new ThrBiTNode;
		T->data = ch;
		T->ltag = LINK;
		T->rtag = LINK;
		CreateThrBiTree(T->lchild);
		CreateThrBiTree(T->rchild);
	}
	return;
}

void TreePrint(ThrBiTree T, int level)
{
	int i;
	if (!T) {
		return;
	}
	if (T->rtag == LINK) {
		TreePrint(T->rchild, level + 1);
	}
	for (i = 0; i<level; i++) {
		cout << "     ";
	}
	cout << T->data <<T->ltag<<T->rtag<< endl;
	if(T->ltag==LINK)
		TreePrint(T->lchild, level + 1);
}

void _PreOrderThread(ThrBiTree &T, ThrBiTNode *prev)
{
	if (T == NULL){
		return;
	}
	if (T->lchild == NULL){
		T->lchild = prev;
		T->ltag = THREAD;
	}
	if (prev != NULL && prev->rchild == NULL){ 
		prev->rchild = T;
		prev->rtag = THREAD;
	}
	if (T->rchild == NULL) {
		T->rtag = THREAD;
	}
	prev = T;

	if (T->ltag == LINK) {
		_PreOrderThread(T->lchild, prev);
	}
	if (T->rtag == LINK) {
		_PreOrderThread(T->rchild, prev);
	}
}

void _PreOrder(ThrBiTree &T)
{
	if (T == NULL)
	{
		return;
	}
	ThrBiTNode* pCur = T;
	while (pCur != NULL){
		while (pCur->lchild != NULL && pCur->ltag == LINK){
			cout << pCur->data;
			pCur = pCur->lchild;
		}
		cout << pCur->data ;

		if (pCur->ltag == THREAD){
			pCur = pCur->rchild;
		}
		while (pCur != NULL){
			if (pCur->lchild != NULL && pCur->ltag == LINK){
				break;
			}
			cout << pCur->data;
			pCur = pCur->rchild;
		}
	}
	cout << endl;
}

int main()
{
	ThrBiTree T;

	CreateThrBiTree(T);
	ThrBiTNode *prev = NULL;
	_PreOrderThread(T,prev);
	_PreOrder(T);
	TreePrint(T,0);
	return 0;
}
*/