#include "./L2_Q1_solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i] >> b[i];
        }

        long long ans = solve(n, a, b);
        std::cout << ans << std::endl;
    }
    return 0;
}