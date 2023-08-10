//
// Created by HuanyuLee on 2022/1/11.
//
#include <iostream>
using namespace std;
struct BigInt{
    int d[1000];
    int length;
};
BigInt init(string str){
    BigInt bI{};
    bI.length = str.length();
    for (int & i : bI.d) {
        i = 0;
    }
    // 将大整数低位保存在数组的低位，可实现低位对齐，有利于计算
    for (int i = 0; i < bI.length; ++i) {
        bI.d[i] = str[bI.length-i-1] - '0';
    }
    return bI;
}

BigInt add(BigInt a,BigInt b){
    BigInt c{};
    c.length = 0;
    int carry = 0;
    for (int i = 0; i < a.length || i < b.length; ++i) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.length++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0)
        c.d[c.length++] = carry;
    return c;
}

BigInt sub(BigInt a,BigInt b){
    BigInt c{};
    c.length = 0;
    for (int i = 0; i < a.length || i < b.length; ++i) {
        if (a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.length++] = a.d[i] - b.d[i];
    }
    while (c.length-1 >= 1 && c.d[c.length-1] == 0)
        c.length--; //除去高位的 0，且至少保留一位 0
    return c;
}
// 大整数与小整数乘法
BigInt multi(BigInt a,int b){
    BigInt c{};
    c.length = 0;
    int carry = 0;
    for (int i = 0; i < a.length; ++i) {
        int temp = a.d[i] * b + carry;
        c.d[c.length++] = temp % 10;
        carry = temp/10;
    }
    while (carry != 0){
        c.d[c.length++] = carry % 10;
        carry /= 10;
    }
    return c;
}
// 大整数与小整数除法
BigInt divide(BigInt a,int b,int &r){   // r保存余数
    BigInt c{};
    c.length = a.length;
    r = 0;
    for (int i = a.length-1; i >= 0; --i) {
        r = r*10 + a.d[i];
        if (r < b)
            c.d[i] = 0;
        else{
            c.d[i] = r/b;
            r = r%b;
        }
    }
    while (c.length-1 >= 1 && c.d[c.length-1] == 0)
        c.length--;
    return c;
}
void printBigInt(BigInt bI){
    for (int i = bI.length-1; i >= 0; --i)
        cout << bI.d[i];
    cout << endl;
}
int main(){
    string num1 = "123456";
    string num2 = "23456789";
    int c = 3;
    int r = 0;
    BigInt a{},b{};
    a = init(num1);
    b = init(num2);
    cout << "a+b = ";
    printBigInt(add(a,b));
    cout << "a-b = ";
    printBigInt(sub(b,a));
    cout << "a*c = ";
    printBigInt(multi(a,c));
    cout << "a/c = ";
    printBigInt(divide(a,c,r));
    cout << r;
    return 0;
}