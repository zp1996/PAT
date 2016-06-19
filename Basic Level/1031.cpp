//
//  1031.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/19.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{
    string identity;
    int N;
    int quan[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char end[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    vector<string> identities;
    vector<string> errors;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>identity;
        identities.push_back(identity);
    }
    for (int i = 0; i < N; i++) {
        identity = identities[i];
        int sum = 0;
        int j = 0, len = (int)identity.length() - 1;
        for (; j < len; j++) {
            int a = identity[j] - '0';
            if (a > 10) {
                errors.push_back(identity);
                break;
            }
            sum += a * quan[j];
        }
        if (end[sum % 11] != identity[j] && j == len) {
            errors.push_back(identity);
        }
    }
    int len = (int)errors.size();
    if (len == 0) {
        cout<<"All passed"<<'\n';
    } else {
        for (int i = 0; i < len; i++) {
            cout<<errors[i]<<'\n';
        }
    }
}
