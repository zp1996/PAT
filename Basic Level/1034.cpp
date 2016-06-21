//
//  1034.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/20.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
typedef long long l;
void handleArr (l* arr)
{
    bool flag = arr[1] < 0;
    if (arr[0] == 0) {
        cout<<"Inf";
        return;
    }
    if (flag)
        cout<<'(';
    l a = arr[1] / arr[0];
    l b = arr[1] % arr[0];
    if (a == 0 && b != 0)
        cout<<b<<'/'<<arr[0];
    else if (b == 0)
        cout<<a;
    else
        cout<<a<<" "<<abs(b)<<'/'<<arr[0];
    if (flag)
        cout<<')';
}
l gcd (l a, l b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
void simplify (l* res)
{
    l i = abs(gcd(res[0], res[1]));
    if (i == 0)
        return;
    res[0] /= i;
    res[1] /= i;
}
void calc (l* arrA, l* arrB, char ch)
{
    l res[2];
    res[0] = arrA[0] * arrB[0];
    switch (ch) {
        case '+':
            res[1] = arrA[1] * arrB[0] + arrB[1] * arrA[0];
            break;
            
        case '-':
            res[1] = arrA[1] * arrB[0] - arrB[1] * arrA[0];
            break;
        case '*':
            res[1] = arrA[1] * arrB[1];
            break;
        case '/':
            res[0] = arrA[0] * arrB[1];
            if (res[0] == 0) {
                cout<<"Inf\n";
                return;
            } else {
                res[1] = arrA[1] * arrB[0];
                res[1] = res[0] < 0 ? 0 - res[1] : res[1];
                res[0] = abs(res[0]);
            }
            break;
    }
    simplify(res);
    handleArr(res);
    cout<<'\n';
}
int main ()
{
    l a1, a2, b1, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &a2, &b1, &b2);
    l arrA[2] = {a2, a1}, arrB[2] = {b2, b1};
    char ch[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        handleArr(arrA);
        cout<<" "<<ch[i]<<" ";
        handleArr(arrB);
        cout<<" = ";
        calc(arrA, arrB, ch[i]);
    }
    return 0;
}
