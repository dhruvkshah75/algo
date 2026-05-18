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

// question link: https://codeforces.com/problemset/problem/1907/D

bool canReach(int n, vector<pii> &segments, int k) {

    /* true => if we can reach the end with jumps <= k
       maintain a interval of all the allowed jumps and check if nth turn is reachable or not 
       Left and Right is the current jumping interval */

    int left = 0, right = 0;

    for(int i = 0; i < n; i++) {
        auto [a, b] = segments[i];

        int maxLeft = max(0, left - k);
        int maxRight = right + k;

        // check if the player can jump into the current interval 
        if(maxLeft > b || maxRight < a) 
            return false;
        
        // keep the interval such that a <= x <= b  -> at best 
        left = max(maxLeft, a);
        right = min(maxRight, b);
    }

    return true;
}

void solve(int n, vector<pii> &segments) {
    // apply binary search on answer for minimum jump length k

    // predicate function returns FFFFTTTTT => find the first occurrence of T
    int result = 0;
    int l = 0, r = 1e9;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canReach(n, segments, mid)) {
            r = mid - 1;
            result = mid;
        }
        else l = mid + 1;
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pii> segments(n);

        for(int i = 0; i < n; i++) 
            cin >> segments[i].first >> segments[i].second;

        solve(n, segments);
    }
}