//
//  2.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/8.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main ()
{
    int k, e, count = 0;
    int key[20];
    double c;
    map<int, double> agg;
    for (int i = 0; i < 2; i++) {
        cin>>k;
        for (int j = 0; j < k; j++) {
            cin>>e>>c;
            if (agg.find(e) != agg.end())
                agg[e] += c;
            else
                agg[e] = c;
        }
    }
    for (auto it : agg) {
        if (it.second) {
            key[count++] = it.first;
        }
    }
    printf("%d", count);
    for (int i = count - 1; i >= 0; i--) {
        printf(" %d %.1f", key[i], agg[key[i]]);
    }
    cout<<'\n';
    return 0;
}
