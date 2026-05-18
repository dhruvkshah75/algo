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

// question link: https://codeforces.com/problemset/problem/1931/D

void solve(int n, int x, int y, vector<int> &arr) {
    // use a hash map to store the info for each element 

    /* note: ai + aj = 0 (mod x) => ai = (x - aj (mod x)) (mod x)
            ai - aj = 0 (mod y) => ai = aj (mod y)
        Note: aj (mod x) = remx or aj (mod y) = remy  */

    // store the two things for a element => (REMx, REMy)
    map<pii,int> mp;

    ll result = 0;

    for(int i = 0; i < n; i++) {
        int rem_x = arr[i] % x;
        int rem_y = arr[i] % y;

        int target_x = (x - rem_x) % x;
        int target_y = rem_y % y;

        if(mp.count({target_x, target_y})) {
            result += mp[{target_x, target_y}];
        }

        // add the remainders for the current number 
        mp[{rem_x, rem_y}]++;
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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) 
            cin >> arr[i];

        solve(n, x, y, arr);
    }
}