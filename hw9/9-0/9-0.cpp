
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


typedef char ElemType;

typedef enum { 
	Link, Thread 
} 
PointerTag;

typedef struct BiThrNode{
	ElemType Data;
	struct BiThrNode *Left;
	struct BiThrNode *Right;
	PointerTag Ltag;
	PointerTag Rtag;
}BiThrNode, *BiThrTree;

BiThrNode *pre;
//创建一个二叉树：利用前序遍历创建二叉树
//函数声明
void CreatTree(BiThrTree *T);
void DestroyBiTree(BiThrTree &T);
void DestroyBiThrTree(BiThrTree &Thrt);
//中序线索化二叉树，并且实现中序遍历操作函数定义
void InThreding(BiThrTree T);
void InorderThreding(BiThrTree *p, BiThrTree T);
void InOrderTraverse(BiThrTree T);
void InOrderTraverse_Iter(BiThrTree T);

//前序线索化二叉树，并且实现前序遍历操作函数定义
void PreThreding(BiThrTree T);
void PreorderThreding(BiThrTree *p, BiThrTree T);
void PreOrderTraverse(BiThrTree T);
void PreOrderTraverse_Iter(BiThrTree T);

//后序线索化二叉树，并且实现后序遍历操作函数定义
void PostThreding(BiThrTree T);
void PostorderThreding(BiThrTree *p, BiThrTree T);
void PostOrderTraverse(BiThrTree T);
void PostOrderTraverse_Iter(BiThrTree T);

//函数定义
void CreatTree(BiThrTree *T)
{
	char ch;
	cin >> ch;
	if (ch == '#') { 
		*T = NULL; 
	}
	else
	{
		*T = (BiThrNode*)malloc(sizeof(struct BiThrNode));
		(*T)->Data = ch;
		(*T)->Ltag = Link;
		(*T)->Rtag = Link;
		CreatTree(&(*T)->Left);
		CreatTree(&(*T)->Right);
	}
}

void DestroyBiTree(BiThrTree &T)
{
	if (T)  // 非空树  
	{
		if (T->Ltag == Link)                // 有左孩子  
			DestroyBiTree(T->Left);         // 销毁左孩子子树  
		if (T->Rtag == Link)                // 有右孩子  
			DestroyBiTree(T->Right);        // 销毁右孩子子树  
		free(T);    // 释放根结点  
		T = NULL;   // 空指针赋0  
	}
}
// 初始条件：线索二叉树Thrt存在。操作结果：销毁线索二叉树Thrt  
void DestroyBiThrTree(BiThrTree &T)
{
	if (T)             // 头结点存在  
	{
		if (T->Left)    // 根结点存在  
		{
			DestroyBiTree(T->Left); // 递归销毁头结点lchild所指二叉树  
		}
		free(T);     // 释放头结点  
		T = NULL;    // 线索二叉树Thrt指针赋0  
	}
}
//前序线索化二叉树，并且实现前序遍历操作函数定义
void PreThreding(BiThrTree T)
{
	if (T)
	{
		if (!T->Left)
		{
			T->Ltag = Thread;
			T->Left = pre;
		}
		if (!pre->Right)
		{
			pre->Right = T;
			pre->Rtag = Thread;
		}
		pre = T;
		if (T->Ltag == Link)
			PreThreding(T->Left);//递归左孩子线索化
		if (T->Rtag == Link)
			PreThreding(T->Right);//递归右孩子线索化
	}
}

void PreorderThreding(BiThrTree *p, BiThrTree T)
{//p结点为头结点，T结点为树根结点
	*p = (BiThrNode*)malloc(sizeof(struct BiThrNode));
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;
	(*p)->Right = *p;
	if (!T)  (*p)->Left = *p;
	else
	{
		(*p)->Left = T;
		pre = *p;
		PreThreding(T);
		pre->Right = *p;
		pre->Rtag = Thread;
		(*p)->Right = pre;
	}
}

void PreOrderTraverse_Iter(BiThrTree T)
{
	BiThrTree p = T->Left;
	while (p != T)
	{
		cout << p->Data;
		if (p->Ltag == Link)
			p = p->Left;
		else
			p = p->Right;
	}
	cout << endl;
}
//与前序有关的函数实现结束

