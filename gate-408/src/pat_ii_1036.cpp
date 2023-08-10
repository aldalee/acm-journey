// 1036 跟奥巴马一起编程
// https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680
// Created by HuanyuLee on 2022/1/6.
//
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    char ch;
    cin >> n >> ch;
    // 输出第一行
    for (int j = 0; j < n; ++j) {
        cout << ch;
    }
    cout << endl;
    // 输出中间的图形
    for (int i = 0; i < round(n / 2.0) - 2 ; ++i) {
        /*
         * cmath库
         * round()函数 四舍五入
         * ceil() 向上取整
         * floor()  向下取整
         */
        for (int j = 0; j < n; ++j) {
            if (j == 0 || j == n-1)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
    // 输出最后一行
    for (int j = 0; j < n; ++j) {
        cout << ch;
    }
    return 0;
}
