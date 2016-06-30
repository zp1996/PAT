//
//  1047.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/29.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
struct Person
{
    int group;
    int num;
    int score;
};
int main ()
{
    int N, group = 0, max = 0;
    Person p;
    map<int, int> agg;
    cin>>N;
    for (int i = 0; i < N; i++) {
        scanf("%d-%d %d", &p.group, &p.num, &p.score);
        if (agg.find(p.group) == agg.end())
            agg[p.group] = p.score;
        else
            agg[p.group] += p.score;
        if (agg[p.group] > max) {
            max = agg[p.group];
            group = p.group;
        }
    }
    printf("%d %d\n", group, max);
    return 0;
}
