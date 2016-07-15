//
//  1005.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string str;
    string dight[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (cin>>str) {
        string res = "";
        int len = (int)str.size(), sum = 0;
        for (int i = 0; i < len; i++) {
            sum += str[i] - '0';
        }
        if (sum == 0) {
            cout<<dight[0]<<'\n';
            continue;
        }
        while (sum != 0) {
            res = dight[sum % 10] + res;
            sum /= 10;
            if (sum != 0) {
                res = " " + res;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
