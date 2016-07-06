//
//  1052.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/4.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define len 5
#define chLen 3
int N;
int main ()
{
    vector<string> chs[3];
    string str, temp = "";
    int line = 0;
    char c;
    while ((c = getchar()) != '\n' || line != 2) {
        if (c == '[' || c == ' ')
            continue;
        else if (c == '\n')
            line++;
        else if (c == ']') {
            chs[line].push_back(temp);
            temp = "";
        } else
            temp += c;
    }
    int x, num;
    cin>>N;
    for (int i = 0; i < N; i++) {
        temp = "";
        int j = 0;
        for (; j < len; j++) {
            cin>>num;
            x = j > chLen - 1 ? (len - 1 - j) : j;
            if (num > (int)chs[x].size() || num <= 0) {
                cout<<"Are you kidding me? @\\/@";
                break;
            } else {
                if (j == 1)
                    temp += '(' + chs[x][num - 1];
                else if (j == len - 1)
                    temp += ')' + chs[x][num - 1];
                else
                    temp += chs[x][num - 1];
            }
        }
        if (j == len) {
            cout<<temp;
        }
        cout<<'\n';
    }
    return 0;
}
