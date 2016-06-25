//
//  1039.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/25.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
bool mapHas (map<char, int> &a, char value)
{
    map<char, int>::iterator isFind = a.find(value);
    return isFind == a.end();
}
int main ()
{
    int n = 0;
    map<char, int> c;
    string a;
    string b;
    cin>>a;
    cin>>b;
    int lenA = (int)a.size(), lenB = (int)b.size();
    for (int i = 0; i < lenA; i++) {
        char ch = a[i];
        if (mapHas(c, ch)) {
            c[ch] = 1;
        } else {
            c[ch]++;
        }
    }
    for (int i = 0; i < lenB; i++) {
        char ch = b[i];
        if (c[ch] != 0) {
            c[ch]--;
        } else {
            n++;
        }
        
    }
    if (!n) {
        cout<<"Yes "<<lenA - lenB<<'\n';
    } else {
        cout<<"No "<<n<<'\n';
    }
}
