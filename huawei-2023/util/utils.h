#ifndef HW_2023_UTILS_H
#define HW_2023_UTILS_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int generate_random_n(int max_value) {
    srand(time(nullptr));
    return rand() % max_value + 1;
}

std::vector<int> generate_random_array(int max_len, int max_value) {
    srand(time(nullptr));       // 设置随机数种子
    std::vector<int> arr(max_len);
    for (int i = 0; i < max_len; i++) {
        arr[i] = rand() % max_value + 1;  // 生成[1, max_value]范围内的随机数
    }
    return arr;
}

std::vector<int> generate_random_unique_array(int size, int min, int max) {
    std::vector<int> arr(size);
    // 使用当前时间作为随机数种子
    std::srand(std::time(nullptr));
    // 生成需要的不重复的随机数
    for (int i = 0; i < size; ++i) {
        arr[i] = min + std::rand() % (max - min + 1);
    }
    // 检查并去除重复值
    std::sort(arr.begin(), arr.end());
    auto last = std::unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    return arr;
}

#endif //HW_2023_UTILS_H
