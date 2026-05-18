#include <iostream>
#include <vector>

#include "L8_Q1_solution.cpp"

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int V, E;
        std::cin >> V >> E;

        std::vector<std::pair<int, int>> edges(E);
        for (int i = 0; i < E; ++i) {
            std::cin >> edges[i].first >> edges[i].second;
        }

        int result = solve(V, E, edges);
        std::cout << result << "\n";
    }

    return 0;
}