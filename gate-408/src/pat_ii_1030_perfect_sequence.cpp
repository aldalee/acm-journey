// 1030 完美数列
// AC
// https://pintia.cn/problem-sets/994805260223102976/problems/994805291311284224
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int l, int r, long long key, const long long arr[]) {
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    long long p;
    cin >> n >> p;
    long long arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int max = 1;
    for (int i = 0; i < n; ++i) {
        int k = binarySearch(i + 1, n - 1, p * arr[i], arr);
        if (max < k - i + 1) {
            max = k - i + 1;
        }
    }
    cout << max << endl;
    return 0;
}