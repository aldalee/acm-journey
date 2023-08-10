// 1069 The Black Hole of Numbers
// https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088
// Created by HuanyuLee on 2022/1/9.
//
#include <iostream>
#include <algorithm>
using namespace std;
// 逆序的提取所给数字num的每一位，比如num=7654，则arr[] = {4,5,6,7}
void divide(int num,int arr[]){
    for (int i = 0; i < 4; ++i) {
        arr[i] = num%10;
        num /= 10;
    }
}
bool isSame(int num){
    int arr[4] = {};
    divide(num,arr);
    for (int i = 1; i < 4; ++i) {
        if (arr[i] != arr[0])
            return false;
    }
    return true;
}
void sorted(int num,int n,int &decrease,int &increase){
    int arr[n];
    int power = 1;
    decrease = increase = 0;
    divide(num,arr);
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        decrease += arr[i] * power;
        power *= 10;
    }
    power = 1;
    for (int i = n-1; i >= 0; --i) {
        increase += arr[i]*power;
        power *= 10;
    }
}
int main(){
    int num;
    cin >> num;
    int decrease = 0, increase = 0, result = num;
    if (isSame(num))
        printf("%04d - %04d = 0000",num,num);
    else{
        do{
            sorted(result, 4, decrease, increase);
            result = decrease - increase;
            printf("%04d - %04d = %04d\n", decrease, increase, result);
        }while (result != 6174);
    }
    return 0;
}