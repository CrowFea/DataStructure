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

typedef struct Node {
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

void TreePrint(BiTree T, int level)
{
	int i;

	if (!T) {
		return;
	}
	TreePrint(T->rchild, level + 1);
	for (i = 0; i<level; i++) {
		cout << "     ";
	}
	cout << T->data << endl;
	TreePrint(T->lchild, level + 1);
}


int Depth(BiTree T)
{
	if (T == NULL)
		return 0;
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m>n) return (m + 1);
		else return (n + 1);
	}
}

int NodeCount(BiTree T)
{
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

int LeafCount(BiTree T)
{
	if (!T) {
		return 0;
	}
	if (!T->lchild && !T->rchild) {
		return 1;
	}
	else {
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

void Copy(BiTree T, BiTree &NewT)
{
	if (T == NULL) {
		NewT = NULL;
		return;
	}
	else{
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->rchild);
		Copy(T->rchild, NewT->lchild);
	}
}

void ExChangeTree(BiTree &T)
{
	BiTree temp;
	if (T != NULL) {
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		ExChangeTree(T->lchild);
		ExChangeTree(T->rchild);
	}
}

int main()
{
	BiTree T,NewT;
	CreateBiTree(T);
	cout<<LeafCount(T)<<endl;
	cout<<NodeCount(T)<<endl;
	cout << Depth(T) << endl;
	Copy(T, NewT);
	//ExChangeTree(NewT);
	TreePrint(T,0);
	TreePrint(NewT, 0);

	return 0;
}
