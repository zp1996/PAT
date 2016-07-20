//
//  1010.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/18.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ll;
ll get (char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else
        return ch - 'a' + 10;
}
ll getDecimal (ll radix, string a)
{
    ll res = 0;
    for (int i = 0; i < a.size(); i++) {
        res = res * radix + get(a[i]);
    }
    return res;
}
int main ()
{
    string a, b;
    int tag, radix;
    ll r1, end, s = 0, res = 0;
    cin>>a>>b>>tag>>radix;
    if (tag == 2)
        swap(a, b);
    for (int i = 0; i < (int)b.size(); i++) {
        if (s <= get(b[i]))
            s = get(b[i]);
    }
    s++;
    r1 = getDecimal(radix, a);
    end = r1 + 1;
    while (s <= end) {
        ll mid = (s + end) >> 1;
        ll r2 = getDecimal(mid, b);
        if (r1 == r2) {
            res = mid;
        }
        if (r2 >= r1) {
            end = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    if (!res)
        cout<<"Impossible"<<endl;
    else
        cout<<s<<endl;
    return 0;
}
