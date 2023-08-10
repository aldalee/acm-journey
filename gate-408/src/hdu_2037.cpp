// 杭电OJ2037 今年暑假不AC
// 区间贪心问题
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct Program{
    int start;
    int end;
};
// 按节目的开始时间从大到小排序，如果开始时间相同，则按结束时间从小到大排序
bool cmp(Program& L,Program& R){
    if (L.start == R.start)
        return L.end < R.end;
    else
        return L.start > R.start;
}
int main(){
    Program programs[100];
    int n;
    while (cin >> n){
        if (n == 0)
            break;
        int count = 1,lastProgramStart;    //第一个开始时间最大的被选中
        for (int i = 0; i < n; ++i) {
            cin >> programs[i].start >> programs[i].end;
        }
        sort(programs,programs+n, cmp);
        lastProgramStart = programs[0].start;
        for (int i = 1; i < n; ++i){
            if (programs[i].end <= lastProgramStart){
                ++count;
                lastProgramStart = programs[i].start;
            }
        }
        cout << count << endl;
    }
    return 0;
}
