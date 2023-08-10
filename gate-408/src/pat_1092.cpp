//
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#define maxSize 100
using namespace std;
void hashFun(const string& s,int *count){
    for (char i : s) {
        int index = i - '0';
        ++count[index];
    }
}
int main(){
    string shop,eva;
    int counts[maxSize] = {};
    cin >> shop >> eva;
    bool flag = true;
    int extra=0,need=0;
    hashFun(shop,counts);
    for (char i : eva) {
        int index = i - '0';
        --counts[index];
    }
    for (int count : counts) {
        if (count >= 0){
            extra += count;
        } else{
            need += abs(count);
            flag = false;
        }
    }
    if (flag)
        cout << "Yes" << " " << extra;
    else
        cout << "No" << " " << need;
    return 0;
}