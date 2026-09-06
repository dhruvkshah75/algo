#include <iostream>
#include <vector>

#include "L9_Q1_solution.cpp"

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::pair<int, int>> c(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> c[i].first >> c[i].second;
        }

        std::vector<int> result = solve(n, m, c);

        if (result.empty()) {
            std::cout << -1 << "\n";
        }
        else {
            for (int i = 0; i < result.size(); ++i) {
                std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }

    return 0;
}