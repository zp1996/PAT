//
//  1041.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/26.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string examNum;
    int writeNum;
    int computerNum;
};
int main ()
{
    int N, M, num;
    Student stu;
    Student stus[1000];
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>stu.examNum>>stu.computerNum>>stu.writeNum;
        stus[i] = stu;
    }
    cin>>M;
    for (int i = 0; i < M; i++) {
        cin>>num;
        for (int i = 0; i < N; i++) {
            if (stus[i].computerNum == num) {
                cout<<stus[i].examNum<<" "<<stus[i].writeNum<<'\n';
                break;
            }
        }
    }
    return 0;
}
