#include "./L2_Q2_solution.cpp"
#include <iostream>

using namespace std;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        char result = solve(n, k);
        std::cout << result << std::endl;
    }

    return 0;
}