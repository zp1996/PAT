#include <iostream>
#include <string>
using namespace std;
int main () 
{
	int res = 0;
	string str;
	cin>>str;
	for (int i = 0; i < str.size(); i++) 
	{
		res += str[i] - '0'; 
	}
	res = res > 0 ? res : 0;
	if (res > 891) 
	{
		throw "数字超过10的100次方";
	}
	string chinese[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	str = "";
	bool flag = true;
	while (res != 0)
	{
		if (flag) 
		{
			str = chinese[res % 10];
			flag = false;
		} 
		else 
		{
			str = chinese[res % 10] + ' ' + str;
		}
		res = res / 10;
	}
	cout<<str<<endl;
	return 0;
}