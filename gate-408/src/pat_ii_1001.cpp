// 1001 害死人不偿命的(3n+1)猜想
// https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
// Created by HuanyuLee on 2022/1/6.
//
#include <iostream>
using namespace std;
int main() {
    int n;
    int count = 0;
    cin >> n;
    while (n != 1){
        if (n%2 == 0)
            n /= 2;
        else
            n = (3*n+1)/2;
        count++;
    }
    cout << count << endl;
    return 0;
}