//
//  1008.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/16.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
#define up 6
#define down 4
#define stop 5
int main ()
{
    int N, prev = 0, now, res = 0;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>now;
        int temp = now - prev;
        res += temp > 0 ? temp * up : (-temp * down);
        prev = now;
    }
    res += stop * N;
    cout<<res<<'\n';
    return 0;
}
