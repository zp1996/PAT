//
//  1044.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/28.
//  Copyright © 2016年 zp1996. All rights reserved.
//


#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
    char rem[][5] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char high[][5] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int N, len;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char input[10];
        gets(input);
        len = (int)strlen(input);
        if (input[0] - '0' < 10) {
            int x = atoi(input);
            if (x == 0)
                cout<<"tret";
            int a = x / 13, b = x % 13;
            if (a)
                cout<<high[a - 1];
            if (a && b)
                cout<<" ";
            if (b)
                cout<<rem[b - 1];
            cout<<'\n';
        } else {
            int id = 0;
            for (int i = 0; i < 12; i++) {
                if (strstr(input, high[i]))
                    id += (i + 1) * 13;
                if (strstr(input, rem[i])) {
                    id += (i + 1);
                }
            }
            cout<<id<<'\n';
        }
    }
    return 0;
}
