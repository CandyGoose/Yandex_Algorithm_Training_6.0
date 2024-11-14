#include <iostream>
#include <vector>
#include <stack>

std::vector<int> findMigrationCities(int N, const std::vector<int>& prices) {
    std::vector<int> result(N, -1);
    std::stack<int> stack;

    for (int i = N - 1; i >= 0; --i) {
        while (!stack.empty() && prices[stack.top()] >= prices[i]) {
            stack.pop();
        }
        if (!stack.empty()) {
            result[i] = stack.top();
        }
        stack.push(i);
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> prices(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> prices[i];
    }

    std::vector<int> result = findMigrationCities(N, prices);

    for (int city : result) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return 0;
}
