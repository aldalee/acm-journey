//  1034 有理数四则运算
// https://pintia.cn/problem-sets/994805260223102976/problems/994805287624491008
// Created by HuanyuLee on 2022/1/9.
//
#include <iostream>
#include <cmath>
using namespace std;
struct Fraction{
    long long up;
    long long down;
};
long long getGcd(long long a,long long b){
    if (b == 0)
        return a;
    return getGcd(b,a%b);
}
// 分数化简
Fraction reduction(Fraction result){
    if (result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
        result.down = 1;
    else{
        long long gcd = getGcd(abs(result.up), abs(result.down));
        result.up /= gcd;
        result.down /= gcd;
    }
    return result;
}
Fraction add(Fraction a,Fraction b){
    Fraction result{};
    result.up = a.up * b.down + b.up * a.down;
    result.down = a.down * b.down;
    return reduction(result);
}
Fraction minu(Fraction a,Fraction b){
    Fraction result{};
    result.up = a.up * b.down - b.up * a.down;
    result.down = a.down * b.down;
    return reduction(result);
}
Fraction multi(Fraction a,Fraction b){
    Fraction result{};
    result.up = a.up * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}
Fraction divide(Fraction a,Fraction b){
    Fraction result{};
    result.up = a.up * b.down;
    result.down = a.down * b.up;
    return reduction(result);
}
void showResult(Fraction result){
    result = reduction(result);
    if (result.up < 0)
        cout << "(";
    if (result.down == 1)
        cout << result.up;
    else if (abs(result.up) > result.down)
        printf("%lld %lld/%lld",result.up/result.down, abs(result.up) % result.down,result.down);
    else
        printf("%lld/%lld",result.up,result.down);
    if (result.up < 0)
        cout << ")";
}
void printAddFraction(Fraction a,Fraction b){
    showResult(a);
    cout << " + ";
    showResult(b);
    cout << " = ";
    showResult(add(a,b));
    cout << endl;
}
void printMinuFraction(Fraction a,Fraction b){
    showResult(a);
    cout << " - ";
    showResult(b);
    cout << " = ";
    showResult(minu(a,b));
    cout << endl;
}
void printMultiFraction(Fraction a,Fraction b){
    showResult(a);
    cout << " * ";
    showResult(b);
    cout << " = ";
    showResult(multi(a,b));
    cout << endl;
}
void printDivideFraction(Fraction a,Fraction b){
    showResult(a);
    cout << " / ";
    showResult(b);
    cout << " = ";
    if (b.up == 0)
        cout << "Inf";
    else
        showResult(divide(a,b));
    cout << endl;
}
int main(){
    Fraction a{},b{};
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    printAddFraction(a,b);
    printMinuFraction(a,b);
    printMultiFraction(a,b);
    printDivideFraction(a,b);
    return 0;
}