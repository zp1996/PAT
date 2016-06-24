//
//  1038.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/24.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    int N, M, temp;
    int score[101] = {0};
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>temp;
        score[temp]++;
    }
    cin>>M;
    for (int i = 0; i < M; i++) {
        cin>>temp;
        int count = score[temp];
        if (i == 0) {
            cout<<count;
        } else {
            cout<<" "<<count;
        }
    }
    cout<<endl;
    return 0;
}