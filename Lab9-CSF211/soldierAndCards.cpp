#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/546/C

void solve(int n) {
    // use two dequeue to simulate the game => only problem when the game does not end (infinite loop)
    // game can run (n+1)! max => so keep the upper limit as 1e6 

    int k1, k2; cin >> k1;

    deque<int> p1, p2;

    for(int i = 0; i < k1; i++) {
        int x; cin >> x;
        p1.push_back(x);
    }

    cin >> k2;

    for(int i = 0; i < k2; i++) {
        int x; cin >> x;
        p2.push_back(x);
    }

    int moves = 0;

    while(!p1.empty() && !p2.empty()) {
        moves++;

        if(moves > 1e6) {
            // most fights in worst case is 11!
            cout << -1 << endl;
            return;
        }

        int card1 = p1.front();
        p1.pop_front();

        int card2 = p2.front();
        p2.pop_front();

        if(card1 > card2) {
            // player 1 wins  
            p1.push_back(card2);
            p1.push_back(card1);
        }
        else {
            // player 2 wins 
            p2.push_back(card1);
            p2.push_back(card2);
        }
    }

    if(p1.empty()) {
        // player 1 loses 
        cout << moves << " " << 2 << endl;
    }
    else {
        cout << moves << " " << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    solve(n);
}