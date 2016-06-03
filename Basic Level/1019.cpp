#include <iostream>
#include <string>
using namespace std;
int SortNum (string num) 
{
	int len = num.size();
	string temp = "";
	int a = 0, b = 0, res = 0;
	for (int i = 0; i < len; i++) 
	{
		char current = num[i];
		int j = i - 1;
		while (j >= 0 && num[j] < current) 
		{
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = current;
	}
	for (int i = 0; i < len; i++) 
	{
		a = a * 10 + (num[i] - '0');
		temp += num[len - 1 - i];
		b = b * 10 + (num[len - 1 - i] - '0');
	}
	res = a - b;
	cout<<a<<" - "<<temp<<" = "<<res<<'\n';
	return res;
}
string intToString(int a) 
{
	string res = "";
	while (a != 0) 
	{
		res += a % 10 + '0';
		a /= 10;
	}
	return res;
}
int main () 
{
	int N;
	cin>>N;
	string num;
	int res = -1;
	for (int i = 0; i < 4; i++) 
	{
		num += N % 10 + '0';
		N /= 10;
	}
	if (num[0] == num [1] && num[1] == num[2] && num[2] == num[3]) 
	{
		cout<<num<<" - "<<num<<" = 0000"<<endl;
		return 0;
	}
	while (res != 0 && res != 6174) 
	{
		res = SortNum(num);
		num = intToString(res);
	}
	return 0;
}