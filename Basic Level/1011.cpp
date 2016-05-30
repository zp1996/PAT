#include <iostream>
using namespace std;
int main () 
{
	int T;
	cin>>T;
	long a, b, c;
	for (int i = 0; i < T; i++) 
	{
		cin>>a>>b>>c;
		if (a + b > c) 
		{
			cout<<"Case #"<<(i + 1)<<": true"<<endl;
		}
		else 
		{
			cout<<"Case #"<<(i + 1)<<": false"<<endl;
		}
	}
}