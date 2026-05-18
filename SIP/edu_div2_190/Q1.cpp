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

// question link: https://codeforces.com/contest/2230/problem/A

void solve(ll n, ll a, ll b) {
    // n = number of students, a = cost of individual key, b = cost of group key

    // if individual keys are cheaper 
    if (3 * a <= b) {
        cout << n * a << endl;
        return;
    }

    ll full_groups = n / 3;
    ll remainder = n % 3;

    ll total = full_groups * b;
    
    if(remainder == 1) {
        total += min(a, b);
    }
    else if(remainder == 2) {
        total += min(2 * a, b);
    }

    cout << total << endl;
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
        ll n, a, b;
        cin >> n >> a >> b;

        solve(n, a, b);
    }
}