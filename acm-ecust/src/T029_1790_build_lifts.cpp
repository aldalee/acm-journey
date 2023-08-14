// http://oj.ecustacm.cn/problem.php?id=1790
// 造电梯
#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y, h;

    point(int x, int y, int h) {
        this->x = x;
        this->y = y;
        this->h = h;
    };

    bool operator<(const point &p) const {
        return (h < p.h);
    }
};

int n, m;
int arr[501][501];
int dx[4] = {1, 0, -1, 0}; // 上下左右
int dy[4] = {0, 1, 0, -1};
bool done[501][501];

void floodFill(int x, int y) {
    done[x][y] = true;
    for (int i = 0; i < 4; ++i) {   // 扩散周围与它等高或矮的点
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || done[nx][ny]) {
            continue;
        }
        if (arr[nx][ny] <= arr[x][y]) {
            floodFill(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    priority_queue<point> heap; // 大根堆
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            cin >> arr[i][j];
            done[i][j] = (arr[i][j] <= 1);
            if (arr[i][j] > 1) {
                heap.push(point(i, j, arr[i][j]));
            }
        }
    }
    int ans = 0;
    while (!heap.empty()) {
        point p = heap.top();
        heap.pop();
        if (!done[p.x][p.y]) {
            floodFill(p.x, p.y);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}