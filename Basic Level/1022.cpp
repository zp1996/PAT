//
//  1022.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/10.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
using namespace std;
void say (int c , int d)
{
    int temp = c/ d;
    if (temp != 0)
    {
        say(temp, d);
    }
    cout<<c % d;
}
int main ()
{
    int A, B, D;
    cin>>A>>B>>D;
    int add = A + B;
    say(add, D);
    cout<<"\n";
    return 0;
}
