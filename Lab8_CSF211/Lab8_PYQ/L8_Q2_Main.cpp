#include <iostream>
#include <vector>
#include "./L8_Q2_solution.cpp"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> connections(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        connections[i] = {a, b};
    }

    cout << minReorder(n, connections) << endl;

    return 0;
}
