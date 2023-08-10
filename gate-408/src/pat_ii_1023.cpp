//  1023 组个最小数
// https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
using namespace std;
int main(){
    int num[10];
    for (int & i : num)
        cin >> i;
    // 找第一个不为 0 的数（最小的）
    int k = 1;
    while (num[k] == 0)
        ++k;
    cout << k;      // 输出第一个不为0的数，作为第一位
    // 紧接着输出所有的0
    for (int i = 0; i < num[0]; ++i)
        cout << 0;
    // 紧接着输出剩余的 k
    for (int i = 1; i < num[k]; ++i)
        cout << k;
    // 紧接着依次输出剩余的数
    for (int i = k+1 ; i < 10; ++i) {
        for (int j = 0; j < num[i]; ++j)
            cout << i;
    }
    return 0;
}