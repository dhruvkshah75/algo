#include <iostream>
#include <vector>

#include "L8_Q2_solution.cpp"

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

        std::vector<std::vector<int>> flights(m, std::vector<int>(3));
        for (int i = 0; i < m; ++i) {
            std::cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
        }

        long long result = solve(n, m, flights);
        std::cout << result << "\n";
    }

    return 0;
}