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
void Merge (int* arr, int* temp, int left, int mid, int right)
{
    int i = left, m = mid, j = mid, n = right, k = 0;
    while (i < m && j < n) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i < m)
        temp[k++] = arr[i++];
    while (j < n)
        temp[k++] = arr[j++];
    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
}
void MergeSort (int* arr, int len, int* arr2)
{
    int* temp = new int[len];
	bool flag = true;
    for (int i = 1; i < len; i *= 2) {
        // i is the length of already sort child list
        for (int j = 0; j < len; j += 2 * i) {

            if (j + 2 * i <= len)
                Merge(arr, temp, j, j + i, j + 2 * i);
            else if (j + 2 * i > len && j + i <= len)
                Merge(arr, temp, j, j + i, len);
        }
		if (!flag) 
		{
			for (int i = 0; i < len - 1; i++) 
			{
				cout<<arr[i]<<' ';
			}
			cout<<arr[len - 1]<<'\n';
			return;
		}
		if (judge(arr, arr2, len)) 
		{
			flag = false;
			cout<<"Merge Sort\n";
		}
    }
	delete[] temp;
}
int main () 
{
	int N, arr1[100], arr2[100], temp1[100], temp2[100];
	cin>>N;
	for (int i = 0; i < N; i++) 
	{
		cin>>arr1[i];
		temp1[i] = arr1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin>>arr2[i];
		temp2[i] = arr2[i];
	}
	if (InsertSort(arr1, arr2, N)) 
	{
		MergeSort(temp1, N, temp2);
	}
 	return 0;
}