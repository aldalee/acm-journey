// http://oj.ecustacm.cn/problem.php?id=1803
// 二进制中的1
// 数位统计DP（暂时没搞懂）
#include <bits/stdc++.h>

using namespace std;
long long dp[60][60];
int num[60];
long long MOD = 1e7 + 7;

// 快速幂
long long fastPow(long long x, long long n) {
    long long ans = 1;
    x %= MOD;
    while (n) {
        if (n & 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

// 数字中有k个1的个数
long long DFS(int pos, int sum, bool limit, int k) {
    if (pos == 0) {
        return sum == k;
    }
    if (!limit && dp[pos][sum] != -1) {
        return dp[pos][sum];
    }
    int up = limit ? num[pos] : 1;
    dp[pos][sum] = 0;
    for (int i = 0; i <= up; ++i) {
        if (i == 1) {
            dp[pos][sum] += DFS(pos - 1, sum + 1, limit && (i == up), k);
        } else {
            dp[pos][sum] += DFS(pos - 1, sum, limit && (i == up), k);
        }
    }
    return dp[pos][sum];
}

int main() {
    long long x;
    cin >> x;
    int n = 0;
    while (x) {
        num[++n] = (int) (x % 2);
        x >>= 1;
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        memset(dp, -1, sizeof(dp));
        long long cnt = DFS(n, 0, true, i);
        ans = ans * fastPow(i, cnt) % MOD;
    }
    cout << ans << endl;
    return 0;
}