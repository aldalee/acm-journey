// 村庄和部落
// AC
// http://oj.ecustacm.cn/problem.php?id=1823
#include <bits/stdc++.h>

using namespace std;

pair<int, int> getNumbersOfTribes(const string &s) {
    int a = 0, b = 0;
    int l = -1;
    for (int r = 0; r < s.length(); ++r) {  // 从第一个字符s[0]开始扫描
        if (s[r] != '.') {                  // r停在A或B上
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
            l = r;                           // 这一轮计算结束，开始下一轮
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
