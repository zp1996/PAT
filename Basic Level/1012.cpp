#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
	int N;
	cin>>N;
	int arr[1000];
	int A1 = 0, A2 = 0, A3 = 0, A5 = 0, flag = 0, c2 = 0, c4 = 0;
	double A4 = 0;
	for (int i = 0; i < N; i++) 
	{
		cin>>arr[i];
		int k = arr[i],x = k % 5;
		switch(x) 
		{
			case 0:
				if (k % 2 == 0) A1 += k;
			break;
			case 1:
				if (!flag) {
					A2 += k;
					flag = 1;
				}
				else {
					A2 -= k;
					flag = 0;
				}
				c2++;
			break;
			case 2:
				A3++;
			break;
			case 3:
				c4++;
				A4 = (A4 * (c4 - 1) + k) / c4;
			break;
			case 4:
				A5 = max(A5, k);
			break;
		}
	}
	A1 == 0 ? (printf("N")) : (printf("%d", A1));
	A2 == 0 && c2 == 0 ? (printf(" N")) : (printf(" %d", A2));
	A3 == 0 ? (printf(" N")) : (printf(" %d", A3));
	A4 == 0 ? (printf(" N")) : (printf(" %.1f", A4));
	A5 == 0 ? (printf(" N")) : (printf(" %d", A5));
}