#include <bits/stdc++.h>
#include "../util/utils.h"

int right(std::vector<int> h) {
    int max_area = 0;
    for (int i = 0; i < h.size(); ++i) {
        for (int j = i + 1; j < h.size(); ++j) {
            max_area = std::max(max_area, (j - i) * std::min(h[i], h[j]));
        }
    }
    return max_area;
}


int f(std::vector<int> h) {
    int max_area = 0;
    int l = 0;
    int r = (int) h.size() - 1;
    while (l < r) {
        max_area = std::max(max_area, std::min(h[l], h[r]) * (r - l));
        if (h[l] > h[r]) {
            r--;
        } else {
            l++;
        }
    }
    return max_area;
}

int main() {
    int max_value = 1000;
    int max_len = 100;
    int test_times = 1;
    bool success = true;
    for (int i = 0; i < test_times; ++i) {
        std::vector<int> h = generate_random_unique_array(max_len,1, max_value);
        int expect = right(h);
        int actual = f(h);
        if (expect != actual) {
            std::cout << "h = ";
            for_each(h.begin(), h.end(), [](int x) { std::cout << x << " "; });
            std::cout << std::endl;
            std::cout << "expect = " << expect << std::endl;
            std::cout << "actual = " << actual << std::endl;
            success = false;
            break;
        }
    }
    std::cout << (success ? "AC!" : "Fuck!");
    return 0;
}