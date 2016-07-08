//
//  1.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/8.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main ()
{
    int a, b;
    cin>>a>>b;
    int res = a + b;
    string temp = "";
    bool flag = res < 0 ? true: false;
    res = abs(res);
    int count = 0;
    while (res != 0 || count == 0) {
        int a = res % 10;
        if (count % 3 == 0 && count != 0)
            temp = ',' + temp;
        temp = (char)(a + '0') + temp;
        count++;
        res /= 10;
    }
    if (flag) {
        cout<<'-';
    }
    cout<<temp<<endl;
    return 0;
}
