// 座位调整 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    vector<int> desk;
    while (cin >> x) {
        desk.push_back(x);
        if (cin.get() == '\n') break;
    }
    int res = 0;
    int n = (int) desk.size();
    for (int i = 0; i < n; ++i) {
        if (desk[i] == 0) {
            bool l = i == 0 || desk[i - 1] == 0;
            bool r = i == n - 1 || desk[i + 1] == 0;
            if (l && r) {
                desk[i++] = 1;
                res++;
            }
        }
    }
    cout << res;
    return 0;
}