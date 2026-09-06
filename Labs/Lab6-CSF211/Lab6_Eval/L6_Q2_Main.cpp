#include <iostream>
#include <vector>

#include "L6_Q2_solution.cpp"

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> h[i];
        }

        int l, b;
        std::cin >> l >> b;

        int result = solve(n, h, l, b);
        std::cout << result << "\n";
    }

    return 0;
}