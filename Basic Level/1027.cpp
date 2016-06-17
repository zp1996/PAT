#include <iostream>
#include <vector>
using namespace std;
void getTime (int num, int *res) 
{
	int n = 1, sum = 1;
	while (sum <= num) 
	{
		sum += (n + 2) * 2;
		n += 2;
	}
	n -= 2;
	res[0] = n;
	res[1] = num - sum + (n + 2) * 2;
}
int main () 
{
	int N;
	char output;
	cin>>N>>output;
	int res[2];
	getTime(N, res);
	int time = res[0];
	for (int i = time; i > 0; i -= 2) 
	{
		int temp = (time - i) / 2;
		for (int j = 0; j < time - temp; j++) 
		{
			if (j < temp) 
			{
				cout<<' ';
			}
			else 
			{
				cout<<output;
			}
		}
		cout<<'\n';
	}
	for (int i = 3; i <= time; i += 2) 
	{
		int temp = (time - i) / 2;
		for (int j = 0; j < time - temp; j++) 
		{
			if (j < temp) 
			{
				cout<<' ';
			}
			else 
			{
				cout<<output;
			}
		}
		cout<<'\n';
	}
	cout<<res[1]<<'\n';
	return 0;
}