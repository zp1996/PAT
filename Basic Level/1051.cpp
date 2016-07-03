//
//  1051.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/3.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
struct Complex
{
    double r;
    double p;
};
int main ()
{
    Complex a, b;
    double x, y, temp;
    cin>>a.r>>a.p>>b.r>>b.p;
    temp = a.r * b.r;
    x = temp * (cos(a.p) * cos(b.p) - sin(a.p) * sin(b.p));
    y = temp * (cos(a.p) * sin(b.p) + cos(b.p) * sin(a.p));
    if (abs(x) < 0.01)
        x = 0;
    if (abs(y) < 0.01)
        y = 0;
    if (y >= 0)
        printf("%.2f+%.2fi\n", x, y);
    else
        printf("%.2f-%.2fi\n", x, abs(y));
    return 0;
}
