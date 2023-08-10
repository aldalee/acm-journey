// https://www.luogu.com.cn/problem/P3366
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5005, M = 2e5 + 1;
struct Edge {
    int u, v, w;
} edge[M];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int s[N];   // 并查集
int find(int x) {
    if (x != s[x]) {
        s[x] = find(s[x]);
    }
    return s[x];
}

int n, m;

void kruskal() {
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        s[i] = i;
    }
    int sum = 0, cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (cnt == n - 1) break;
        int e1 = find(edge[i].u);
        int e2 = find(edge[i].v);
        if (e1 != e2) {
            sum += edge[i].w;
            s[e1] = e2;
            cnt++;
        }
    }
    if (cnt == n - 1) cout << sum; else cout << "orz";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal();
    return 0;
}