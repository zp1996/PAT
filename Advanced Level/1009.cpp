//
//  1009.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/16.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main ()
{
    int N, e, count = 0;
    double c;
    map<int, double> vec[2];
    map<int, double> res;
    int key[100];
    for (int i = 0; i < 2; i++) {
        cin>>N;
        for (int j = 0; j < N; j++) {
            cin>>e>>c;
            vec[i][e] = c;
        }
    }
    for (auto it : vec[0]) {
        for (auto itb : vec[1]) {
            e = it.first + itb.first;
            c = it.second * itb.second;
            if (res.find(e) == res.end())
                res[e] = c;
            else
                res[e] += c;
        }
    }
    for (auto it : res) {
        if (it.second)
            key[count++] = it.first;
    }
    printf("%d", count);
    for (int i = count - 1; i >= 0; i--) {
        printf(" %d %.1f", key[i], res[key[i]]);
    }
    cout<<'\n';
    return 0;
}
