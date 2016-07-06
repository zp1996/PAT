//
//  1054.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/5.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int N;
int main ()
{
    int count = 0;
    double res = 0;
    cin>>N;
    string str;
    for (int i = 0; i < N; i++) {
        cin>>str;
        int len = (int)str.size(),
            dight = 1,
            x = 0, j = 0;
        double temp = 0;
        bool a = true, b = true;
        for (; j < len; j++) {
            char ch = str[j] - '0';
            if (j == 0 && str[j] == '-') {
                a = false;
                continue;
            } else if (ch < 10 && ch >= 0) {
                temp = temp * 10 + ch;
                if (!b){
                    if (j - x <= 2)
                        dight *= 10;
                    else
                        break;
                }
            } else if (str[j] == '.' && b) {
                b = false;
                x = j;
            } else {
                break;
            }
        }
        if (j == len) {
            if (a)
                temp /= dight;
            else
                temp = (0 - temp) / dight;
            if (temp <= 1000 && temp >= -1000) {
                res += temp;
                count++;
            } else {
                printf("ERROR: %s is not a legal number\n", str.c_str());
            }
        } else {
            printf("ERROR: %s is not a legal number\n", str.c_str());
        }
    }
    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (count == 1)
        printf("The average of %d number is %.2f\n", count, res / count);
    else
        printf("The average of %d numbers is %.2f\n", count, res / count);
    return 0;
}
