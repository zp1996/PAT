#include <iostream>
#include <cmath>
#include <string>
#include <cmath>
using namespace std;
struct Datas 
{
	string lineone, linetwo, linethree, linefour;
	char res[2];
	void findDH () 
	{
		int len = min(lineone.size(), linetwo.size());
		int count = 0;
		for (int i = 0; i < len; i++) 
		{
			char temp = lineone[i];
			if (temp == linetwo[i]) 
			{
				if (count == 0 && temp <= 'G' && temp >= 'A') 
					res[count++] = temp;
				else if (count != 0 && (temp <= 'Z' && temp >= 'A' || temp >= 48 && temp <= 57))
					res[count++] = temp;
			}
			if (count == 2) 
			{
				break;
			}
		}
	}
	int findMin () 
	{
		int i = 0;
		int len = min(linethree.size(), linefour.size());
		for (; i < len; i++) 
		{
			char temp = linethree[i];
			if (temp == linefour[i] && (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) 
			{
				break;
			}
		}
		return i;
	}
};
int main () 
{
	string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	Datas datas;
	cin>>datas.lineone>>datas.linetwo>>datas.linethree>>datas.linefour;
	datas.findDH();
	char *dh = datas.res;
	cout<<days[dh[0] - 'A']<<" ";
	int hour = (int)dh[1];
	hour = hour < 57 ? (hour - 48) : hour - 'A' + 10;
	hour < 10 ? (cout<<"0"<<hour<<":") : (cout<<hour<<":");
	int minutes = datas.findMin();
	minutes< 10 ? (cout<<"0"<<minutes) : (cout<<minutes);
	return 0;
}