//
//  1004.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/11.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main ()
{
    int m, n, k, id, child, temp;
    while (cin>>n>>m) {
        vector<vector<int>> agg(n);
        for (int i = 0; i < m; i++) {
            cin>>id>>k;
            for (int j = 0; j < k; j++) {
                cin>>child;
                agg[id - 1].push_back(child - 1);
            }
        }
        // 树的层次遍历
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int len = (int)q.size(), count = 0;
            for (int i = 0; i < len; i++) {
                temp = q.front();
                int num = (int)agg[temp].size();
                if (!num) {
                    count++;
                } else {
                    for (int j = 0; j < num; j++) {
                        q.push(agg[temp][j]);
                    }
                }
                q.pop();
            }
            if (q.empty())
                cout<<count<<'\n';
            else
                cout<<count<<' ';
        }
    }
    return 0;
}
