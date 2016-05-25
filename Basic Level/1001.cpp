#include <iostream>
using namespace std;
int main () 
{
	int n, res = 0;
	cin>>n;
	if (n <= 0 || n > 1000) 
	{
		throw n;
	}
	while (n != 1) 
	{
		res++;
		if (n % 2 == 0) 
		{
			n = n / 2;
		} 
		else 
		{
			n = (3 * n + 1) / 2;
		}
	}
	cout<<res<<endl;
	return 0;
}