// 选修课 AC
#include <bits/stdc++.h>

using namespace std;

struct stu {
    string id;      // 学生学号
    int score1;     // 学生第一门选修课成绩
    int score2;     // 学生第二门选修课成绩
    // 定义小于运算符，用于排序
    bool operator<(const stu &o) const {
        // 按照两门选修课成绩和的降序排序
        if (score1 + score2 != o.score1 + o.score2) {
            return score1 + score2 > o.score1 + o.score2;
        }
        // 成绩相同时，按照学生的学号升序排序
        return id < o.id;
    }
};

// 定义字符串分割函数
vector<string> split(const string &s, char delim) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// 将选修课的学生成绩存储到一个map中
map<string, int> put(string &scores) {
    map<string, int> course;
    for (string &student: split(scores, ';')) {
        vector<string> tokens = split(student, ',');
        course[tokens[0]] = stoi(tokens[1]);
    }
    return course;
}

int main() {
    string scores1, scores2;
    getline(cin, scores1);
    getline(cin, scores2);
    // key: stu_id      value: stu_score
    map<string, int> course1 = put(scores1);
    map<string, int> course2 = put(scores2);

    // 将同时选修了两门选修课的学生按照班级进行分组
    // key: class_id    value: stus
    map<string, vector<stu>> classes;
    for (auto &[id, score]: course1) {
        if (course2.count(id) > 0) {
            string class_id = id.substr(0, 5);
            classes[class_id].push_back({id, score, course2[id]});
        }
    }

    if (classes.empty()) {
        cout << "NULL" << endl;
        return 0;
    }
    for (auto &[class_id, stus]: classes) {
        sort(stus.begin(), stus.end());
        cout << class_id << endl;
        for (size_t i = 0; i < stus.size(); ++i) {
            if (i > 0) {
                cout << ";";
            }
            cout << stus[i].id;
        }
        cout << endl;
    }
    return 0;
}