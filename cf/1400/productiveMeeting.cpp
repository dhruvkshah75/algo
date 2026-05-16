#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1579/D

void solve(int n) {
    
    priority_queue<pii> pq;
    // max heap = {sociability left, person index}

    vector<pii> result;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if(x == 0) continue;

        pq.push({x, i});
    }

    while(pq.size() >= 2) {
        auto [s1, p1] = pq.top();
        pq.pop();

        auto [s2, p2] = pq.top();
        pq.pop();

        result.push_back({p1, p2});

        s1--; s2--;
        // add this person back if sociability > 0
        if(s1 > 0) {
            pq.push({s1, p1});
        }
        
        if(s2 > 0) {
            pq.push({s2, p2});
        }
    }


    cout << result.size() << endl;

    for(auto [p1, p2]: result) 
        cout << p1 << " " << p2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // Summation over a[i] <= 2e5
        solve(n);
    }
}