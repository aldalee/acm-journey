// 特殊数字
// AC
// http://oj.ecustacm.cn/problem.php?id=1817
#include <bits/stdc++.h>

using namespace std;

int nums[901], n;

//预先处理出所有特殊数字
void precompute() {
    for (int x = 0; x <= 30; ++x) {
        for (int y = x + 1; y <= 30; ++y) {
            nums[n++] = (1 << x) + (1 << y);
        }
    }
    sort(nums, nums + n);
}

int main() {
    ios::sync_with_stdio(false);
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int res = 0;
        // 查找第一个大于等于x的位置p，即 nums[p]>=x
        long long p = lower_bound(nums, nums + n, x) - nums;
        if (nums[p] == x) {
            res = 0;
        } else {
            res = nums[p] - x;
            if (p - 1 > 0) {
                // 比x大和比x小的最近的两个数
                res = min(res, x - nums[p - 1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}