#include <iostream>
#include <vector>

#include "L7_Q1_solution.cpp"

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

        std::vector<std::pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> edges[i].first >> edges[i].second;
        }

        int result = solve(n, m, edges);
        std::cout << result << "\n";
    }

    return 0;
}