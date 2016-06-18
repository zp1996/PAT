//
//  1029.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/18.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
bool has (char* arr, int size, char value)
{
    for (int i = 0; i < size; i++) {
        if (value >= 'a' && value <= 'z') {
            if (arr[i] - 'A' + 'a' == value) {
                return true;
            }
        } else {
            if (arr[i] == value) {
                return true;
            }
        }
    }
    return false;
}
int main ()
{
    string input, output;
    int size = 0;
    char bad[37];
    cin>>input>>output;
    for (int i = 0, j = 0; i < input.size(); i++) {
        if (input[i] == output[j]) {
            j++;
        } else {
            if (!has(bad, size, input[i])) {
                if (input[i] >= 'a' && input[i] <= 'z') {
                    bad[size++] = input[i] - 'a' + 'A';
                } else {
                    bad[size++] = input[i];
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout<<bad[i];
    }
    cout<<'\n';
    return 0;
}