//中序线索化二叉树，并且实现中序遍历操作
//中序遍历线索化的过程
void InThreding(BiThrTree T)
{
	if (T)
	{
		InThreding(T->Left);//递归左孩子线索化
							 //结点处理
		if (!T->Left)      //如果该结点没有左孩子，
		{
			T->Ltag = Thread;
			T->Left = pre;
		}
		if (!pre->Right)
		{
			pre->Rtag = Thread;
			pre->Right = T;
		}
		pre = T;
		InThreding(T->Right);//递归右孩子线索化
	}
}
void InorderThreding(BiThrTree *p, BiThrTree T)
{//p结点为头结点，T结点为树根结点
	*p = (BiThrNode*)malloc(sizeof(struct BiThrNode));//创建一个头结点
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;
	(*p)->Right = *p;          //有指针回指
	if (!T)  (*p)->Left = *p;   //若二叉树为空，则做指针回指
	else
	{
		(*p)->Left = T;        //若二叉树不为空，Left指向根结点
		pre = *p;
		InThreding(T);       //中序遍历进行中序线索化
							 //最后一个结点线索化
		pre->Rtag = Thread;
		pre->Right = *p;    //终端结点指向头结点
		(*p)->Right = pre;  //头结点的右指针指向终端结点
	}

}
//中序遍历二叉树，非递归实现
void InOrderTraverse_Iter(BiThrTree T)
{
	BiThrTree p;
	p = T->Left;      //p指向根结点T
	while (p != T)     //二叉树非空或遍历未结束
	{
		while (p->Ltag == Link)  //访问左子树为空的结点
		{
			p = p->Left;
		}
		cout << p->Data;
		while ((p->Rtag == Thread) && (p->Right != T))  //p的Right指向后继，访问p结点的后继
		{
			p = p->Right;
			cout << p->Data;
		}
		p = p->Right;   //p的Right指向右孩子
	}
}
//与中序有关的函数实现结束

//后序线索化二叉树，并且实现后序遍历操作函数定义
void PostThreding(BiThrTree T)
{
	if (T)
	{
		PostThreding(T->Left);
		PostThreding(T->Right);
		if (!T->Left)
		{
			T->Ltag = Thread;
			T->Left = pre;
		}
		if (!pre->Right)
		{
			pre->Rtag = Thread;
			pre->Right = T;
		}
		pre = T;
	}
}
void PostorderThreding(BiThrTree *p, BiThrTree T)
{
	//p结点为头结点，T结点为树根结点
	*p = (BiThrNode*)malloc(sizeof(struct BiThrNode));
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;

	if (!T)  (*p)->Left = (*p)->Right = *p;
	else
	{
		(*p)->Left = (*p)->Right = *p;
		pre = *p;
		PostThreding(T);
		if (pre->Rtag != Link)  // 最后一个结点没有右孩子  
		{
			pre->Right = *p;  // 最后一个结点的后继指向头结点  
			pre->Rtag = Thread;
		}
	}
}
void PostOrderTraverse_Iter(BiThrTree T)
{
	BiThrTree p = T->Left;
	while (p->Ltag == Link || p->Rtag == Link)   //有左孩子先访问左孩子,没有左孩子先访问右孩子  
	{
		while (p->Ltag == Link)
			p = p->Left;
		if (p->Rtag == Link)                //访问左孩子为空的结点的右孩子  
			p = p->Right;
	}
	cout << p->Data;
	while (p != T)                        //p不为根结点  
	{
		if (p->Rtag == Link)              //若p是有兄弟的左孩子  
		{
			if (pre->Rtag == Thread || p == pre->Right) //若p是双亲的右孩子或是独生左孩子，则后继为双亲  
				p = pre;
			else
			{
				p = pre->Right;              //后继为双亲的右子树上按照后序遍历访问的第一个结点。  
				while (p->Ltag == Link || p->Rtag == Link)
				{
					if (p->Ltag == Link)
						p = p->Left;
					if (p->Rtag == Link)
						p = p->Right;
				}
			}
		}
		else
			p = p->Right;             //p指向后继  
		cout << p->Data;
	}
}
//与后序有关的函数实现结束
int _tmain(int argc, _TCHAR* argv[])
{
	BiThrTree T = NULL;
	BiThrTree T = NULL;
	BiThrTree A = NULL;
	BiThrTree BA = NULL;
	BiThrTree D = NULL;
	BiThrTree BD = NULL;
	cout << "按照前序遍历创建二叉树：" << endl;
	CreatTree(&T);
	cout << "中序遍历：";
	InOrderTraverse(T);
	cout << endl;
	cout << "中序线索化!" << endl;
	InorderThreding(&T, T);
	cout << "中序线索化后输出：";
	InOrderTraverse_Iter(T);
	cout << endl;
	DestroyBiThrTree(T);

	cout << "按照前序遍历创建二叉树：" << endl;
	CreatTree(&A);
	cout << "前序遍历：";
	PreOrderTraverse(A);
	cout << endl;
	cout << "前序线索化!" << endl;
	PreorderThreding(&BA, A);
	cout << "前序线索化后输出：";
	PreOrderTraverse_Iter(BA);
	cout << endl;
	DestroyBiThrTree(BA);

	cout << "按照前序遍历创建二叉树：" << endl;
	CreatTree(&D);
	cout << "后序遍历：";
	PostOrderTraverse(D);
	cout << endl;
	cout << "后序线索化!" << endl;
	PostorderThreding(&BD, D);
	cout << "后序线索化后输出：";
	PostOrderTraverse_Iter(BD);
	DestroyBiThrTree(BD);
	cout << endl;
	return 0;
}