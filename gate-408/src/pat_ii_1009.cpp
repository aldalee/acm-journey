// 1009 说反话
// https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#include <stack>
using namespace std;
int main(){
    string word;
    stack<string> stack;
    while (cin >> word){
        stack.push(word);
        if (cin.get() == '\n')
            break;
    }
    while(!stack.empty()){
        cout << stack.top();
        if (stack.size() > 1)
            cout << " ";
        stack.pop();
    }
    return 0;
}
