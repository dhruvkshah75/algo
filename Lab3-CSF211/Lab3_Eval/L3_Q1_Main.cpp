#include "./L3_Q1_solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        vector<int> difficulty(x);
        for (int i = 0; i < x; i++) {
            std::cin >> difficulty[i];
        }
        vector<int> profit(y);
        for (int i = 0; i < y; i++) {
            std::cin >> profit[i];
        }
        vector<int> worker(z);
        for (int i = 0; i < z; i++) {
            std::cin >> worker[i];
        }
        int result = solve(x, difficulty, profit, z, worker);
        std::cout << result << std::endl;
    }

    return 0;
}