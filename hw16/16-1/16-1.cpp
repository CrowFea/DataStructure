#include <iostream>
using namespace std;

//直接插入排序
void straightInsertSort(int[] arr, int len)
{
    int high = 0;
    int i = 0, j = 0, inValue = 0;
    while (high < len - 1)
    {
        i = high;
        inValue = arr[i];
        while (i >= 0 && inValue > arr[i])
        {
            i--;
        }
        for (j = high; j >= i; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[i + 1] = inValue;
        high++;
    }
}

//折半插入排序
void binary_insertion_sort(int arr[], int len)
{
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++){
        temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high){
            m = (low + high) / 2;
            if (arr[m] > temp){
                high = m - 1;
            }
            else{
                low = m + 1;
            }
        }
    }
    for (j = i - 1; j >= high + 1; j--)
        arr[j + 1] = arr[j];
    arr[j + 1] = temp;
}

//希尔排序
void shellSort(int arr[], int len)
{
    int j = 0, tmp = 0;
    for (int d = len / 2; d > 0; d /= 2)
    {
        for (int i = d; i < len; i++)
        {
            j = i - d;
            tmp = arr[i];
            while (j >= 0 && arr[j] > tmp)
            {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = tmp;
        }
    }
}

//冒泡排序
void swap(int *arr,int i,int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void bubble_sort1(int *arr,int len){
    int max = len-1;
    int i,j;
    for(i=0;i<max;i++){
        for(j=0;j<max-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr,j,j+1);
            }
        }
    }
}


//快速排序
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end) return;
    int base = arr[end];
    int left = start, right = end - 1;  
    while (true) {
        while (arr[left] < base) ++left;
        while (arr[right] >= base) --right;
        if (left >= right) break;
        swap(arr[left], arr[right]);   
    }
    if (arr[left] >= arr[end]) swap(arr[left], arr[end]);  
    else ++left;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

//选择排序
void selectSort(int arr[], int len)
{
    int i, j, temp = 0;
    for (i = 0; i < len - 1; i++){
        for (j = i; j < len - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//归并排序

void Merge(int a[],int left,int mid,int right)
{
	//两段区间的长度
	int length1 = mid-left+1;
	int length2 = right-mid;
 
	//分配两段新的内存空间存储原内容
	int *l1 = new int[length1];
	int *l2 = new int[length2];
 
	for (int i = 0; i < length1; ++i)
	{
		l1[i] = a[left+i];
	}
	for (int j = 0; j < length2; ++j)
	{
		l2[j] = a[j+mid+1];
	}
 
	//存入原内容之后，比较两个序列
	int i = 0,j = 0;
	int k = length1;
	//比较两个序列的重合部分，进行排序
	while (i<length1 && j<length2)
	{
		if (l1[i] < l2[j])
		{
			a[left++] = l1[i++];
		}
		else
		{
			a[left++] = l2[j++];
			//因为l2[j]大于l1[i],所以l2[j]肯定大于[0,length-1]之中[0,i]之间的所有数，产生逆序对
			if (l2[j] > l1[i])
			{
				_count +=  length1-i+1;
			}		
		}
	}
	//两序列的剩余部分分别放于结尾
	while (i<length1){
		a[left++] = l1[i++];
	}
 
	while (j<length2){
		a[left++] = l2[j++];
	}
 
	delete []l1;
	delete []l2;
}
void Merge_sort(int a[],int left,int right)
{
	if (left < right){
		int mid = (left+right)/2;
		Merge_sort(a,left,mid);
		Merge_sort(a,mid+1,right);
		Merge(a,left,mid,right);
	}

}


//堆排序
void Heap_build(int a[],int root,int length)
{
	int lchild = root*2+1;//根节点的左子结点下标
	if (lchild < length)//左子结点下标不能超出数组的长度
	{
		int flag = lchild;//flag保存左右节点中最大值的下标
		int rchild = lchild+1;//根节点的右子结点下标
		if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
		{
			if (a[rchild] > a[flag])//找出左右子结点中的最大值
			{
				flag = rchild;
			}
		}
		if (a[root] < a[flag])
		{
			//交换父结点和比父结点大的最大子节点
			Swap(a[root],a[flag]);
			//从此次最大子节点的那个位置开始递归建堆
			Heap_build(a,flag,length);
		}
	}
}
 
void Heap_sort(int a[],int len)
{
	for (int i = len/2; i >= 0; --i)//从最后一个非叶子节点的父结点开始建堆
	{
		Heap_build(a,i,len);
	}
 
	for (int j = len-1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
	{
		Swap(a[0],a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
		Heap_build(a,0,j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
	}
}

void print(int arr[],int len)
{
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    straightInsertSort(arr,n);
    halfIntervalSearch(arr,n);
    bubble_sort1(arr,n);
    quick_sort_recursive(arr,0,n-1);
    selectSort(arr,n);
    Merge_sort(arr,0,n-1);
    Heap_sort(arr,n);
    print(arr,n);
    return 0;
}