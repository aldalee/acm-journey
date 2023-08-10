// IPv4地址转换成整数 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    // 空串
    if (s.empty()) {
        cout << "invalid IP";
        return 0;
    }
    // 含有IP地址中不存在的字符
    for (char c : s) {
        if (!isdigit(c) && c != '#') {
            cout << "invalid IP";
            return 0;
        }
    }
    stringstream ss(s);
    vector<int> res;
    while (getline(ss, t, '#')) {
        res.push_back(stoi(t));
    }
    // 非法的#分十进制、十进制整数不在合法区间内
    for (int i = 1; i < res.size(); ++i) {
        if (res.size() != 4 || res[0] > 128 || res[0] < 1 || res[i] < 0 || res[i] > 255) {
            cout << "invalid IP";
            return 0;
        }
    }
    // 合法IPV4地址
    unsigned int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += (unsigned int) pow(256, 3 - i) * res[i];
    }
    cout << ans;
    return 0;
}