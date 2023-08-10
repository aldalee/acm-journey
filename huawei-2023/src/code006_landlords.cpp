// 斗地主之顺子 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    map<string, int> m = {
            {"3",  0},
            {"4",  1},
            {"5",  2},
            {"6",  3},
            {"7",  4},
            {"8",  5},
            {"9",  6},
            {"10", 7},
            {"J",  8},
            {"Q",  9},
            {"K",  10},
            {"A",  11},
            {"2",  12},
    };
    vector<int> cnt(13, 0);
    while (cin >> x) {
        cnt[m[x]]++;
        if (cin.get() == '\n') break;
    }
    map<int, string> res = {
            {0,  "3"},
            {1,  "4"},
            {2,  "5"},
            {3,  "6"},
            {4,  "7"},
            {5,  "8"},
            {6,  "9"},
            {7,  "10"},
            {8,  "J"},
            {9,  "Q"},
            {10, "K"},
            {11, "A"},
    };
    int l = 0, r = 0;
    bool ok = false;
    while (l < 12 && r < 12) {
        while (cnt[r] >= 1) {
            r++;
        }
        if (r - l >= 5) {
            ok = true;
            for (int i = l; i < r; ++i) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
        l = r + 1;
        r = l + 1;
    }
    if (!ok) {
        cout << "No";
    }
    return 0;
}