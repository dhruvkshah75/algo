#include <iostream>
#include <string>
#include "./L8_Q1_solution.cpp"  // Include the solution logic

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string start, end;
        cin >> start >> end;

        cout << min_knight_moves(start, end) << endl;
    }

    return 0;
}
