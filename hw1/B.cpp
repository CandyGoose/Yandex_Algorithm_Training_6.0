#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::vector<std::pair<int, int>> options;

    if (a > 0 && c > 0) {
        options.emplace_back(b + 1, d + 1);
    }

    if (b > 0 && d > 0) {
        options.emplace_back(a + 1, c + 1);
    }

    if (a > 0 && b > 0) {
        options.emplace_back(std::max(a, b) + 1, 1);
    }

    if (c > 0 && d > 0) {
        options.emplace_back(1, std::max(c, d) + 1);
    }

    auto compare = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    };

    auto answer = std::min_element(options.begin(), options.end(), compare);

    std::cout << answer->first << ' ' << answer->second << std::endl;

    return 0;
}
