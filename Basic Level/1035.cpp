#include <iostream>
using namespace std;
bool judge (int* arr1, int* arr2, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}
bool InsertSort (int* arr, int* target, int len) 
{
	bool flag = true;
	for (int i = 1; i < len; i++) 
	{
		int j = i - 1, current = arr[i];
		while (j >= 0 && arr[j] > current) 
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
		if (!flag) 
		{
			for (int i = 0; i < len - 1; i++) 
			{
				cout<<arr[i]<<' ';
			}
			cout<<arr[len - 1]<<'\n';
			return flag;
		}
		if (judge(arr, target, len)) 
		{
			flag = false;
			cout<<"Insertion Sort\n";
		}
	}
	return flag;
}
void MergeArray (int* arr, int* temp, int left, int mid, int right) 
{
	int i = left, m = mid, j = mid + 1, n = right, k = 0;
	while (i <= m && j <= n) 
	{
		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= m)
		temp[k++] = arr[i++];
	while (j <= n)
		temp[k++] = arr[j++];
	for (int x = 0; x < k; x++) 
		arr[left + x] = temp[x];
}
void MSort (int* arr, int left, int right, int* temp) 
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	// sort the left part
	MSort(arr, left, mid, temp);
	// sort the right part
	MSort(arr, mid + 1, right, temp);
	// merge two part
	MergeArray(arr, temp, left, mid, right);
}
void MergeSort (int* arr, int N) 
{
	int* temp = new int[N];
	for (int len = 1; len < N; len *= 2) 
	{
		for (int i = 0; i < N; i += 2 * len) 
		{
			if (i + 2 * len <= N)
				MergeArray(arr, temp, i, i + len, i + 2 * len - 1);
			else if (i + 2 * len > N && i + len <= N) 
				MergeArray(arr, temp, i, i + len, N - 1);				
		}
	}
	delete[] temp;
}
int main () 
{
	//int N, arr1[100], arr2[100];
	//cin>>N;
	//for (int i = 0; i < N; i++) 
	//	cin>>arr1[i];
	//for (int i = 0; i < N; i++) 
	//	cin>>arr2[i];
	//if (!InsertSort(arr1, arr2, N)) 
	//{
	//	int target[100];
	//	for (int i = 0; i < N; i++) 
	//	{
	//		target[i] = i;
	//	}
	//}
	int arr[] = {1, 11, 17, 20, 22, 13, 16, 19, 90, 80};
	MergeSort(arr, 10);
	for (int i = 0; i <= 9; i++) 
	{
		cout<<arr[i]<<" ";
	}
 	return 0;
}