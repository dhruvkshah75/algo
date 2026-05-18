#include "./L4_Q1_solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int q;
        std::cin >> q;

        std::vector<int> A(n);
        std::vector<int> queries(q);

        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }
        for (int i = 0; i < q; i++) {
            std::cin >> queries[i];
        }

        std::vector<int> ans = solve(n, A, q, queries);

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i]) {
                std::cout << "Yes";
            }
            else {
                std::cout << "No";
            }
            std::cout << (i == ans.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
