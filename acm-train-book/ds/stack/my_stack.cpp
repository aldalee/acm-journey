// hdu1062,手写栈
#include <bits/stdc++.h>

using namespace std;
const int N = 100100;

struct my_stack {
    char arr[N]{};
    int t = 0;

    void push(char x) {
        arr[++t] = x;
    }

    char top() {
        return arr[t];
    }

    void pop() {
        t--;
    }

    bool empty() const {
        return t == 0;
    }
} st;

int main() {
    int n;
    scanf_s("%d", &n);
    getchar();
    while (n--) {
        while (true) {
            int ch = getchar();
            if (ch == ' ' || ch == '\n' || ch == EOF) {
                while (!st.empty()) {
                    printf("%c", st.top());
                    st.pop();
                }
                if (ch == '\n' || ch == EOF) {
                    break;
                }
                printf(" ");
            } else {
                st.push(static_cast<char>(ch));
            }
        }
        printf("\n");
    }
    return 0;
}