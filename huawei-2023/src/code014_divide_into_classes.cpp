// 分班 AC
#include <bits/stdc++.h>

using namespace std;

// 定义字符串分割函数
vector<string> split(const string &s, char delim) {
    vector<string> res;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delim)) {
        res.push_back(token);
    }
    return res;
}

bool is_valid(string &s) {
    return all_of(s.begin(), s.end(), [](char c) {
        return isdigit(c) || isspace(c) || c == '/' || c == 'N' || c == 'Y';
    });
}

int main() {
    string info;
    getline(cin, info);
    // 合法性检测
    if (!is_valid(info)) {
        cout << "ERROR";
        return 0;
    }
    // 字符串切割
    vector<pair<int, string>> stus;
    for (string &stu: split(info, ' ')) {
        vector<string> t = split(stu, '/');
        int id = stoi(t[0]);
        // 合法性检测
        if (id < 0 || id > 999) {
            cout << "ERROR";
            return 0;
        }
        stus.emplace_back(id, t[1]);
    }
    // 合法性检测
    if (stus.size() > 999) {
        cout << "ERROR";
        return 0;
    }
    // 统计各班学生
    int cnt = 0;
    vector<int> class_a;
    vector<int> class_b;
    for (auto &stu: stus) {
        if (stu.second == "N") {
            cnt++;
        }
        if (cnt % 2 != 0) {
            class_a.push_back(stu.first);
        } else {
            class_b.push_back(stu.first);
        }
    }
    // 排序
    sort(class_a.begin(), class_a.end());
    sort(class_b.begin(), class_b.end());
    // 输出结果
    for_each(class_a.begin(), class_a.end(), [](int x) { cout << x << " "; });
    cout << endl;
    if (!class_b.empty()) {
        for_each(class_b.begin(), class_b.end(), [](int x) { cout << x << " "; });
    } else {
        cout << endl;
    }
    return 0;
}