#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    b[0] = a[0];

    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
