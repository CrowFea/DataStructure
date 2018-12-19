
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOWED -1


typedef char ElemType;
typedef int Status;

typedef enum {
	Link, Thread
} PointerTag;

typedef struct BiThrNode {
	ElemType data;
	BiThrNode *lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree;

Status CreateBiThrTree(BiThrTree &PreT) {
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		PreT = NULL;
	}
	else {
		if (!(PreT = (BiThrNode*)malloc(sizeof(BiThrNode)))) 
			exit(OVERFLOWED);
		PreT->data = ch;
		PreT->ltag = Link;
		PreT->rtag = Link;
		CreateBiThrTree(PreT->lchild);
		CreateBiThrTree(PreT->rchild);
	}
	return OK;
}

void InThreading(BiThrTree p, BiThrTree &pre) {
	if (p) {
		InThreading(p->lchild, pre);
		if (!p->lchild) {
			p->ltag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild, pre);
	}
}

Status InOrderThreading(BiThrTree &T, BiThrTree PreT) {
	BiThrTree pre;
	if (!(T = (BiThrTree)malloc(sizeof(BiThrNode)))) 
		exit(OVERFLOWED);
	T->ltag = Link;
	T->rtag = Thread;
	T->rchild = T;
	if (!PreT)
		T->lchild = T;
	else {
		T->lchild = PreT;
		pre = T;
		InThreading(PreT, pre);
		pre->rchild = T;
		pre->rtag = Thread;
		T->rchild = pre;
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T) {
	BiThrTree p = T->lchild;
	while (p != T) {
		while (p->ltag == Link)
			p = p->lchild;
		cout << p->data;
		while (p->rtag == Thread && p->rchild != T) {
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;
	}
	return OK;
}

Status InOrderFind(BiThrTree T,  char target) {
	BiThrTree p = T->lchild;
	BiThrTree prev = T;
	BiThrTree succ = NULL;
	bool is_found=false,prev_exist = false, succ_exist = false;
	while (p != T) {
		while (p->ltag == Link)
			p = p->lchild;
		if (prev_exist == false) {
			if (p->data == target) {
				prev_exist = true;
				is_found = true;
			}
			else {
				prev = p;
			}
		}
		else {
			if (succ_exist == false) {
				succ = p;
				succ_exist = true;
			}
		}
		while (p->rtag == Thread && p->rchild != T) {
			p = p->rchild;
			if (prev_exist == false) {
				if (p->data == target) {
					prev_exist = true;
					is_found = true;
				}
				else {
					prev = p;
				}
			}
			else {
				if (succ_exist == false) {
					succ = p;
					succ_exist = true;
				}
			}
		}
		p = p->rchild;
	}
	if (is_found == true) {
		InOrderTraverse_Thr(T);
		cout << endl;
		cout << "succ is ";
		if (succ != NULL) {
			cout << succ->data << succ->rtag << endl;
		}
		else {
			cout << "NULL" << endl;
		}
		cout << "prev is ";
		if (prev != T) {
			cout << prev->data << prev->ltag << endl;
		}
		else {
			cout << "NULL" << endl;
		}
	}
	else {
		InOrderTraverse_Thr(T);
		cout << endl;
		cout << "Not found"<<endl;
	}
	return OK;
}

int main() {
	BiThrTree PreT, T;
	char target;
	CreateBiThrTree(PreT);
	cin >> target;
	InOrderThreading(T, PreT);
	
	//cout << endl;
	InOrderFind(T, target);
	return 0;
}
