// 分苹果 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n;
    int res = 0;        // 表示A是否可以均分苹果
    int sum = 0;
    int a = 10001;
    while (cin >> w) {
        res ^= w;
        sum += w;
        a = min(a, w);
        if (cin.get() == '\n') break;
    }
    // res为0表示满足A的规则，因此只留给A最小的一个
    if (res == 0) {
        cout << sum - a;
    } else {
        cout << -1;
    }
    return 0;
}