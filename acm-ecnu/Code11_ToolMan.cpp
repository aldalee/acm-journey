//
// Created by HuanyuLee on 2022/11/30.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long all = 0;
    long n;
    cin >> n;
    vector<long> money(n, 0);
    int index = 0;
    while (index < n) {
        cin >> money[index];
        all += money[index++];
    }
    long avg = all / n;
    if (all % n != 0) {
        cout << -1;
        return 0;
    }
    long pmax = 0;
    long nmax = 0;
    long cnt = 0;
    for (int i = 0; i < n; i++) {
        money[i] -= avg;
        cnt += money[i];
        pmax = max(pmax, cnt);
        nmax = min(nmax, cnt);
    }
    cout << abs(pmax) + abs(nmax);
    return 0;
}