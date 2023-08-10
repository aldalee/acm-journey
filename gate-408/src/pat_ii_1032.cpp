//  1032 挖掘机技术哪家强
// https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032
// Created by HuanyuLee on 2022/1/6.
//
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int score[n+1]={};
    int schoolID,schoolScore;
    while(cin >> schoolID >> schoolScore){
        score[schoolID]+=schoolScore;
    }
    for (int i = 1; i <= n; ++i) {
        if (score[i] > score[0]){
            score[0] = score[i];
            schoolID = i;
        }
    }
    cout << schoolID << " " << score[schoolID];
    return 0;
}
