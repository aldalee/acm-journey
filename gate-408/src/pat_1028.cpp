// 1028 List Sorting
// https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct Student{
    int ID{};
    string name;
    int grade{};
};
bool cmp1(const Student& st1,const Student& st2){
    return st1.ID < st2.ID;
}
bool cmp2(const Student& st1,const Student& st2){
    if (st1.name == st2.name || st1.grade == st2.grade)
        return st1.ID < st2.ID;
    return st1.name < st2.name;
}
bool cmp3(const Student& st1,const Student& st2){
    if (st1.name == st2.name || st1.grade == st2.grade)
        return st1.ID < st2.ID;
    return st1.grade < st2.grade;
}
int main(){
    int N,C;
    cin >> N >> C;
    Student student[N];
    for (int i = 0; i < N; ++i) {
        cin >> student[i].ID >> student[i].name >> student[i].grade;
    }
    if (C == 1)
        sort(student,student+N, cmp1);
    else if (C == 2)
        sort(student,student+N, cmp2);
    else
        sort(student,student+N, cmp3);
    for (int i = 0; i < N; ++i) {
        printf("%06d %s %d\n",student[i].ID,student[i].name.c_str(),student[i].grade);
    }
    return 0;
}
