// 1043 输出PATest
// https://pintia.cn/problem-sets/994805260223102976/problems/994805280074743808
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
using namespace std;
int main(){
    string s;
    int count[200] = {};
    string dic = "PATest";
    getline(cin,s);
    for (int i = 0; s[i] != '\0'; ++i) {
        ++count[s[i]-'0'];
    }
    while (true){
        bool flag = false;
        for (int i = 0; dic[i] != '\0'; ++i) {
            int index = dic[i]-'0';
            if (count[index] > 0){
                cout << dic[i];
                --count[index];
                flag = true;
            }
        }
        if (!flag)
            break;
    }
    return 0;
}

