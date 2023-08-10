// 喊7的次数重排 AC
#include <bits/stdc++.h>

using namespace std;

bool isContains7(int x) {
    return x % 7 == 0 || x % 10 == 7;
}

int main() {
    int x;
    vector<int> arr;
    while (cin >> x) {
        arr.push_back(x);
        if (cin.get() == '\n') break;
    }

    int cnt = accumulate(arr.begin(), arr.end(), 0);
    int n = (int) arr.size();
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= 200; ++i) {
        if (cnt == 0) break;
        if (isContains7(i)) {
            res[i % n]++;
            cnt--;
        }
    }
    for (int i = 1; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}