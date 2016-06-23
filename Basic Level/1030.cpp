//
//  1030.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/18.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
    int N, p, count = 1;
    cin>>N>>p;
    vector<unsigned> arr;
    unsigned num;
    for (int i = 0; i < N; i++) {
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        unsigned temp = arr[i] * p;
        int j = i + count;
        while (j < N) {
            if (temp < arr[j])
                break;
            j++;
        }
        count = j - i;
    }
    cout<<count<<'\n';
    return 0;
}
