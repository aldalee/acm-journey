// 太阳能板最大面积 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    vector<int> h;
    while (cin >> x) {
        h.push_back(x);
        if (cin.get() == '\n') break;
    }
    int l = 0;
    int r = (int) h.size() - 1;
    int max_area = 0;
    while (l < r) {
        max_area = max(max_area, min(h[l], h[r]) * (r - l));
        if (h[l] > h[r]) {
            r--;
        } else {
            l++;
        }
    }
    cout << max_area << endl;
    return 0;
}