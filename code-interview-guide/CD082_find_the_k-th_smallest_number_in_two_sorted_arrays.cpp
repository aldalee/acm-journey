// 在两个排序数组中找到第k小的数
#include <bits/stdc++.h>

using namespace std;

int getUpMedian(vector<int> A, int L1, int R1, vector<int> B, int L2, int R2) {
    int mid1, mid2, offset;
    while (L1 < R1) {
        mid1 = L1 + ((R1 - L1) >> 1);
        mid2 = L2 + ((R2 - L2) >> 1);
        offset = ((R1 - L1 + 1) & 1) ^ 1;
        if (A[mid1] > B[mid2]) {
            R1 = mid1;
            L2 = mid2 + offset;
        } else if (A[mid1] < B[mid2]) {
            L1 = mid1 + offset;
            R2 = mid2;
        } else {
            return A[mid1];
        }
    }
    return min(A[L1], B[L2]);
}

int findKthNum(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> shorts = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int> longs = nums1.size() >= nums2.size() ? nums1 : nums2;
    int s = (int) shorts.size();
    int l = (int) longs.size();
    if (k <= s) {
        return getUpMedian(shorts, 0, k - 1, longs, 0, k - 1);
    } else if (k <= l) {
        if (longs[k - s - 1] >= shorts[s - 1]) {
            return longs[k - s - 1];
        }
        return getUpMedian(shorts, 0, s - 1, longs, k - s, k - 1);
    } else {
        if (shorts[k - l - 1] >= longs[l - 1]) {
            return shorts[k - l - 1];
        }
        if (longs[k - s - 1] >= shorts[s - 1]) {
            return longs[k - s - 1];
        }
        return getUpMedian(shorts, k - l, s - 1, longs, k - s, l - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums1(n);
    vector<int> nums2(m);
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums1[i] = x;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x;
        nums2[i] = x;
    }
    cout << findKthNum(nums1, nums2, k);
    return 0;
}