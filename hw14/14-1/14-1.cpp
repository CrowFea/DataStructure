#include<iostream>
using namespace std;

#define MAXSIZE 100000

typedef  int ElemType;

void Input(ElemType arr[],int n)
{
	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return;
}

int halfIntervalSearch(ElemType arr[], ElemType tar,int n)
{
	int low = 0, high = n - 1;
	int mid,i;

	while (high - low > 1) {
		mid = (high + low) / 2;
		
		if (arr[mid] == tar) {
			
			for (i = mid;i>=low; i--) {
				if (arr[i] == arr[mid]) {
					mid = i;
				}
			}
			
			return mid;
		}
		else if (arr[mid] < tar) {
			low = mid;
			continue;
		}
		else {
			high = mid;
			continue;
		}
		
	}

	return -1;
}

int main()
{
	ElemType arr[MAXSIZE];
	int n;
	cin >> n;
	Input(arr,n);
	int findNum,tar;
	cin >> findNum;
	while (findNum) {
		cin >> tar;
		cout<<halfIntervalSearch(arr, tar, n);
		cout << endl;
		findNum--;
	}
	return 0;
}