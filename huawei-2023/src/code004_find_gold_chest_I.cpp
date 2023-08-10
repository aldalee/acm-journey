// 阿里巴巴找黄金宝箱（I）AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    vector<int> arr;
    while (cin >> t) {
        arr.push_back(t);
        if (cin.get() == '\n') break;
    }
    int L = arr[0];
    int R = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (L == R) {
            res = i;
            break;
        }
        L += arr[i + 1];
        R -= arr[i];
    }
    cout << res;
    return 0;
}