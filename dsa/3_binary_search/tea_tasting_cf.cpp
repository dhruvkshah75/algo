#include<bits/stdc++.h>
using namespace std;

// question link: 

class Solution {
public:
    void teaTasting() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for(int i=0; i<n; i++) 
            cin >> a[i];

        for(int i=0; i<n; i++)
            cin >> b[i];

        // this is the prefix array of the tasters, 
        // and then we find till which taster will the a[i] be depleted 
        vector<long long> prefix(n+1, 0);
        for(int i=1; i<=n; i++)
            prefix[i] = prefix[i-1] + b[i] * 1LL;


        vector<long long> ans(n);
        // traversing through each tea cup 
        for(int i=0; i<n; i++) {
            // we find the upper_bound of (a[i] + prefix[i-1])  
            auto it = upper_bound(prefix.begin(), prefix.end(), a[i] + prefix[i-1]);
            int k = distance(prefix.begin(), it) - 1;

            // all the tasters till index k drink to their capacity 
            if(k >= i) {

            }

        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s = Solution();

    int t;
    cin >> t;
    while(t--) {
        s.teaTasting();
    }
}