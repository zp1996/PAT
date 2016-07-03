//
//  1050.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/2.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, row, col;
void getRowCol (int n)
{
    int min = 10000, temp;
    for (int i = 1; i <= sqrt((double)n); i++) {
        temp = n / i;
        if (temp * i == n) {
            if (abs(temp - i) < min) {
                row = temp >= i ? temp : i;
                col = temp < i ? temp : i;
            }
        }
    }
}
int main ()
{
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    sort(arr, arr + N);
    getRowCol(N);
    int matrix[row][col];
    int i = 0, j = 0, count = N - 1, id = 0;
    while (count >= 0) {
        while (j < col - id && count >= 0)
            matrix[i][j++] = arr[count--];
        j--;
        i++;
        while (i < row - id && count >= 0)
            matrix[i++][j] = arr[count--];
        i--;
        j--;
        while (j >= id && count >= 0)
            matrix[i][j--] = arr[count--];
        j++;
        i--;
        while (i > id && count >= 0)
            matrix[i--][j] = arr[count--];
        id++;
        i = j = id;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0)
                cout<<matrix[i][j];
            else
                cout<<' '<<matrix[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
