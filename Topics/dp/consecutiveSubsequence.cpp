// =================================================================== dp on subsequences ================================================================

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

// question link: https://codeforces.com/problemset/problem/977/F

/* The relaive ordering of elements is important for numbers in this question */


void solve(int n, vector<int> &arr) {

    unordered_map<int,int> dp;
    // dp[val] = length of consecutive subsequences ending in value val  

    int longest = 0;
    int endVal = -1;

    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        // if prev element exists then add this number to end of the sequence
        if(dp.count(curr - 1)) dp[curr] = 1 + dp[curr - 1];
        else dp[curr] = 1;

        if(dp[curr] > longest) {
            longest = dp[curr];
            endVal = curr;
        }
    }
    
    cout << longest << endl;

    int startVal = endVal - longest + 1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == startVal) {
            cout << i + 1 << " ";
            startVal++;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    solve(n, arr);
}