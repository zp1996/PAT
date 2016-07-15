//
//  1006.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
inline void GetTime (int &x, int h, int m, int s) {
    x = h * 10000 + m * 100 + s;
}
struct Person {
    string name;
    int inTime;
    int outTime;
};
bool InSort (Person &a, Person &b) {
    return a.inTime < b.inTime;
}
bool OutSort (Person &a, Person &b) {
    return a.outTime > b.outTime;
}
int main () {
    int m, h, min, s;
    while (cin>>m) {
        vector<Person> agg(m);
        for (int i = 0; i < m; i++) {
            cin>>agg[i].name;
            scanf("%d:%d:%d", &h, &min, &s);
            GetTime(agg[i].inTime, h, min, s);
            scanf("%d:%d:%d", &h, &min, &s);
            GetTime(agg[i].outTime, h, min, s);
        }
        sort(agg.begin(), agg.end(), InSort);
        cout<<agg[0].name<<" ";
        sort(agg.begin(), agg.end(), OutSort);
        cout<<agg[0].name;
    }
    return 0;
}
