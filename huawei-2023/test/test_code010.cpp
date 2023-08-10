#include <bits/stdc++.h>
#include "../util/utils.h"

int right(std::vector<int> price, int r) {
    int sum = -1;
    for (int i = 0; i < price.size(); ++i) {
        for (int j = i + 1; j < price.size(); ++j) {
            for (int k = j + 1; k < price.size(); ++k) {
                int t = price[i] + price[j] + price[k];
                if (t <= r) {
                    sum = std::max(t, sum);
                }
            }
        }
    }
    return sum;
}

int f(std::vector<int> price, int r) {
    int n = (int) price.size();
    sort(price.begin(), price.end());
    int max_cost = -1;
    // 使用双指针求解最大花费额度
    // i、j、k分别指向数组中的第一个、第二个和最后一个元素
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int cost = price[i] + price[j] + price[k];
            if (cost == r) {
                std::cout << r << std::endl;
                return 0;
            } else if (cost < r) {
                max_cost = std::max(max_cost, cost);
                j++;
            } else {
                k--;
            }
        }
    }
    return max_cost;
}

int main() {
    int max_value = 1000;
    int max_len = 100;
    int test_times = 10000;
    bool success = true;
    for (int i = 0; i < test_times; ++i) {
        int r = generate_random_n(100000);
        std::vector<int> price = generate_random_array(max_len, max_value);
        int expect = right(price, r);
        int actual = f(price, r);
        if (expect != actual) {
            std::cout << "r = " << r << std::endl;
            std::cout << "price = ";
            for_each(price.begin(), price.end(), [](int x) { std::cout << x << " "; });
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