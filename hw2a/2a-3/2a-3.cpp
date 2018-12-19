#include<iostream>
using namespace std;

#define MAXSIZE 10000

typedef int ElemType;

typedef struct Node{
	ElemType weight;
	struct Node* LChild, *RChild;
}HNode,*HTree;

void CreateTree(HTree &T)
{
	HTree Root = T;
	T->LChild = NULL;
	T->RChild = NULL;
	int n,wei,i;
	char code[MAXSIZE];
	cin >> n;
	while (n) {
		cin >> wei;
		cin >> code;
		for (i = 0; code[i] != '\0'; i++) {
			if (code[i] == '1') {
				if (!T->RChild) {
					T->RChild = new HNode;
					T->RChild->LChild = NULL;
					T->RChild->RChild = NULL;
				}
				T = T->RChild;
			}
			else {
				if (!T->LChild) {
					T->LChild = new HNode;
					T->LChild->LChild = NULL;
					T->LChild->RChild = NULL;
				}
				T = T->LChild;
			}
		}
		T->weight = wei;
		T = Root;
		n--;
	}
	return;
}

void Decode(HTree T,char Code[])
{
	int i=0;
	HTree Root = T;
	while (Code[i] != '\0') {
		
		if (!T->LChild && !T->RChild) {
			cout << char(T->weight);
			T = Root;
			continue;
		}
		if (Code[i] == '1') {
			T = T->RChild;
		}
		else {
			T = T->LChild;
		}
		i++;
	}
	cout << char(T->weight);
	cout << endl;
	return;
}

int main()
{
	char Code[MAXSIZE];
	HTree T;
	T = (HTree)malloc((1) * sizeof(HNode));
	CreateTree(T);
	cin >> Code;
	Decode(T, Code);
	return 0;
}