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
	int M, N;
	cin>>M>>N;
	int count = 1, pos = 1, start = 2;
	while (M <= N) 
	{
		if (isPrime(start)) 
		{
			if (pos == M) 
			{
				if (count % 10 == 1) 
				{
					count == 1 ? (cout<<start) : (cout<<'\n'<<start);
				} 
				else
				{
					cout<<" "<<start;
				}
				M++;
				count++;
			}
			pos++;
		}
		start++;
	}
	return 0;
}