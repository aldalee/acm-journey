// http://acm.hdu.edu.cn/showproblem.php?pid=1062
// Description: Text Reverse
// Input: olleh !dlrow
// OutPut: hello world!

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf_s("%d", &n);
    getchar();
    while (n--) {
        stack<char> s;
        while (true) {
            int ch = getchar();                             // 一次读入一个字符
            if (ch == ' ' || ch == '\n' || ch == EOF) {
                while (!s.empty()) {                        // 输出并清空栈
                    printf("%c", s.top());
                    s.pop();
                }
                if (ch == '\n' || ch == EOF) break;
                printf(" ");
            } else {
                s.push(static_cast<char>(ch));           // 入栈
            }
        }
        printf("\n");
    }
    return 0;
}