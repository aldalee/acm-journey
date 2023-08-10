// 最远足迹 AC
#include <bits/stdc++.h>

using namespace std;

bool is_valid_coordinate(int x, int y) {
    return (x > 0 && x < 1000 && y > 0 && y < 1000);
}

pair<int, int> get_farthest_footprint(string &data) {
    int max_distance = 0;
    pair<int, int> coord = make_pair(0, 0);
    size_t idx;
    size_t l = data.find('(');
    while (l != string::npos) {
        size_t comma = data.find(',', l);
        size_t r = data.find(')', comma);
        if (comma != string::npos && r != string::npos) {
            string x_str = data.substr(l + 1, comma - l - 1);
            string y_str = data.substr(comma + 1, r - comma - 1);
            if (x_str[0] != '0' && y_str[0] != '0') {
                int x = stoi(x_str);
                int y = stoi(y_str);
                if (is_valid_coordinate(x, y)) {
                    int distance = x * x + y * y;
                    if (distance > max_distance) {
                        max_distance = distance;
                        coord = make_pair(x, y);
                    }
                }
            }
        }
        idx = r + 1;
        l = data.find('(', idx);
    }
    return coord;
}

int main() {
    string data;
    getline(cin, data);
    pair<int, int> coord = get_farthest_footprint(data);
    printf("(%d,%d)", coord.first, coord.second);
    return 0;
}