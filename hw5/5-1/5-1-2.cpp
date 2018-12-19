#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;

typedef struct Node{
	string data;
	int cur;
}*SLinkList, StaticList;

void InitSList(SLinkList&SList, int num, int n)
{
	int i = 0;
	for (i = 0; i<num; i++){
		SList[i].data = "N/A";
	}
	for (i = 2; i < num - 1; i++){
		SList[i].cur = i + 1;
	}
	SList[num - 1].cur = -1;
	SList[0].cur = -1;
	if (num > 2){
		SList[1].cur = 2;
	}
	else{
		SList[1].cur = -1;
	}
}

void Print(SLinkList&SList, int a)
{
	int k = 0;
	for (int i = 0; i<a; i++){
		cout << i << " : " << SList[i].data << " : " << SList[i].cur << "        ";
		k++;
		if (k % 3 == 0 && k != 0) {
			cout << endl;
		}
	}
	if (k % 3 != 0){
		cout << endl;
	}
}

void Chage(SLinkList&SList, int num, string str)
{
	int t = SList[1].cur;
	SList[1].cur = SList[t].cur;
	SList[t].data = str;
	SList[t].cur = SList[num].cur;
	SList[num].cur = t;

}

void Free(SLinkList&SList, int n)
{
	SList[n].cur = SList[1].cur;
	SList[n].data = "N/A";
	SList[1].cur = n;
}

void Print_l(SLinkList&SList)
{
	int i = SList[0].cur;
	for (i; i != -1;){
		cout << SList[i].data << " ";
		i = SList[i].cur;
	}
	cout << endl;
}

void Insert(SLinkList&SList, string insert, int num, int &n)
{
	if (SList[1].cur == -1){
		cout << "FULL" << endl;
		return;
	}
	int curpos = 0, s; 
	int pos = 0;
	while (curpos != -1 && pos < num - 1) {
		curpos = SList[curpos].cur;
		pos++;
	}

	if (curpos == -1 || pos > num - 1)  {
		cout << "-1" << endl;
		return;
	}
	Chage(SList, curpos, insert);
	Print_l(SList);
	n++;
}

void Delete(SLinkList&SList, int a, int &n)
{
	if (SList[0].cur == -1){
		cout << "EMPTY" << endl;
		return;
	}
	if (a<1 || a>n){
		cout << "-1" << endl;
		return;
	}
	int curpos = 0, q = 1;
	while (q<a){
		curpos = SList[curpos].cur;
		q++;
	}
	int t = SList[curpos].cur;
	cout << SList[t].data << endl;
	SList[curpos].cur = SList[t].cur;
	Free(SList, t);
	n--;
}

int Compare(string str1, string str2)
{
	if (str1 == str2)
		return 1;
	else
		return 0;
}

int Locate(SLinkList&SList, string e, int(*compare)(string e1, string e2))
{
	int curpos = SList[0].cur;  
	int pos = 1;        					 
	while (curpos != -1 && (*compare)(e, SList[curpos].data) == 0) {
		curpos = SList[curpos].cur;
		pos++;
	}

	return curpos != -1 ? pos : -1;
}

int main()
{
	SLinkList SList;
	int num, n, pos;
	cin >> num >> n;
	SList = new StaticList[num];
	string str;
	InitSList(SList, num, n);
	for (int i = 1; i <= n; i++){
		cin >> str;
		if (i <= num - 2){
			if (i == 1) {
				Chage(SList, 0, str);
			}
			else {
				Chage(SList, i, str);
			}
		}
	}
	if (n > num - 2) {
		n = num - 2;
	}
	Print(SList, num);
	cin >> pos >> str;
	Insert(SList, str, pos, n);
	cin >> pos;
	Delete(SList, pos, n);
	cin >> str;
	cout << Locate(SList, str, Compare) << endl;
	cin >> str;
	Insert(SList, str, n + 1, n);
	Print(SList, num);
	return 0;
}