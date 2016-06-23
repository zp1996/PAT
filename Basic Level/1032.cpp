//
//  1032.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/19.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Student
{
    int sno;
    int score;
};
int main ()
{
    int N, max = 0;
    cin>>N;
    Student stu;
    map<int, int> school;
    vector<Student> stus;
    for (int i = 0; i < N; i++) {
        cin>>stu.sno>>stu.score;
        stus.push_back(stu);
    }
    for (vector<Student>::iterator iter = stus.begin(); iter != stus.end(); iter++) {
        int temp = school[iter->sno] ? school[iter->sno] + iter->score : iter->score;
        if (max < temp) {
            max = temp;
            stu.sno = iter->sno;
            stu.score = temp;
        }
        school[iter->sno] = temp;
    }
    cout<<stu.sno<<" "<<stu.score<<'\n';
    return 0;
}
