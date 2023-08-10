// 组成最大数 AC
// https://leetcode.cn/problems/largest-number
#include <bits/stdc++.h>

using namespace std;

string largestNumber(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](const int &x, const int &y) {
        long sx = 10, sy = 10;
        while (sx <= x) sx *= 10;
        while (sy <= y) sy *= 10;
        return sy * x + y > sx * y + x;
    });
    if (arr[0] == 0) {
        return "0";
    }
    string res;
    for (int &x: arr) {
        res += to_string(x);
    }
    return res;
}

int main() {
    int x;
    vector<int> arr;
    while (cin >> x) {
        arr.push_back(x);
        if (cin.get() == '\n') break;
    }
    cout << largestNumber(arr);
    return 0;
}