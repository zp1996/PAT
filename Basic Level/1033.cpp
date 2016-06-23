//
//  1033.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/20.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main ()
{
    char bad[100001], input[100001];
    bool chars[128];
    gets(bad);
    gets(input);
    for (int i = 0; i < 128; i++) {
        chars[i] = false;
    }
    for (int i = 0; bad[i]; i++) {
        chars[bad[i]] = true;
        if (isupper(bad[i]))
            chars[tolower(bad[i])] = true;
    }
    if (chars['+']) {
        for (char i = 'A'; i <= 'Z'; i++) {
            chars[i] = true;
        }
    }
    for (int i = 0; input[i]; i++) {
        if (!chars[input[i]])
            cout<<input[i];
    }
    cout<<'\n';
    return 0;
}
