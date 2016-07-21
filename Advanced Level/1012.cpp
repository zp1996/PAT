//
//  1012.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/21.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Stu
{
    string id;
    int arr[4];
};
typedef bool (*Fun)(Stu &a, Stu &b);
void init (vector<Stu> agg, map<string, vector<int>> &res,  Fun fn, int index)
{
    int i = 0, len = (int)agg.size();
    sort(agg.begin(), agg.end(), fn);
    for (; i < len; i++) {
        if (i != 0 && agg[i].arr[index] == agg[i - 1].arr[index]) {
            res[agg[i].id][index] = res[agg[i - 1].id][index];
        } else {
            res[agg[i].id][index] = i + 1;
        }
    }
}
bool CompareA (Stu &a, Stu &b)
{
    return a.arr[0] > b.arr[0];
}
bool CompareC (Stu &a, Stu &b)
{
    return a.arr[1] > b.arr[1];
}
bool CompareM (Stu &a, Stu &b)
{
    return a.arr[2] > b.arr[2];
}
bool CompareE (Stu &a, Stu &b)
{
    return a.arr[3] > b.arr[3];
}
int main ()
{
    int N, M;
    cin>>N>>M;
    Stu temp;
    string id;
    char chs[4] = {'A', 'C', 'M', 'E'};
    vector<Stu> agg;
    map<string, vector<int>> res;
    for (int i = 0; i < N; i++) {
        cin>>temp.id>>temp.arr[1]>>temp.arr[2]>>temp.arr[3];
        temp.arr[0] = (temp.arr[1] + temp.arr[2] + temp.arr[3]) / 3;
        res[temp.id] = {0, 0, 0, 0};
        agg.push_back(temp);
    }
    init(agg, res, CompareA, 0);
    init(agg, res, CompareC, 1);
    init(agg, res, CompareM, 2);
    init(agg, res, CompareE, 3);
    for (int i = 0; i < M; i++) {
        cin>>id;
        if (res.find(id) != res.end()) {
            int num = N + 1, index = 0;
            for (int i = 0; i < res[id].size(); i++) {
                if (res[id][i] < num) {
                    num = res[id][i];
                    index = i;
                }
            }
            cout<<num<<" "<<chs[index]<<endl;
        } else {
            cout<<"N/A"<<'\n';
        }
    }
    return 0;
}
