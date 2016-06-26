//
//  1040.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/26.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define standard 1000000007;
int main ()
{
    string str;
    cin>>str;
    int posP = 0, posA = 0, posT = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        char ch = str[i];
        if (ch == 'P') {
            posP++;
        } else if (ch == 'A') {
            posA += posP;
        } else {
            posT += posA;
            posT = posT % standard;
        }
    }
    cout<<posT<<'\n';
    return 0;
}