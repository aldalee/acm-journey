// 1013 数素数
// https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
// Created by HuanyuLee on 2022/1/10.
//
#include <iostream>
#include <cmath>
#define maxSize 1000001
using namespace std;
bool isPrime(int n){
    for (int i = 2; i <= (int)sqrt(1.0*n); ++i) {
        if (n%i == 0)
            return false;
    }
    return true;
}
void findPrime(int n,int prime[]){
    int p[maxSize] = {};    // 0代表素数
    int num = 0;
    // 埃氏筛法
    for (int i = 2; i < maxSize; ++i) {
        if (p[i] == 0){
            prime[++num] = i;   // prime[]保存求得的素数
            if (num >= n)
                break;
            for (int j = i+i; j < maxSize; j += i)  // 2i,3i,4i...
                p[j] = 1;
        }
    }
}
void printPrime(int prime[],int m,int n){
    int count = 0;
    for (int i = m; i <= n; ++i) {
        cout << prime[i];
        ++count;
        if (i != n && count%10 != 0)
            cout << " ";
        else
            cout << endl;
    }
}
int main(){
    int m,n;
    cin >> m >> n;
    int prime[10000] = {};    // 素数表
    findPrime(n,prime);
    printPrime(prime,m,n);
    return 0;
}
