#include <iostream>
#include <vector>

#include "L5_Q2_solution.cpp"

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

        std::vector<int> position(n), speed(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> position[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> speed[i];
        }

        std::vector<int> result = solve(n, position, speed);

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << result[i];
        }
        std::cout << "\n";
    }

    return 0;
}