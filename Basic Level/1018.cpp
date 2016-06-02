#include <iostream>
#include <cmath>
using namespace std;
inline void Count (char x, int arr[3]) 
{
	switch(x)
	{
		case 'B':
			arr[0]++;
			break;
		case 'C':
			arr[1]++;
			break;
		case 'J':
			arr[2]++;
			break;
	}
}
int main () 
{
	int N, jias[] = {0, 0, 0}, yis[] = {0, 0, 0}, jiaW = 0, yiW = 0, dogfall = 0;
	int jiaIndex, yiIndex, jiaM = -1, yiM = -1;
	char res[] = {'B', 'C', 'J'};
	cin>>N;
	for (int i = 0; i < N; i++) 
	{
		char jia, yi;
		cin>>jia>>yi;
		if (jia == 'B' && yi == 'C' || jia == 'C' && yi == 'J' || jia == 'J' && yi == 'B') 
		{
			jiaW++;
			Count(jia, jias);
		} 
		else if (jia == 'C' && yi == 'B' || jia == 'J' && yi == 'C' || jia == 'B' && yi == 'J') 
		{
			yiW++;
			Count(yi, yis);
		}
		else 
		{
			dogfall++;
		}
	}
	cout<<jiaW<<" "<<dogfall<<" "<<yiW<<"\n";
	cout<<yiW<<" "<<dogfall<<" "<<jiaW<<"\n";
	for (int i = 0; i < 3; i++) 
	{
		if (jias[i] > jiaM) 
		{
			jiaM = jias[i];
			jiaIndex = i;
		}
		if (yis[i] > yiM) 
		{
			yiM = yis[i];
			yiIndex = i;
		}
	}
	cout<<res[jiaIndex]<<" "<<res[yiIndex]<<endl;
}