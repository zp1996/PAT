//
//  1048.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/1.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main ()
{
    string a, b, res = "";
    char chs[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    int temp;
    cin>>a>>b;
    int lenA = (int)a.size(), lenB =(int)b.size();
    int len = max(lenA, lenB);
    int k = 1;
    // start 蛋疼的补位
    while (lenA < len) {
        a = '0' + a;
        lenA++;
    }
    while (lenB < len) {
        b = '0' + b;
        lenB++;
    }
    // end 蛋疼的补位
    int i = len - 1;
    while (k <= len) {
        if (k % 2 != 0) {
            temp = a[i] - '0' + b[i] - '0';
            res = chs[temp % 13] + res;
        } else {
            temp = b[i] - a[i];
            temp = temp < 0 ? temp + 10 : temp;
            res = (char)(temp + '0') + res;
        }
        k++;
        i--;
    }
    cout<<res<<endl;
    return 0;
}
