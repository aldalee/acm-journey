// 敏感字段加密 AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;                  // 敏感字段的索引
    string s;               // 命令字符串
    string cmd;             // 当前正在解析的命令字
    vector<string> res;     // 存储解析出的命令字序列
    cin >> k >> s;

    for (char c: s) {
        if (c == '_' && (cmd.empty() || cmd[0] != '"')) {   // 当遇到下划线且不在双引号内时
            res.push_back(cmd);
            cmd.clear();
        } else if (c == '"' && !cmd.empty()) {              // 当遇到双引号且当前命令字非空时
            cmd += '"';
            res.push_back(cmd);
            cmd.clear();
        } else {                                            // 否则将该字符加入当前命令字
            cmd += c;
        }
    }
    if (!cmd.empty()) {     // 将最后一个命令字加入命令字序列
        res.push_back(cmd);
    }

    // 删除命令字序列中的空命令字
    res.erase(remove(res.begin(), res.end(), ""), res.end());
    // 输出结果
    if (k >= res.size()) {
        cout << "ERROR" << endl;
    } else {
        res[k] = "******";
        cout << res[0];
        for (int i = 1; i < res.size(); ++i) {
            cout << '_' << res[i];
        }
    }

    return 0;
}