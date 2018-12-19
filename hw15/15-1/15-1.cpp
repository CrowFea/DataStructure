#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAXSIZE 100

typedef string ElemType;

typedef struct Node {
	ElemType value;
	int choosed;
} *PNode;

typedef struct HashTable {
	int size;
	PNode arr;
} *PHashTable;


PHashTable init(int P)
{
	PHashTable table = (PHashTable)malloc(sizeof(struct HashTable));
	table->size = P;
	table->arr = new Node[P];
	int i;
	for (i = 0; i < P; i++) {
		table->arr[i].choosed = 0;
		table->arr[i].value = "";
	}
	return table;
}

int hashcal(string key, int M)
{

	unsigned int i;
	int value = 0;
	for (i = 0; i<key.length(); i++) {
		if (key[i] >= 97) {
			key[i] -= 96;
		}
		else {
			key[i] -= 64;
		}
		//value += (int)(key[i] * pow(37, key.length() - 1 - i));
		int len = key.length() - 1 - i;
		int temp = key[i];
		while (len) {
			if (temp>= 2147483647 / 37) {
				temp %= M;
			}
			temp *= 37;
			len--;
		}
		temp %= M;
		value += temp;


		value %= M;
	}
	return value;
}

int insert(PHashTable table, string key, int M)
{
	int index = hashcal(key, M);
	while (table->arr[index].choosed
		&& table->arr[index].value != key && table->arr[index].value != "") {
		table->arr[index].choosed++;
		index++;
		index = index % table->size;
	}
	if (!table->arr[index].choosed) {
		table->arr[index].value = key;
		table->arr[index].choosed = 1;
	}
	return index;
}

int hashFind(PHashTable table, string key, int M, int P)
{
	int index = hashcal(key, M);
	int count = 1;
	while (index<P) {
		if (table->arr[index].value == key && table->arr[index].value != "") {
			return count;
		}
		else {
			index++;
			index = index % table->size;
			count++;
		}
	}
	return -1;
}

int main()
{
	int N, M, P;
	cin >> N >> M >> P;

	PHashTable table = init(P);
	int i;

	string key;
	int *ind = new int[N];
	int *find = new int[N];
	for (i = 0; i < N; i++) {
		cin >> key;
		int index = insert(table, key, M);

		ind[i] = index;
		find[i] = hashFind(table, key, M, P);
		//find[i] = table->arr[index].choosed;
	}

	for (i = 0; i<N; i++) {
		cout << ind[i] << " ";
	}
	cout << endl;

	for (i = 0; i<N; i++) {
		cout << find[i] << " ";
	}
	cout << endl;

	return 0;
}