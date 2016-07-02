//
//  1049.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/2.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main ()
{
    int N;
    cin>>N;
    double res = 0, temp;
    for (int i = 0; i < N; i++) {
        cin>>temp;
        res += (i + 1) * temp * (N - i);
    }
    printf("%.2f\n", res);
    return 0;
}
