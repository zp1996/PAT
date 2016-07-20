//
//  1011.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/20.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    char states[3] = {'W', 'T', 'L'};
    char res[3];
    double maxs[3] = {-1, -1, -1};
    double temp, price = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin>>temp;
            if (temp > maxs[i]) {
                maxs[i] = temp;
                res[i] = states[j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout<<res[i]<<" ";
        price *= maxs[i];
    }
    price = (price * 0.65 - 1) * 2;
    printf("%.2f\n", price);
    return 0;
}
