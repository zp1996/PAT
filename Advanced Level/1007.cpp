//
//  1007.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/15.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
int k;
int main ()
{
    int maxSum = -0xfffffff, start = 0, end = 0, sum =  -0xfffffff, s = 0;
    int arr[10000];
    cin>>k;
    arr[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin>>arr[i];
        if (sum + arr[i] < arr[i]) {
            sum = arr[i];
            s = i;
        } else
            sum += arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            end = arr[i];
            start = arr[s];
        }
    }
    if (maxSum < 0 && start < 0 && end < 0)
        cout<<0<<" "<<arr[1]<<" "<<arr[k]<<"\n";
    else
        cout<<maxSum<<" "<<start<<" "<<end<<"\n";
    return 0;
}
