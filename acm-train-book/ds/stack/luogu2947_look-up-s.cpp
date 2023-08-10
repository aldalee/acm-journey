// https://www.luogu.com.cn/problem/P2947
// Description: Look Up S
// Input: 6 3 2 6 1 1 2
// OutPut: 3 3 0 6 6 0

#include <iostream>
#include <stack>

using namespace std;
const int N = 100001;
int h[N], ans[N];

int main() {
    int n;
    scanf_s("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf_s("%d", &h[i]);
    }
    stack<int> s;               //单调栈
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && h[s.top()] <= h[i]) {
            s.pop();            //栈顶奶牛没有i高，弹出它，直到栈顶奶牛更高为止
        }
        if (s.empty()) {
            ans[i] = 0;         //栈空，没有仰望对象
        } else {
            ans[i] = s.top();   //栈顶奶牛更高，是仰望对象
        }
        s.push(i);           //进栈
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}