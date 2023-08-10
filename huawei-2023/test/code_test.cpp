#include <bits/stdc++.h>
#include "../util/utils.h"
using namespace std;

int f(int n, vector<int> &r) {
    vector<pair<int, int>> gap;
    // 计算每个路灯的照明范围
    for (int i = 0; i < n; i++) {
        gap.emplace_back(max(0, i * 100 - r[i]), min((n - 1) * 100, i * 100 + r[i]));
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
    return res;
}


int g(int n, vector<int> &r) {
    vector<pair<int, int>> light;         // 每盏灯的照明区间
    vector<int> res(n - 1, 100);    // 每个空隙当前的最小阴影
    for (int i = 0; i < n; ++i) {
        light.emplace_back(max(i * 100 - r[i], 0), min(i * 100 + r[i], (n - 1) * 100));
    }

    for (int i = 0; i < light.size() - 1; ++i) {
        for (int j = i + 1; j < light.size(); ++j) {
            if (light[i].second >= light[j].first) {
                int t = j - 1;
                while (t >= i) {
                    res[t--] = 0;
                }
            } else {
                int L = light[j].first / 100, R = light[i].second / 100;
                if (L > R) continue;
                res[L] = min(res[L], light[j].first - light[i].second);
            }
        }
    }
    return accumulate(res.begin(), res.end(), 0);
}


int main() {
    int maxLen = 10000;
    int maxValue = 100000;
    int testTimes = 10000;

    for (int i = 0; i < testTimes; ++i) {
        int n = generate_random_n(maxLen);
        vector<int> r = generate_random_array(maxLen, maxValue);
        int expect = g(n, r);
        int actual = f(n, r);
        if (expect != actual) {
            cout << "n = " << n << endl;
            cout << "r = ";
            for_each(r.begin(), r.end(), [](int x) { cout << x << " "; });
            cout << endl;
            cout << "expect = " << expect << endl;
            cout << "actual = " << actual << endl;
            cout << "Fuck!" << endl;
            break;
        }
    }
    return 0;
}