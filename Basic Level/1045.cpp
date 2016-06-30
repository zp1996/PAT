//
//  1045.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/28.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int maxSize = 100000;
int arr[maxSize];
bool res[maxSize];
vector<int> sure;
int N;
int main ()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int current = arr[0];
    for (int i = 0; i < N; i++) {
        current = max(current, arr[i]);
        if (current > arr[i])
            res[i] = true;
    }
    current = arr[N - 1];
    for (int i = N - 1; i >= 0; i--) {
        current = min(current, arr[i]);
        if (current < arr[i])
            res[i] = true;
    }
    for (int i = 0; i < N; i++) {
        if (!res[i])
            sure.push_back(arr[i]);
    }
    int len = (int)sure.size();
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        if (i == 0)
            printf("%d", sure[i]);
        else
            printf(" %d", sure[i]);
    }
    cout<<'\n';
    return 0;
}
