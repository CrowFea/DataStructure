#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOWED   -2

typedef double  Status;
typedef int ElemType;

typedef struct LNode {
	ElemType coef;
	ElemType exp;
	struct LNode *next;
	LNode(ElemType x, ElemType y) :coef(x), exp(y), next(nullptr) {}
} LNode, *LinkList;

void initial(LinkList &L, ElemType n)
{
	LNode *p;
	L = new LNode(0, 0);
	p = L;
	while (n) {
		p->next = new LNode(0, 0);
		p = p->next;
		cin >> p->coef >> p->exp;
		n--;
	}
	p->next = nullptr;
}

Status calculate(LinkList L, double x)
{
	double res = 0;
	int exp = 0;
	LNode *p;
	p = L->next;
	while (p) {
		double x1 = 1;
		if (p->exp == 0) {
			x1 = 1;
		}
		else {
			for (exp = p->exp ; exp > 0; exp--) {
				x1 *= x;
			}
		}
		x1 *= p->coef;
		res += x1;
		p = p->next;
		
	}
	return res;
}


int main()
{
	LinkList L1;
	int n;
	double x, res;
	cin >> n;
	initial(L1, n);
	cin >> x;
	res = calculate(L1, x);
	cout << fixed << setprecision(1) << res << endl;


	return 0;
}
