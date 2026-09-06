#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/520/B


void solve(int n, int m) {
    // in order for n to become m we apply bfs to get the shortest path to reach m
    // q = {num on screen, level} => level = min number of moves to reach this point  
    queue<pair<int,int>> q;
    unordered_set<int> visited;

    q.push({n, 0});
    visited.insert(n);

    while(!q.empty()) {
        auto [node, moves] = q.front();
        q.pop();

        if(node == m) {
            cout << moves << endl;
            return;
        }

        // always press the blue buttom unless it becomes negative 
        if(node-1 > 0 && visited.find(node-1) == visited.end()) {
            q.push({node-1, moves+1});
            visited.insert(node-1);
        }

        // press the red button only if the number is less than the target 
        if(node < m && visited.find(2*node) == visited.end()) {
            q.push({2*node, moves+1});
            visited.insert(2*node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // n is the initial number on the screen 
    solve(n, m);
}