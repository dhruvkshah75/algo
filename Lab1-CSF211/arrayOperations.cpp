// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
class Solution {
public:
    void arrayOperations(){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        // we remove the last 2k elements 
        int score = 0;
        for(int i=0; i<n-2*k; i++) {
            score += arr[i];
        }

        // we apply the operation only k times so from n-2k to n-k and remove 2k elements 
        for(int i=n-2*k; i<n-k; i++){
            score += arr[i]/arr[i+k];
            // pair the ith with (i+k)th
        }

        cout << score << endl;
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Solution s = Solution();
    int tt;
    cin >> tt;
    while (tt--)
        s.arrayOperations();
}