#include <iostream>
#include <vector>

#include "L7_Q2_solution.cpp"

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

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int k;
        std::cin >> k;

        long long result = solve(n, a, k);
        std::cout << result << "\n";
    }

    return 0;
}