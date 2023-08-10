// https://acm.ecnu.edu.cn/contest/563/problem/I/
// Created by HuanyuLee on 2022/11/30.
// AC
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int index = 0;
    unordered_map<int, int> tmpMap;
    unordered_map<int, int>::iterator it;
    vector<int> mapArr(n,n);
    int read = 0;
    while (index < n) {
        scanf("%d", &read);
        it = tmpMap.find(read);
        if (it != tmpMap.end()) {
            mapArr[tmpMap[read]] = index;
        }
        tmpMap[read] = index++;
    }
    int missTimes = 0;
    set<int, greater<>> cacheSet;
    set<int, greater<>>::iterator itr;
    for (int i = 0; i < n; ++i) {
        itr = cacheSet.find(i);
        if (itr != cacheSet.end()) {
            cacheSet.erase(i);
            cacheSet.insert(mapArr[i]);
            continue;
        }
        if (cacheSet.size() == k) {
            if (mapArr[i] == n) {
                missTimes++;
                continue;
            }
            int cacheNum = *cacheSet.begin();
            if (mapArr[i] <= cacheNum) {
                cacheSet.erase(cacheNum);
                cacheSet.insert(mapArr[i]);
            }
        }
        if (cacheSet.size() < k) {
            cacheSet.insert(mapArr[i]);
        }
        missTimes++;
    }
    cout << missTimes;
    return 0;
}