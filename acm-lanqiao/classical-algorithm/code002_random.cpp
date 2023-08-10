//https://www.lanqiao.cn/problems/539/learning/
#include <iostream>

#define MAXLENGTH 1001
using namespace std;
int num[MAXLENGTH];

int main() {
    int N, t;
    cin >> N;
    int count = N;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        num[t]++;
        if (num[t] > 1){
            count--;
        }
    }
    cout << count << endl;
    for (int i = 0; i < MAXLENGTH; ++i) {
        if (num[i] != 0){
            cout << i << " ";
        }
    }
    return 0;
}