#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> carNumbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> carNumbers[i];
    }

    std::unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; 

    int currentSum = 0;
    int result = 0;

    for (int i = 0; i < N; ++i) {
        currentSum += carNumbers[i];

        if (prefixSumCount.find(currentSum - K) != prefixSumCount.end()) {
            result += prefixSumCount[currentSum - K];
        }

        prefixSumCount[currentSum]++;
    }

    std::cout << result << std::endl;

    return 0;
}
