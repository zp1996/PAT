#include <iostream>
#include <string>
using namespace std;
int main () 
{
	string a, res;
	int b;
	cin>>a>>b;
	int len = a.size(), i =0, temp = 0;
	if (len == 1) 
	{
		temp = a[0] - '0';
		cout<<temp / b;
		temp = temp % b; 
	}
	else
	{
		while (i < len) 
		{
			temp = i == 0 ? a[i] - '0' : temp;
			if (temp < b && i <= len - 1) 
			{
				i = i == 0 ? (++i) : i;
				temp = temp * 10 + (a[i] - '0');
			}
			cout<<temp / b;
			temp = temp % b;
			i++;
		}
	}
	cout<<" "<<temp<<endl;
}