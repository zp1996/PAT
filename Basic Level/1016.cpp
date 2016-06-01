#include <iostream>
#include <string>
using namespace std;
int main () 
{
	string A, B;
	char Da, Db;
	cin>>A>>Da>>B>>Db;
	int x = 0, y = 0, startX = 1, startY = 1;
	for (int i = 0; i < A.size(); i++) 
	{
		if (A[i] == Da) 
		{
			x += (Da - '0') * startX;
			startX *= 10;
		}
	}
	for (int i = 0; i < B.size(); i++) 
	{
		if (B[i] == Db) 
		{
			y += (Db - '0') * startY;
			startY *= 10;
		}
	}
	cout<<x + y<<endl;
	return 0;
}