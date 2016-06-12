//
//  1024.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/12.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int findPos (string str, char a)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == a) {
            return i;
        }
    }
    return -1;
}
int main ()
{
    string A, num = "", exp = "";
    cin>>A;
    char fh;
    int index = findPos(A, '.'), EPos = findPos(A, 'E');
    if (index != -1) {
        num += A[index - 1];
    }
    index++;
    for ( ; index < EPos; index++) {
        num += A[index];
    }
    EPos += 1;
    fh = A[EPos];
    EPos++;
    for ( ; EPos < A.size(); EPos++) {
        exp += A[EPos];
    }
    int expNum = 0, pos = 1;
    for (int i = (int)exp.size() - 1; i >= 0; i--) {
        expNum += (exp[i] - '0') * pos;
        pos *= 10;
    }
    if (A[0] == '-') cout<<'-';
    if (fh == '+') {
        if ((num.size() - 1) > expNum) {
            for (int i = 0; i < num.size(); i++) {
                if (i == expNum + 1) {
                    cout<<'.';
                }
                cout<<num[i];
            }
        } else {
            int zeroLen = expNum - (int)num.size() + 1;
            for (int i = 0; i < num.size(); i++) {
                cout<<num[i];
            }
            for (int i = 0; i < zeroLen; i++) {
                cout<<0;
            }
        }
    } else {
        for (int i = 0; i < expNum; i++) {
            if (i == 1) {
                cout<<'.';
            }
            cout<<0;
        }
        for (int i = 0; i < num.size(); i++) {
            cout<<num[i];
        }
    }
    cout<<'\n';
}
