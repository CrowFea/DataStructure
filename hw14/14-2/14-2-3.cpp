#include<iostream>
#include <iomanip>

using namespace std;
int a[10000] = { 0 };

typedef int ElemType;

class OrderT;

class OrderTNode{
public:
	ElemType data;
	OrderTNode *lchild;
	OrderTNode *rchild;
	OrderTNode(){
		lchild = NULL;
		rchild = NULL;
	}
};

class OrderT
{
public:
	OrderTNode * root;
	OrderT(){
		root = NULL;
	}
	~OrderT(){
		
	}

	OrderTNode *Search(ElemType value, OrderTNode *&p);
	void Insert(ElemType value); 
	int Delete(ElemType value);
	void PreOrderTra(OrderTNode *bt, int i);
	bool IsEmpty(){
		return root == NULL;
	}
};

OrderTNode *OrderT::Search(ElemType value, OrderTNode *&p)
{
	OrderTNode *q = NULL;
	q = root;
	while (q){
		p = q;
		if (q->data == value) {
			return p;
		}
		else if (q->data > value) {
			q = q->lchild;
		}
		else {
			q = q->rchild;
		}
	}
	return NULL;
}

void OrderT::Insert(ElemType value)
{
	OrderTNode *p = NULL, *q;
	q = root;
	if (Search(value, p) == NULL){
		OrderTNode *ins = new OrderTNode;
		ins->data = value;
		if (q == NULL){
			root = ins;
			return;
		}
		if (p&&value < p->data) {
			p->lchild = ins;
		}
		else if (p&&value > p->data) {
			p->rchild = ins;
		}
	}
}

void OrderT::PreOrderTra(OrderTNode *p, int level)
{
	if (p){
		a[level]++;
		cout << p->data << " ";
		PreOrderTra(p->lchild, level + 1);
		PreOrderTra(p->rchild, level + 1);
	}
}

int OrderT::Delete(ElemType value)
{
	OrderTNode *pre, *lcur, *rpre, *rcur;
	lcur = root;
	pre = NULL;
	while (lcur&&lcur->data != value){
		pre = lcur; 
		if (lcur->data>value)
			lcur = lcur->lchild;
		else
			lcur = lcur->rchild;
	}
	if (!lcur)
		return 0;
	if (lcur->lchild == NULL) {
		if (pre == NULL)
			root = lcur->rchild;
		else if (pre->lchild == lcur)
			pre->lchild = lcur->rchild;
		else               
			pre->rchild = lcur->rchild;
		delete lcur;
	}

	else{
		rpre = lcur;
		rcur = lcur->lchild;
		while (rcur->rchild) {
			rpre = rcur;
			rcur = rcur->rchild;
		}
		if (rpre == lcur)
			rpre->lchild = rcur->lchild;
		else
			rpre->rchild = rcur->lchild;
		lcur->data = rcur->data;  
		delete rcur;
	}
	return 1;
}

int main()
{
	OrderT OrderTree;
	OrderTNode  *p = NULL, *rootP = NULL;
	int num, node;
	double sum = 0;
	cin >> num;
	for (int i = 0; i < num; i++){
		cin >> node;
		OrderTree.Insert(node);
	}
	cin >> node;
	cout << OrderTree.Delete(node) << endl;   
	rootP = OrderTree.Search(node, p); 
	if (rootP){
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
		OrderTree.Insert(node);
	}
	OrderTree.PreOrderTra(OrderTree.root, 0);
	cout << endl;
	for (int i = 0; a[i] != 0; i++){
		sum += (a[i] * (i + 1));
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sum / num << endl;
	return 0;
}
