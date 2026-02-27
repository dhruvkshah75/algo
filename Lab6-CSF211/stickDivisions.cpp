#include<bits/stdc++.h>
using namespace std;

// question link: https://cses.fi/problemset/task/1161
// A simple usage of priority queue question 

/*
    If the stick of size x = 24 and n = 6 
    The config is        2 2 3 5 6 6 
    The best way to get the min cost is take the smallest 2 elements then add them and insert into the heap again 
    Here 2 + 2 = 4 
    the min_heap becomes 3 4 5 6 6 
    We keep doing this => this is the most optimised way to solve the question 
*/


void solve(vector<int>&sticks, int x) {

    // we have n sticks => we must combine the sticks to form stick of length of x 
    // the best way to combine to minimize the cost is to combine to 2 smallest sticks 

    // min heap 
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int stick: sticks) {
        min_heap.push(stick);
    }

    long long cost = 0;

    while(min_heap.size() > 1) {
        // get the two smallest sticks and then combine them 
        int stick1 = min_heap.top();
        min_heap.pop();

        int stick2 = min_heap.top();
        min_heap.pop();

        cost += (long long)stick1 + stick2;

        // now the push the combined stick into the min heap 
        min_heap.push(stick1 + stick2);
    }

    cout << cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    vector<int> sticks(n);

    for(int i=0; i<n; i++) 
        cin >> sticks[i];

    solve(sticks, x);
}
