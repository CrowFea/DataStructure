/*
#include<iostream>
#include<iomanip>
using namespace std;

#define MAXSIZE 100000

struct Node {
	int data;
	Node* left;
	Node* right;
};



void release(Node* root) {

	if (root == 0) {
		return;
	}

	release(root->left);
	release(root->right);

	delete root;

}

Node *pre;

void search(Node*& root, int key, Node**& _result) {

	if (root == 0) {
		_result = 0;
		return;
	}

	if (key<root->data) {
		pre = root;
		search(root->left, key, _result);
	}
	else if (key == root->data) {
		_result = &root;
		return;
	}
	else {
		pre = root;
		search(root->right, key, _result);
	}
}

void insert(Node*& root, int value) {

	if (root == 0) {
		root = new Node;
		root->left = 0;
		root->right = 0;
		root->data = value;
		return;
	}

	if (value>root->data) {
		insert(root->right, value);
	}
	else if (value == root->data) {
		return;
	}
	else {
		insert(root->left, value);
	}
}

bool _delete(Node*& root, int key) {

	Node** node;
	search(root, key, node);

	if (node == 0) {
		return false;
	}

	Node* temp = *node;

	if ((*node)->left == 0 && (*node)->right == 0) {
		*node = 0;
		//cout << "0" << endl;
		delete temp;
	}
	else if ((*node)->left == 0) {
		*node = (*node)->right;
		delete temp;
	}
	else if ((*node)->right == 0) {
		*node = (*node)->left;
		delete temp;
	}
	else {
		Node *s = (*node)->right;
		if ((*node)->left->right != 0) {
			while (s->left) {
				s = s->left;
			}
			s->left = (*node)->left->right;
		}
		if ((*node)->data < pre->data) {
			pre->left = (*node)->left;
			(*node)->left->right = (*node)->right;
		}
		else {
			(*node)->left->right = (*node)->right;
			pre->right = (*node)->left;
			
		}

	}
	return true;

}

void PreOrderTraverse(Node *root)
{
	if (root) {
		cout << root->data<<" ";
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}
	
}

void TreePrint(Node *root, int level)
{
	int i;
	if (!root) {
		return;
	}
	TreePrint(root->right, level + 1);
	for (i = 0; i<level; i++) {
		cout << "     ";
	}
	cout << root->data << endl;
	TreePrint(root->left, level + 1);
}

void calFind(Node *root, int level,int arr[])
{
	if (!root) {
		return;
	}
	calFind(root->right, level + 1,arr);
	
	arr[level]++;
	calFind(root->left, level + 1, arr);
}


int main() 
{
	int i,n;
	int num;
	Node* root = new Node;
	root->left = 0;
	root->right = 0;
	root->data = 0;
	cin >> n;

	for (i = 0; i<n; i++) {
		cin >> num;
		insert(root, num);
	}
	Node** _result;
	int value;
	cin >> value;

	if (_delete(root->right, value)) {
		n--;
		cout << 1<< endl;
	}
	else {
		cout << 0 << endl;
	}
	
	search(root->right, value, _result);
	if (_result == 0) {
		cout << 0 << endl;
		n++;
		insert(root, value);
	}
	else {
		cout << 1 << endl;
		
	}
	

	PreOrderTraverse(root->right);
	cout << endl;

	int arr[MAXSIZE];
		double sum=0;
		for (i = 0; i<MAXSIZE; i++) {
			arr[i] = 0;
		}
	calFind(root->right, 0, arr);

	for (i = 0; arr[i]!=0; i++) {
		sum += (i + 1)*arr[i];
	}
	if (n == 0) {
		cout << fixed << setprecision(2) << 1.00 << endl;
	}
	else {
		cout << fixed << setprecision(2) << (sum / n) << endl;
	}
	release(root);
	return 0;
}
*/