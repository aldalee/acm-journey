// 分糖果 AC
#include <bits/stdc++.h>

using namespace std;

int f(long long n) {
    if (n == 1) {
        return 0;
    }
    int res = 0;
    if (n % 2 == 0) {
        n /= 2;
        res += f(n) + 1;
    } else {
        res = min(f(n + 1), f(n - 1)) + 1;
    }
    return res;
}

int dp(long long n, unordered_map<long long, int> t) {
    if (n == 1) {
        return 0;
    }
    if (t.count(n)) {
        return t[n];
    }
    int res = 0;
    if (n % 2 == 0) {
        n /= 2;
        res += dp(n, t) + 1;
    } else {
        res = min(dp(n + 1, t), dp(n - 1, t)) + 1;
    }
    t[n] = res;
    return res;
}


int main() {
    long long n;
    cin >> n;
    unordered_map<long long, int> t;
//    cout << f(n) << endl;
    cout << dp(n, t) << endl;
    return 0;
}