//
//  1036.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/22.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    int N;
    char c;
    cin>>N>>c;
    int len = (int)(N / 2.0 + 0.5);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == len - 1 || j == 0 || j == N - 1) {
                cout<<c;
            } else {
                cout<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}
