// 补种未成活胡杨
#include <bits/stdc++.h>

using namespace std;

// 求含有K个零的最长子串
int f(vector<int> arr, int k) {
    int res = 0;
    queue<int> q;

    for (int i = 1, l = 1; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            q.push(i);
        }
        if (q.size() > k) {
            res = max(res, i - l);
            l = q.front() + 1;
            q.pop();
            continue;
        }
        if ((q.size() == k) && i == arr.size() - 1) {
            res = max(res, i - l + 1);
        }
    }

    return res;
}

int main() {
    int n, m, k, t;
    cin >> n >> m;
    vector<int> tree(n + 1, 1);     // 1: live  0: die
    for (int i = 0; i < m; ++i) {
        cin >> t;
        tree[t] = 0;
    }
    cin >> k;
    cout << f(tree, k);
    return 0;
}