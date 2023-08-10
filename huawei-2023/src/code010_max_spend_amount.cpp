// 最大花费金额 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, r;
    vector<int> price;
    while (cin >> m) {
        price.push_back(m);
        if (cin.get() == '\n') break;
    }
    cin >> r;
    int n = (int) price.size();
    sort(price.begin(), price.end());
    int max_cost = -1;
    // 使用双指针求解最大花费额度
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int cost = price[i] + price[j] + price[k];
            if (cost == r) {
                cout << r << endl;
                return 0;
            } else if (cost < r) {
                max_cost = max(max_cost, cost);
                j++;
            } else {
                k--;
            }
        }
    }
    cout << max_cost << endl;
    return 0;
}