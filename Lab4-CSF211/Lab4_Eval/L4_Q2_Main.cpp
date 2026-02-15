#include "./L4_Q2_solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        long long k;
        std::cin >> k;

        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        long long result = solve(n, a, k);

        std::cout << result << "\n";
    }

    return 0;
}
