
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
//����һ��������������ǰ���������������
//��������
void CreatTree(BiThrTree *T);
void DestroyBiTree(BiThrTree &T);
void DestroyBiThrTree(BiThrTree &Thrt);
//����������������������ʵ���������������������
void InThreding(BiThrTree T);
void InorderThreding(BiThrTree *p, BiThrTree T);
void InOrderTraverse(BiThrTree T);
void InOrderTraverse_Iter(BiThrTree T);

//ǰ��������������������ʵ��ǰ�����������������
void PreThreding(BiThrTree T);
void PreorderThreding(BiThrTree *p, BiThrTree T);
void PreOrderTraverse(BiThrTree T);
void PreOrderTraverse_Iter(BiThrTree T);

//����������������������ʵ�ֺ������������������
void PostThreding(BiThrTree T);
void PostorderThreding(BiThrTree *p, BiThrTree T);
void PostOrderTraverse(BiThrTree T);
void PostOrderTraverse_Iter(BiThrTree T);

//��������
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
	if (T)  // �ǿ���  
	{
		if (T->Ltag == Link)                // ������  
			DestroyBiTree(T->Left);         // ������������  
		if (T->Rtag == Link)                // ���Һ���  
			DestroyBiTree(T->Right);        // �����Һ�������  
		free(T);    // �ͷŸ����  
		T = NULL;   // ��ָ�븳0  
	}
}
// ��ʼ����������������Thrt���ڡ������������������������Thrt  
void DestroyBiThrTree(BiThrTree &T)
{
	if (T)             // ͷ������  
	{
		if (T->Left)    // ��������  
		{
			DestroyBiTree(T->Left); // �ݹ�����ͷ���lchild��ָ������  
		}
		free(T);     // �ͷ�ͷ���  
		T = NULL;    // ����������Thrtָ�븳0  
	}
}
//ǰ��������������������ʵ��ǰ�����������������
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
			PreThreding(T->Left);//�ݹ�����������
		if (T->Rtag == Link)
			PreThreding(T->Right);//�ݹ��Һ���������
	}
}

void PreorderThreding(BiThrTree *p, BiThrTree T)
{//p���Ϊͷ��㣬T���Ϊ�������
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
//��ǰ���йصĺ���ʵ�ֽ���

//����������������������ʵ�������������
//��������������Ĺ���
void InThreding(BiThrTree T)
{
	if (T)
	{
		InThreding(T->Left);//�ݹ�����������
							 //��㴦��
		if (!T->Left)      //����ý��û�����ӣ�
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
		InThreding(T->Right);//�ݹ��Һ���������
	}
}
void InorderThreding(BiThrTree *p, BiThrTree T)
{//p���Ϊͷ��㣬T���Ϊ�������
	*p = (BiThrNode*)malloc(sizeof(struct BiThrNode));//����һ��ͷ���
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;
	(*p)->Right = *p;          //��ָ���ָ
	if (!T)  (*p)->Left = *p;   //��������Ϊ�գ�����ָ���ָ
	else
	{
		(*p)->Left = T;        //����������Ϊ�գ�Leftָ������
		pre = *p;
		InThreding(T);       //���������������������
							 //���һ�����������
		pre->Rtag = Thread;
		pre->Right = *p;    //�ն˽��ָ��ͷ���
		(*p)->Right = pre;  //ͷ������ָ��ָ���ն˽��
	}

}
//����������������ǵݹ�ʵ��
void InOrderTraverse_Iter(BiThrTree T)
{
	BiThrTree p;
	p = T->Left;      //pָ������T
	while (p != T)     //�������ǿջ����δ����
	{
		while (p->Ltag == Link)  //����������Ϊ�յĽ��
		{
			p = p->Left;
		}
		cout << p->Data;
		while ((p->Rtag == Thread) && (p->Right != T))  //p��Rightָ���̣�����p���ĺ��
		{
			p = p->Right;
			cout << p->Data;
		}
		p = p->Right;   //p��Rightָ���Һ���
	}
}
//�������йصĺ���ʵ�ֽ���

//����������������������ʵ�ֺ������������������
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
	//p���Ϊͷ��㣬T���Ϊ�������
	*p = (BiThrNode*)malloc(sizeof(struct BiThrNode));
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;

	if (!T)  (*p)->Left = (*p)->Right = *p;
	else
	{
		(*p)->Left = (*p)->Right = *p;
		pre = *p;
		PostThreding(T);
		if (pre->Rtag != Link)  // ���һ�����û���Һ���  
		{
			pre->Right = *p;  // ���һ�����ĺ��ָ��ͷ���  
			pre->Rtag = Thread;
		}
	}
}
void PostOrderTraverse_Iter(BiThrTree T)
{
	BiThrTree p = T->Left;
	while (p->Ltag == Link || p->Rtag == Link)   //�������ȷ�������,û�������ȷ����Һ���  
	{
		while (p->Ltag == Link)
			p = p->Left;
		if (p->Rtag == Link)                //��������Ϊ�յĽ����Һ���  
			p = p->Right;
	}
	cout << p->Data;
	while (p != T)                        //p��Ϊ�����  
	{
		if (p->Rtag == Link)              //��p�����ֵܵ�����  
		{
			if (pre->Rtag == Thread || p == pre->Right) //��p��˫�׵��Һ��ӻ��Ƕ������ӣ�����Ϊ˫��  
				p = pre;
			else
			{
				p = pre->Right;              //���Ϊ˫�׵��������ϰ��պ���������ʵĵ�һ����㡣  
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
			p = p->Right;             //pָ����  
		cout << p->Data;
	}
}
//������йصĺ���ʵ�ֽ���
int _tmain(int argc, _TCHAR* argv[])
{
	BiThrTree T = NULL;
	BiThrTree T = NULL;
	BiThrTree A = NULL;
	BiThrTree BA = NULL;
	BiThrTree D = NULL;
	BiThrTree BD = NULL;
	cout << "����ǰ�����������������" << endl;
	CreatTree(&T);
	cout << "���������";
	InOrderTraverse(T);
	cout << endl;
	cout << "����������!" << endl;
	InorderThreding(&T, T);
	cout << "�����������������";
	InOrderTraverse_Iter(T);
	cout << endl;
	DestroyBiThrTree(T);

	cout << "����ǰ�����������������" << endl;
	CreatTree(&A);
	cout << "ǰ�������";
	PreOrderTraverse(A);
	cout << endl;
	cout << "ǰ��������!" << endl;
	PreorderThreding(&BA, A);
	cout << "ǰ���������������";
	PreOrderTraverse_Iter(BA);
	cout << endl;
	DestroyBiThrTree(BA);

	cout << "����ǰ�����������������" << endl;
	CreatTree(&D);
	cout << "���������";
	PostOrderTraverse(D);
	cout << endl;
	cout << "����������!" << endl;
	PostorderThreding(&BD, D);
	cout << "�����������������";
	PostOrderTraverse_Iter(BD);
	DestroyBiThrTree(BD);
	cout << endl;
	return 0;
}