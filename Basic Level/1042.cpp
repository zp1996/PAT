//
//  1042.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/27.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string str;
    char ch;
    int max = 0;
    int chs[26] = {0};
    getline(cin, str, '\n');
    for (int i = 0; i < (int)str.size(); i++) {
        ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
            chs[ch - 'A']++;
        else if (ch >= 'a' && ch <= 'z')
            chs[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (chs[i] > max) {
            max = chs[i];
            ch = i + 'a';
        }
    }
    cout<<ch<<' '<<max<<'\n';
    return 0;
}
