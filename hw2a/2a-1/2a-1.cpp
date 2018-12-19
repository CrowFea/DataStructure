#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

void shellSort(int arr[], int len)
{
	int j = 0, tmp = 0;
	for (int d = len / 2; d >0; d /= 2) {
		for (int i = d; i <len; i++) {
			j = i - d;
			tmp = arr[i];
			while (j >= 0 && arr[j]>tmp) {
				arr[j + d] = arr[j];
				j -= d;
			}
			arr[j + d] = tmp;
		}
	}
}
void straightInsertSort(int arr[], int len) {
	for (int i = 2; i <= len; i++) {
		arr[0] = arr[i];
		int j;
		for (j = i - 1; arr[0]<arr[j]; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = arr[0];
	}
}
int Cal(ElemType arr[MAXSIZE], int n)
{
	int i, j, len = n;
	int sum = 0, leaf = 0;
	while (1) {
		i = 0;
		j = 0;
		if (n == 1) {
			return sum;
		}
		shellSort(arr, len);
		//straightInsertSort(arr, len);
		while (arr[i] == -1) {
			i++;
		}
		j = i + 1;
		while (arr[j] == -1) {
			j++;
		}
		leaf = arr[i] + arr[j];
		sum += leaf;
		arr[j] = leaf;
		arr[i] = -1;
		n--;
	}
}

int main()
{
	int n;
	ElemType arr[MAXSIZE];
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		arr[i] = -1;
	}
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << Cal(arr, n) << endl;
	return 0;

}