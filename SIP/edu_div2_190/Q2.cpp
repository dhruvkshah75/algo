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

// question link: https://codeforces.com/contest/2230/problem/B

void solve(string &str) {
    int n = str.length();
    // the string should not contain multiple of 4s 

    /* Maintain the counts of elements that we would keep in the beautiful 
       sequence  => a beautiful sequence is of the form 22..213133311...
       Starting with 2s in the first zone and then random 1s or 3s */

    int cnt_2 = 0, cnt_13 = 0;

    for(int i = 0; i < n; i++) {
        // 4 must be deleted regardless of other numbers 
        if(str[i] == '4') continue;
        
        if(str[i] == '2') 
            cnt_2++;
        else if(str[i] == '1' || str[i] == '3') {
            // this must be after the sequence of 2s
            // either append to end of series of 2s or append to already vis 1s or 3s 
            cnt_13 = max(cnt_13, cnt_2) + 1;
        }
    }

    // max elements we can preserve in the final good subsequence 
    int max_kept = max(cnt_2, cnt_13);
    int max_deletions = n - max_kept;

    cout << max_deletions << endl;
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