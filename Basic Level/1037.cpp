//
//  1037.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/24.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
struct Money
{
    int g, s, k;
    Money(int g1, int s1, int k1) {
        g = g1;
        s = s1;
        k = k1;
    }
};
Money calc (int a, int b) {
    int res = a - b;
    int k = res % 29;
    res -= k;
    res /= 29;
    int s = res % 17;
    res -= s;
    int g = res / 17;
    Money x(g, s, k);
    return x;
}
int main ()
{
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d", &g1, &s1, &k1);
    scanf("%d.%d.%d", &g2, &s2, &k2);
    Money res(0, 0, 0);
    int a = g1 * 29 * 17 + s1 * 29 + k1;
    int b = g2 * 29 * 17 + s2 * 29 + k2;
    if (a > b) {
        printf("-");
        res = calc(a, b);
    } else {
        res = calc(b, a);
    }
    printf("%d.%d.%d\n", res.g, res.s, res.k);
    return 0;
}
