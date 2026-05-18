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

// question link: https://codeforces.com/contest/2225/problem/B

void solve(string &str) {
    // only two possible substrings => ababa.. or babab...

    // conflicts more than 2 cannot be fixed 
    int n = str.length();

    int conflicts = 0;
    // conflict occured at i, i+1 

    for(int i = 0; i + 1 < n; i++) {
        if(str[i] == str[i+1]) conflicts++;
    }

    if(conflicts <= 2) { yes; }
    else { no; }
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
        string str;
        cin >> str;

        solve(str);
    }
}