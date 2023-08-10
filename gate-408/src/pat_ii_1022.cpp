// 1022 D进制的A+B
// https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#define maxSize 100
using namespace std;
int main(){
    unsigned int A,B,C,D,result[maxSize]={};
    while (cin >> A >> B >> D){
        C = A + B;
        int n = 0;
        do {
            result[n++] = C % D;
            C /= D;
        } while (C > 0);
        for (int i = n-1; i >=0 ; --i) {
            cout << result[i];
        }
        cout<<endl;
    }
    return 0;
}
