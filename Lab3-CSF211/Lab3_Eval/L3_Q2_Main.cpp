#include "./L3_Q2_solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, r;
        std::cin >> n >> k >> r;
        std::vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            std::cin >> stations[i];
        }
        long long ans = solve(n, stations, r, k);
        std::cout << ans << std::endl;
    }

    return 0;
}