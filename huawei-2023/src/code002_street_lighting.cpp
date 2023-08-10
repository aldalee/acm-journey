// 路灯照明问题 AC
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r;
    cin >> n;
    vector<pair<int, int>> gap;
    // 计算每个路灯的照明范围
    for (int i = 0; i < n; i++) {
        cin >> r;
        gap.emplace_back(max(0, i * 100 - r), min((n - 1) * 100, i * 100 + r));
    }

    sort(gap.begin(), gap.end());

    // 合并重叠的照明范围
    vector<pair<int, int>> mergedGap{gap[0]};
    for (int i = 1; i < n; i++) {
        int last = mergedGap.back().second;
        int L = gap[i].first;
        int R = gap[i].second;
        if (L <= last) {
            mergedGap.back().second = max(last, R);
        } else {
            mergedGap.emplace_back(L, R);
        }
    }

    // 计算未照明区间的长度和
    int res = 0;
    for (int i = 1; i < mergedGap.size(); i++) {
        res += mergedGap[i].first - mergedGap[i - 1].second;
    }
    cout << res << endl;

    return 0;
}
