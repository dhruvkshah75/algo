#include <iostream>
#include <vector>

#include "L9_Q2_solution.cpp"

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int S, P;
        std::cin >> S >> P;

        std::vector<std::pair<int, int>> outposts(P);
        for (int i = 0; i < P; ++i) {
            std::cin >> outposts[i].first >> outposts[i].second;
        }

        int result = solve(S, P, outposts);
        std::cout << result << "\n";
    }

    return 0;
}