// 村庄和部落
// AC
// http://oj.ecustacm.cn/problem.php?id=1823
#include <bits/stdc++.h>

using namespace std;

pair<int, int> getNumbersOfTribes(const string &s) {
    int a = 0, b = 0;
    int l = -1;
    for (int r = 0; r < s.length(); ++r) {
        if (s[r] != '.') {
            if (l != -1 && s[l] == s[r]) {
                if (s[r] == 'A') {
                    a += r - l;
                } else {
                    b += r - l;
                }
            } else if (s[r] == 'A') {
                a++;
            } else {
                b++;
            }
            l = r;
        }
    }
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;
        auto res = getNumbersOfTribes(s);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
