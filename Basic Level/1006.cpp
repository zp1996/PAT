#include <iostream>
#include <string>
using namespace std;
int main () 
{
	int n, len, index = 0;
	string res;
	char replacement[] = {' ', 'S', 'B'};
	cin>>n;
	while (n != 0) 
	{
		len = n % 10;
		for (int i = 0; i < len; i++) 
		{
			if (index == 0) 
			{ 
				res += (i + 1) + '0';
			}
			else 
			{
				res = replacement[index] + res;
			}
		}
		index++;
		n = n / 10;
	}
	cout<<res<<endl;
	return 0;
}