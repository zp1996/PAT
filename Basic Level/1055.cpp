//
//  1055.cpp
//  PAT Basic Level
//
//  Created by apple on 16/7/7.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
struct Person
{
    string name;
    int height;
};
bool compare (Person &a, Person &b)
{
    return a.height > b.height ||
            (a.height == b.height &&
             a.name < b.name) ||
            (a.height == b.height &&
             a.name == b.name);
}
void Quick (Person* arr, int left, int right)
{
    if (left >= right) return;
    int i = left, j = right;
    Person current = arr[i];
    while (i < j) {
        while (compare(current, arr[j]) && i < j)
            j--;
        while (compare(arr[i], current) && i < j)
            i++;
        if (i < j) {
            Person p = arr[i];
            arr[i] = arr[j];
            arr[j] = p;
        }
    }
    arr[left] = arr[j];
    arr[j] = current;
    Quick(arr, left, j - 1);
    Quick(arr, j + 1, right);
}
void QuickSort (Person* arr, int len)
{
    Quick(arr, 0, len - 1);
}
int main () {
    int N, k;
    cin>>N>>k;
    int num = N / k, count = 0;
    Person arr[10000];
    Person p;
    for (int i = 0; i < N; i++) {
        cin>>p.name>>p.height;
        arr[i] = p;
    }
    QuickSort(arr, N);
    for (int i = 0; i < k; i++) {
        int len = i == 0 ? (N - num * k + num) : num;
        string temp = "";
        for (int j = 0; j < len; j++) {
            if (j == 0)
                temp += arr[count + j].name;
            else if (j % 2 == 0)
                temp += " " + arr[count + j].name;
            else
                temp = arr[count + j].name + " " + temp;
        }
        cout<<temp<<'\n';
        count += len;
    }
    return 0;
}
