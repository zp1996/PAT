#include <iostream>
using namespace std;
int main () 
{
	int arr[100], res[100]; 
	int k = 0, n;
	cin>>n;
	if (n >= 100) throw n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] != 0) 
		{
			int temp = arr[i];
			while (temp != 1) 
			{
				if (temp % 2 == 0) 
				{
					temp = temp / 2;
				}
				else 
				{
					temp = (3 * temp) + 1;
				}
				for (int j = 0; j < n; j++) 
				{
					if (arr[j] == temp) arr[j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] != 0) 
		{
			res[k++] = arr[i];
		}
	}
	for (int i = 0; i < k - 1; i++) 
	{
		for (int j = i + 1; j < k; j++) 
		{
			if (res[i] < res[j]) 
			{
				int temp = res[i];
				res[i] = res[j];
				res[j] = temp;
			}
		}
	}
	for (int i = 0; i < k; i++) 
	{
		if (i == k - 1) 
		{
			cout<<res[i];
		}
		else 
		{
			cout<<res[i]<<" ";
		}
	}
	cout<<endl;
}