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

// question link: https://codeforces.com/contest/2230/problem/C

void solve(int n, vector<int> &c) {
    
    /* fill the places with same numbers adjacent to each other 
       eg 5555522223333.... [5, 5, 5] => valid, [5, 5, 2] => valid, [5, 2, 2] => valid 
       element with c[i] = 1 can only work if it is clustered inside like this [5, 5, 3, 5, 5] 
       Categorize the numbers with cnt more than 1 as large as they can form grps */

    vector<int> large;
    int ones = 0;

    for(int i = 1; i <= n; i++) {
        if(c[i] == 1)   
            ones++;
        else if(c[i] >= 2) 
            large.push_back(c[i]);
    }

    // if there are no large count cards then no circle can be formed 
    if(large.empty()) {
        cout << 0 << endl;
        return;
    }

    ll sum_large = 0, total_capacity = 0;

    for(int x: large) 
        sum_large += (ll)x;


    // now cnt the number of elements in the middle 
    if(large.size() == 1) 
        total_capacity = large[0] / 2; 
    else 
        for(int x: large) 
            total_capacity += (ll)(x / 2) - 1;
    
    ll result = sum_large + min((ll)ones, total_capacity);

    if(result < 3) cout << 0 << endl;
    else cout << result << endl;
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

        vector<int> cards(n+1, 0);

        for(int i = 1; i <= n; i++) 
            cin >> cards[i];

        solve(n, cards);
    }
}