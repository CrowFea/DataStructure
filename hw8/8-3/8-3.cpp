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

typedef BiTNode * StackElemType;   

typedef struct stacknode    
{
	StackElemType data;
	stacknode * next;
}StackNode;

StackNode * InitStack(StackNode * S)
{
	S = (StackNode *)malloc(sizeof(StackNode));
	if (NULL == S){
		exit(0);
	}

	S->next = NULL;
	return(S);
}

void StackPush(StackNode * S, StackElemType data)
{
	StackNode * q;
	q = (StackNode *)malloc(sizeof(StackNode));
	if (NULL == q){
		exit(0);
	}
	q->data = data;
	q->next = S->next;
	S->next = q;
}

void StackPop(StackNode * S, StackElemType & data)
{
	StackNode * q;
	if (NULL == S->next){
		return ;
	}

	q = S->next;
	data = q->data;
	S->next = q->next;
	free(q);
}

int StackEmpty(StackNode * S)
{
	if (NULL == S->next){
		return(1);
	}

	return(0);
}

int StackGetTop(StackNode * S, StackElemType & data)
{
	if (NULL != S->next)
	{
		data = S->next->data;
		return OK;
	}
	else{
		return 0;
	}
}

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

int NodeCount(BiTree T)
{
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}


void InOrderTraverse2(BiTree  T)
{
	StackNode * S;
	BiTNode * p;
	S = NULL;
	p = T;
	S = InitStack(S);

	if (NULL == p){	
		return;
	}

	while (p || !StackEmpty(S)){
		if (p){
			StackPush(S, p);
			cout << "push " << p->data << endl;
			p = p->lchild;
		}
		else
		{
			StackPop(S, p);
			cout << "pop" << endl;
			cout << p->data << endl;
			p = p->rchild;
		}
	}
	free(S);
}


int main()
{
	BiTree T;
	CreateBiTree(T);
	InOrderTraverse2(T);

	return 0;
}

/*二叉树的非递归先序遍历*/
void PreTraverseTree2(BiTree  T)
{
	StackNode  *S;
	BiTNode * p;
	S = NULL;
	p = T;
	S = InitStack(S);
	if (NULL == p){
		return;
	}
	while (p || !StackEmpty(S)){
		if (p){
			StackPush(S, p);
			cout  << p->data << endl;
			p = p->lchild;
		}
		else{
			StackPop(S, p);
			p = p->rchild;
		}
	}
	free(S);
}

/*二叉树非递归后序遍历*/
void LastTraverseTree2(BiTree T)
{
	StackNode * S;
	BiTNode * cur, *pre;
	S = NULL;
	S = InitStack(S);
	if (NULL == T){
		return;
	}
	pre = NULL;    
	cur = NULL;
	StackPush(S, T);
	while (!StackEmpty(S)){
		cur = NULL;
		StackGetTop(S, cur);
		if ((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild 
			|| pre == cur->rchild))){
			cout<<cur->data<<endl;
			pre = cur;
			StackPop(S, cur);
		}
		else{
			if (cur->rchild != NULL){
				StackPush(S, cur->rchild);

			}
			if (cur->lchild != NULL){
				StackPush(S, cur->lchild);
			}
		}
	}
	free(S);
}