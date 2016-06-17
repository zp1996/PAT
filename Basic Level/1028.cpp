#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
struct Person
{
	int birthInt;
	string name;
	string birth;
};
int main () 
{
	const int Today = 20140906; 
	int N;
	cin>>N;
	Person old, young;
	int count = 0, minBirth = INT_MAX, maxBirth = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		Person temp;
		cin>>temp.name>>temp.birth;
		int j = (int)temp.birth.size() - 1, start = 1;
		temp.birthInt = 0;
		for (; j >= 0; j--) 
		{
			if (temp.birth[j] != '/') 
			{	
				temp.birthInt += (temp.birth[j] - '0') * start;
				start *= 10;
			}
		}
		if (temp.birthInt <= Today && temp.birthInt >= Today - 2000000) 
		{
			count++;
			if (temp.birthInt > maxBirth) 
			{
				young = temp;
				maxBirth = temp.birthInt;
			}
			if (temp.birthInt < minBirth) 
			{
				old = temp;
				minBirth = temp.birthInt;
			}
		}
	}
	if (count) 
		cout<<count<<' '<<old.name<<' '<<young.name<<'\n';
	else 
		cout<<0;
	return 0;
}