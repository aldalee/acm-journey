// http://oj.ecustacm.cn/problem.php?id=1830
// 房间划分
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 1;

struct point {
    double x{}, y{};

    point() = default;

    point(double x, double y) : x(x), y(y) {}

    point operator+(point p) const { return {x + p.x, y + p.y}; }

    point operator-(point p) const { return {x - p.x, y - p.y}; }

    point operator*(double k) const { return {k * x, k * y}; }
} p[N];

typedef point Vector;

// 叉积
double cross(Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}

// 三角形面积
double area(point a, point b, point c) {
    return 0.5 * cross(b - a, c - a);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    double s = 0;   // 多边形面积
    for (int i = 2; i <= n - 1; ++i) {
        s += area(p[1], p[i], p[i + 1]);
    }
    s *= 0.5;
    double a = 0;   // 重新开始累加三角形面积
    for (int i = 2; i <= n - 1; ++i) {
        double b = a + area(p[1], p[i], p[i + 1]);
        // 找到平分总面积的三角形
        if (a <= s && b >= s) {
            double t = (s - a) / (b - a);           // 比例
            point delta = (p[i + 1] - p[i]) * t;    // 两点中间等比例处是答案
            point ans = p[i] + delta;
            printf("%.9f %.9f\n", ans.x, ans.y);
            break;
        }
        a = b;
    }
    return 0;
}