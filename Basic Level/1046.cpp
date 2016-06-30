//
//  1046.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/29.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
struct Num
{
    int han;
    int hua;
};
int main ()
{
    int N;
    Num numA, numB;
    int a = 0, b = 0;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>numA.han>>numA.hua>>numB.han>>numB.hua;
        if (numA.han + numB.han == numA.hua &&
            numA.han + numB.han != numB.hua
           ) {
            b++;
        } else if (numA.han + numB.han == numB.hua &&
                   numA.han + numB.han != numA.hua) {
            a++;
        }
    }
    cout<<a<<' '<<b<<'\n';
    return 0;
}
