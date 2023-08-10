//  找x
// Created by HuanyuLee on 2022/1/6.
//
#include <iostream>
#define maxSize 200
using namespace std;
int main(){
    int n,x;
    int num[maxSize];
    while (cin >> n){
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        cin >> x;
        int i;
        for (i = 0; i < n; ++i) {
            if (x == num[i]){
                cout << i << endl;
                break;
            }
        }
        if (i == n)
            cout << -1 << endl;
    }
    return 0;
}
