//
//  1053.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/4.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int main () {
    int D, N;
    double e;
    cin>>N>>e>>D;
    int pCount = 0, count = 0;
    for (int i = 0; i < N; i++) {
        int day, c = 0;
        cin>>day;
        for (int j = 0; j < day; j++) {
            double t;
            cin>>t;
            if (t < e)
                c++;
        }
        if(c <= (day / 2)) continue;
        if(day > D)
            count++;
        else
            pCount++;
    }
    double x = (double)(pCount) / N * 100.0;
    double y = (double)(count) / N * 100.0;
    printf("%.1f%% %.1f%%\n", x, y);
    return 0;
}
