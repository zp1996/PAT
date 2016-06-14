#include <iostream>
#include <cmath>
using namespace std;
#define CLK_TCK 100
void Output (int x) 
{
	if (x < 10) {
		cout<<'0'<<x;
	} else {
		cout<<x;
	}
}
int main () 
{
	int start, end, hours, minutes;
	cin>>start>>end;
	int alltimes = end - start;
	hours = alltimes / 3600 / CLK_TCK;
	Output(hours);
	cout<<':';
	int mintimes = alltimes - hours * 3600 * CLK_TCK;
	minutes = (mintimes) / 60 / CLK_TCK;
	Output(minutes);
	cout<<':';
	double sectimes = mintimes - minutes * 60 * CLK_TCK;
	double seconds = sectimes / CLK_TCK;
	Output((int)(seconds + 0.5));
	cout<<'\n';
	return 0;
}