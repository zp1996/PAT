//
//  1043.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/27.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define source "PATest"
#define len 6
int has (char val)
{
    for (int i = 0; i < len; i++) {
        if (source[i] == val) {
            return i;
        }
    }
    return -1;
}
int main ()
{
    string str;
    int agg[6] = {0};
    int index, id = 0, all = 0;
    char val;
    cin>>str;
    for (int i = 0; i < (int)str.size(); i++) {
        val = str[i];
        index = has(val);
        if (index != -1) {
            agg[index]++;
            all++;
        }
    }
    while (all) {
        if (agg[id] > 0) {
            cout<<source[id];
            agg[id]--;
            all--;
        }
        id = id == len - 1 ? 0 : (id + 1);
    }
    cout<<'\n';
    return 0;
}
