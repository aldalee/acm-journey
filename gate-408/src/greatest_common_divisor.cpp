//  Codeup1818  最大公约数
// c为 a和 b的最大公约数，则 a和 b的最小公倍数是 ab/c
// Created by HuanyuLee on 2022/1/9.
//
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if (b == 0)
        return a;
    else
        return gcd(b,a%b);
}
int main(){
    int a,b;
    while (cin >> a >> b)
        cout << gcd(a,b) << endl;
    return 0;
}
