//
//  1021.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/10.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string N;
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    cin>>N;
    while (i < N.size()) {
        arr[N[i++] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            cout<<i<<":"<<arr[i]<<'\n';
        }
    }
    return 0;
}