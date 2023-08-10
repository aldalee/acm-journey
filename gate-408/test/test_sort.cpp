//
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct structTest{
    int a;
    int b;
};
bool cmp(const structTest& st1,const structTest& st2){
    if (st1.a == st2.a)
        return st1.b < st2.b;
    return st1.a < st2.a;
}
int main(){
    structTest array[6] = {
            {1,2},
            {-1,-2},
            {0,4},
            {7,9},
            {0,6},
            {0,-1}
    };
    int n = 6;
    sort(array,array+n,cmp);
    for (int i = 0; i < n; ++i)
        cout << array[i].a << "," << array[i].b << endl;
    return 0;
}