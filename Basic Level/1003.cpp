#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	if (n >= 10) 
	{
		throw n;
	}
	while (n--)
	{
		string str;
		cin>>str;
		int len = str.size(), posp = 0, post = 0, p = 0, t = 0; 
		bool flag = true;
		for (int i = 0; i < len; i++) 
		{
			if (!(str[i] == 'P' || str[i] == 'A' || str[i] == 'T')) 
			{
				flag = false;
				break;
			}
			if (str[i] ==  'P') 
			{
				posp = i;
			}
			if (str[i] == 'T')
			{
				post = i;
			}
		}
		if (!flag) 
		{
			cout<<"NO"<<endl;
		} 
		else 
		{
			int a = posp - 0;
			int b = post - posp - 1;
			int c = len - 1 - post;
			if (a == c && b >= 1) 
			{
				cout<<"YES"<<endl;
			}
			else if (c && c == a * b) 
			{
				cout<<"YES"<<endl;
			}
			else 
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}