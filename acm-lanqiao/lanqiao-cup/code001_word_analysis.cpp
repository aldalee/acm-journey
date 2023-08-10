//https://www.lanqiao.cn/problems/504/learning/
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    //[a,z]的ASCII码对应[97,122]
    int count[26] = {};
    for (char i: s) {
        count[i - 97]++;
    }
    int max = -1;
    int index;
    for (int i = 25; i >= 0; --i) {
        if (count[i] >= max) {
            max = count[i];
            index = i;
        }
    }
    cout << (char) (index + 97) << endl;
    cout << max;
    return 0;
}