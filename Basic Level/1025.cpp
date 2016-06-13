//
//  1025.cpp
//  PAT Basic Level
//
//  Created by apple on 16/6/13.
//  Copyright © 2016年 zp1996. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;
struct Node

{
    int Data;
    string Pos;
    string Next;
};
int main ()
{
    string first;
    int len, turnLen;
    cin>>first>>len>>turnLen;
    if (len < turnLen) {
        return 0;
    }
    vector<Node> nodes;
    map<string, Node> cacheList;
    for (int i = 0; i < len; i++) {
        Node node;
        cin>>node.Pos>>node.Data>>node.Next;
        cacheList[node.Pos] = node;
    }
    while (first != "-1") {
        nodes.push_back(cacheList[first]);
        first = cacheList[first].Next;
    }
    if (turnLen != 0 || turnLen != 1) {
        Node end;
        end.Next = "-1";
        end.Pos = "-1";
        end.Data = 0;
        nodes.push_back(end);
        cacheList[end.Pos] = end;
        int start = 0, cacheLen = turnLen;
        first = nodes[turnLen - 1].Pos;
        while (turnLen <= len) {
            int x = start == 0 ? 0 : (turnLen / 2);
            Node *temp = &cacheList[nodes[x].Pos];
            Node *nextRear = &cacheList[nodes[turnLen].Pos];
            for (int i = start; i < min(turnLen, len); i++) {
                string item = temp->Next;
                temp->Next = nextRear->Pos;
                nextRear = temp;
                temp = &cacheList[item];
            }
            if (x != 0) {
                cacheList[nodes[x - cacheLen].Pos].Next = cacheList[nodes[turnLen - 1].Pos].Pos;
            }
            start = turnLen;
            turnLen += turnLen;
        }
        nodes.clear();
        while (first != "-1") {
            nodes.push_back(cacheList[first]);
            first = cacheList[first].Next;
        }
    }
    for (int i = 0; i < nodes.size(); i++) {
        cout<<nodes[i].Pos<<" "<<nodes[i].Data<<" "<<nodes[i].Next<<"\n";
    }
    return 0;
}