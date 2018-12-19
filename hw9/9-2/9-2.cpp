/*
#include<iostream>
using namespace std;

#define ERROR  0
#define OK  1

typedef enum { 
	Link, Thread 
} PointerTag;      
			
typedef char ElemType;
typedef int  Status;


typedef struct BitNode{
	ElemType data;                            
	struct BitNode *lchild;                
	struct BitNode *rchild;
	PointerTag ltag;                        
	PointerTag rtag;
}BiThrNode, *BiThrTree;

BiThrTree pre;                                
										
Status CreatBiThrTree(BiThrTree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!T)
			return 0;
		T->data = ch;
		T->rtag = Link;
		T->ltag = Link;
		CreatBiThrTree(T->lchild);
	
		CreatBiThrTree(T->rchild);
	}
	return 1;
}

int InOrderThraverse_Thr(BiThrTree t)
{
	BiThrTree p;
	p = t->lchild;           
	while (p != t){
		while (p->ltag == Link){
			p = p->lchild;
		}
		cout<<p->data;  
		while (p->rtag == Thread && p->rchild != t){
			p = p->rchild;
			cout<<p->data;
		}
		p = p->rchild;          
	}
	return OK;
}

void InThreading(BiThrTree p)
{
	if (p){
		InThreading(p->lchild);              
		if (!p->lchild){
			p->ltag = Thread;               
			p->lchild = pre;            
		}
		if (!pre->rchild){
			pre->rtag = Thread;            
			pre->rchild = p;            
		}
		pre = p;
		InThreading(p->rchild);              
	}
}

int InOrderThread_Head(BiThrTree *h, BiThrTree t)
{
	(*h) = (BiThrTree)malloc(sizeof(BitNode));
	if ((*h) == NULL){
		return ERROR;
	}

	(*h)->rchild = *h;
	(*h)->rtag = Link;

	if (!t){
		(*h)->lchild = *h;
		(*h)->ltag = Link;
	}
	else
	{
		pre = *h;
		(*h)->lchild = t;       
		(*h)->ltag = Link;
		InThreading(t);         
		pre->rchild = *h;        
		pre->rtag = Thread;
		(*h)->rchild = pre;      
	}
	return OK;
}

Status InOrderFind(BiThrTree Thrt, bool &flag, char check) {
	BiThrTree p = Thrt->lchild;
	BiThrTree prev = Thrt;
	BiThrTree succ = NULL;
	bool flag1 = false, flag2 = false;
	while (p != Thrt) {
		while (p->ltag == Link)
			p = p->lchild;
		if (flag1 == false) {
			if (p->data == check) {
				flag1 = true;
				flag = true;
			}
			else {
				prev = p;
			}
		}
		else {
			if (flag2 == false) {
				succ = p;
				flag2 = true;
			}
		}
		while (p->rtag == Thread && p->rchild != Thrt) {
			p = p->rchild;
			if (flag1 == false) {
				if (p->data == check) {
					flag1 = true;
					flag = true;
				}
				else {
					prev = p;
				}
			}
			else {
				if (flag2 == false) {
					succ = p;
					flag2 = true;
				}
			}
		}
		p = p->rchild;
	}
	if (flag == true) {
		cout << "succ is ";
		if (succ != NULL) {
			cout << succ->data << succ->rtag << endl;
		}
		else {
			cout << "NULL" << endl;
		}
		cout << "prev is ";
		if (prev != Thrt) {
			cout << prev->data << prev->ltag << endl;
		}
		else {
			cout << "NULL" << endl;
		}
	}
	return OK;
}

BiThrTree Search1(BiThrTree t, char target)
{
	BiThrTree p;
	p = t->lchild;
	bool find = false;
	while (p != t) {
		if (p->data == target) {
			find = true;
			return p;
		}
		while (p->ltag == Link) {
			if (p->data == target) {
				find = true;
				return p;
			}
			p = p->lchild;
		}
		while (p->rtag == Thread && p->rchild != t) {
			if (p->data == target) {
				find = true;
				return p;
			}
			p = p->rchild;
		}
		p = p->rchild;
	}
	p = NULL;
	return p;
}

Status Search(BiThrTree t, char target) 
{
	BiThrTree p;
	p=Search1(t, target);
	InOrderThraverse_Thr(t);
	if (!p) {
		cout << "Not found" << endl;
		return OK;
	}
	
	cout << endl;
	cout << "succ is ";
	if ((p->ltag==Thread||p->lchild)&&p->rchild!=t) {
		cout << p->rchild->data << p->rchild->rtag << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	cout << "prev is ";
	if ((p->ltag == Thread||p->rchild)&&p->lchild != t) {
		cout << p->lchild->data << p->lchild->ltag << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	return OK;
}

int main()
{
	BiThrTree t;
	BiThrTree temp;
	ElemType target;

	CreatBiThrTree(t);   
	if (!t) {
		return 0;
	}
	cin.ignore(1024, '\n');
	cin.clear();

	cin >> target;
	InOrderThread_Head(&temp, t);       
	Search(temp, target);
	return 0;
}*/