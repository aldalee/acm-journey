//¡¾Âå¹È¡¿P1996 Ô¼Éª·òÎÊÌâ https://www.luogu.com.cn/problem/P1996
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> node;
    for (int i = 1; i <= n; ++i) {
        node.push_back(i);
    }
    auto it = node.begin();
    while (node.size() > 1) {
        for (int i = 1; i < m; ++i) {
            if (++it == node.end()) it = node.begin();
        }
        cout << *it << " ";
        it = node.erase(it);
        if (it == node.end()) it = node.begin();
    }
    cout << *it;
    return 0;
}