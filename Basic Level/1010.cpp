#include <iostream>
#include <cstring>
using namespace std;
int main () 
{
	int index, ratio, flag = 0;
	while (scanf("%d%d", &ratio, &index) != EOF) 
	{
		if (index * ratio)
		{
			if (flag) 
			{
				cout<<" ";
			}
			else 
			{
				flag = 1;
			}
			cout<<index * ratio<<" "<<(index - 1);
		}
	}
	// ʲô��û����,Ҳ���������ʽ
	if (!flag) cout<<"0 0";
	return 0;
}