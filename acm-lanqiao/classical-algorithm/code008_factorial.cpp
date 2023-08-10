//https://www.lanqiao.cn/problems/1515/learning/
#include <iostream>

using namespace std;
#define MAXLENGTH 3000
int digit[MAXLENGTH];

void factorial(const int N) {
    int n = 2;
    int size = 1;
    digit[0] = 1;
    //n! = n * n-1 * n-2 ... * 2 * 1
    while (n <= N) {
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int multi = digit[i] * n;
            digit[i] = (carry + multi) % 10;
            carry = (carry + multi) / 10;
            if (i >= size - 1 && carry > 0) {
                size++;
            }
        }
        n++;
    }
    //打印结果
    for (int i = size - 1; i >= 0; --i) {
        cout << digit[i];
    }
}

int main() {
    int n;
    cin >> n;
    factorial(n);
    return 0;
}