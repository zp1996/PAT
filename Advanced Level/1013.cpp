//
//  1013.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/23.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
int matrix[1000][1000];
int visited[1000];
int N;
void dfs (int id)
{
    visited[id] = 1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && matrix[id][i])
            dfs(i);
    }
}
void output (int id)
{
    int temp[N][N], num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == id || j == id)
                temp[i][j] = 0;
            else
                temp[i][j] = matrix[i][j];
        }
        if (i == id)
            visited[i] = 1;
        else
            visited[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            num++;
        }
    }
    cout<<num - 1<<'\n';
}
int main ()
{
    int M, K, x, y;
    cin>>N>>M>>K;
    for (int i = 0; i < M; i++) {
        cin>>x>>y;
        matrix[x - 1][y - 1] = matrix[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < K; i++) {
        cin>>x;
        x = x - 1;
        output(x);
    }
    return 0;
}
