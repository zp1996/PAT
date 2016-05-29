#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main () 
{
	char str[90];
	gets(str);
	string arr[80];
	string temp = "";
	int index = 0, len = strlen(str);
	for (int i = 0; i <= len; i++) 
	{
		if (str[i] == ' ' || i == len) 
		{
			arr[index++] = temp;
			temp = "";
		}
		else 
		{
			temp += str[i];
		}
	}
	for (int i = index - 1; i >= 0; i--) 
	{
		if (i == index - 1) cout<<arr[i];
		else cout<<" "<<arr[i];
	}
	return 0;
}