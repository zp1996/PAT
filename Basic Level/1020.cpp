#include <iostream>

using namespace std;
struct MoonCake
{
    double all_price;
    double count;
    double price;
};
void QuickFun(MoonCake arr[], int left, int right)
{
    if (left >= right) return;
    int i = left, j = right;
    MoonCake current = arr[i];
    while (i < j)
    {
        while (arr[j].price < current.price && i < j)
            j--;
        while (arr[i].price >= current.price && i < j)
            i++;
        if (i < j)
        {
            MoonCake temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j];
    arr[j] = current;
    QuickFun(arr, left, j - 1);
    QuickFun(arr, j + 1, right);
}
void QuickSort (MoonCake arr[], int len)
{
    QuickFun(arr, 0, len - 1);
}
int main ()
{
    int Types, Count, index = 0;
    MoonCake cakes[1000];
    double res = 0;
    cin>>Types>>Count;
    for (int i = 0; i < Types; i++)
        cin>>cakes[i].count;
    for (int i = 0; i < Types; i++)
    {
        cin>>cakes[i].all_price;
        cakes[i].price = cakes[i].all_price / cakes[i].count;
    }
    QuickSort(cakes, Types);
    while (Count > 0 && index < Types)
    {
        if (Count >= cakes[index].count)
        {
            res += cakes[index].all_price;
            Count -= cakes[index].count;
        }
        else
        {
            res += cakes[index].price * Count;
            Count -= Count;
        }
        index++;
    }
    printf("%.2f\n", res);
}