#include <iostream>
#include <cmath>
using namespace std;
int getMaxCM (int a, int b) 
{
	int len = min(a, b), res = 0;
	for (int i = 2; i <= len; i++) 
	{
		if (a % i == 0 && b % i == 0) 
		{
			res = i;
		}
	}
	return res;
}
void changePos(int len, int m, int *arr) 
{
	m %= len;
	if (m == 0) return;
	for (int i = 0; i < getMaxCM(len, m); i++) 
	{
		int k = i, t = arr[k];
		do 
		{
			k = (k + m) % len;
			int tt = arr[k];
			arr[k] = t;
			t =tt;
		} while (k != i);
	}
}
int main () 
{
	int n, m, arr[100];
	cin>>n;
	cin>>m;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	changePos(n, m, arr);
	for (int i = 0; i < n; i++)
	{
		if (i == 0) 
		{
			cout<<arr[i];
		}
		else 
		{
			cout<<" "<<arr[i];
		}
	}
}