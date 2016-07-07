#include <iostream>
#include <cmath>
using namespace std;
bool isPrime (int n) 
{
	bool res = true;
	for (int j = 2; j <= sqrt((float)n); j++) 
	{
		if (n % j == 0) {
			res = false;
			break;
		}
	}
	return res;
}
int main () 
{
	int n;
	int len = 0, res = 0;
	cin>>n;
	for (int i = 2; i <= n - 2; i++) 
	{
		if ( isPrime(i) && isPrime(i + 2) ) 
		{
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}