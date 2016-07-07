#include <iostream>
using namespace std;
int main ()
{
    int arr[100], res[100];
    int k = 0, n;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            while (temp != 1)
            {
                if (temp & 1)
                    temp = ((3 * temp) + 1) >> 1;
                else
                    temp >>= 1;
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == temp)
                        arr[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            res[k++] = arr[i];
    }
    for (int i = 0; i < k - 1; i++)
    {
        bool flag = false;
        for (int j = k - 1; j > i; j--)
        {
            if (res[i] < res[j])
            {
                int x = res[i];
                res[i] = res[j];
                res[j] = x;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
    printf("%d", res[0]);
    for (int i = 1; i < k; i++)
    {
        printf(" %d", res[i]);
    }
    printf("\n");
}