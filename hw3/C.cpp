#include <iostream>
#include <deque>
#include <vector>

std::vector<int> sliding_window_minimum(const std::vector<int>& arr, int n, int k) {
    std::deque<int> dq;
    std::vector<int> result;

    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> result = sliding_window_minimum(arr, n, k);

    for (int min_val : result) {
        std::cout << min_val << std::endl;
    }

    return 0;
}
