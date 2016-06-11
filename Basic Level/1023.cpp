//
//  1023.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/11.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    const int len = 10;
    int arr[len];
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool flag = false;
    int start = 1;
    for (int i = 0; i < 10; i++) {
        cin>>arr[i];
    }
    for (; start < 10; start++) {
        if (arr[start] != 0) {
            flag = true;
            break;
        }
    }
    if (flag) {
        if (arr[0] != 0) {
            arr[start] -= 1;
            cout<<num[start];
        }
        for (int i = 0; i < len; i++) {
            int temp = arr[i];
            for (int j = 0; j < temp; j++) {
                cout<<num[i];
            }
        }
        cout<<"\n";
    }
}