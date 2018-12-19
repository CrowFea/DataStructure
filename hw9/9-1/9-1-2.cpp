#include <iostream>
using namespace std;

#define OK 1
#define ERROR -1

typedef int  Status;
typedef char ElemType;

typedef enum {
	Link, Thread
}PointerTag;

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;


Status CreatBiThrTree(BiThrTree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else{
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!T)  
			return 0;
		T->data = ch;
		T->LTag = Link;
		T->RTag = Link;
		CreatBiThrTree(T->lchild);
		
		CreatBiThrTree(T->rchild);
	}
	return 1;
}

BiThrTree pre;
void PreThreading(BiThrTree &p) {
	if (p) {
		if (!p->lchild) {
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		if (p->LTag == Link)
			PreThreading(p->lchild);
		if (p->RTag == Link)
			PreThreading(p->rchild);
	}
}

Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T) {

	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		return ERROR;

	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;
	Thrt->LTag = Link;
	if (!T) {
		Thrt->lchild = Thrt;
	}
	else {
		Thrt->lchild = T;
		pre = Thrt;
		PreThreading(T);
		pre->rchild = Thrt;
		pre->RTag = Thread;
		Thrt->rchild = pre;
	}
	return OK;
}

Status PreOrderTraverse_Thr(BiThrTree T) {

	BiThrTree p;
	p = T->lchild;
	while (p != T) {
		cout << p->data;
		if (p->LTag == Link)
			p = p->lchild;
		else
			p = p->rchild;
		
	}
	cout << endl;
	return OK;
}

void TreePrint(BiThrTree T, int level)
{
	int i;
	if (!T) {
		return;
	}
	if (T->RTag == Link) {
		TreePrint(T->rchild, level + 1);
	}
	for (i = 0; i<level; i++) {
		cout << "     ";
	} 
	cout << T->data << T->LTag << T->RTag << endl;
	if (T->LTag == Link)
		TreePrint(T->lchild, level + 1);
}


int main()
{
	BiThrTree T, PreT;
	CreatBiThrTree(T);

	PreOrderThreading(PreT,T);
	if (PreT->lchild!=PreT) {
		TreePrint(PreT->lchild, 0);
	}
	PreOrderTraverse_Thr(PreT);
	return 0;
}
