#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1775/B


void solve(int n, vector<vector<int>> &nums) {
    // we are supposed to find f(a) = f(b)  
    unordered_map<int,int> freq;
    // store the occurrences of bits in a map
    // Subsequence A => entire set of all numbers ci
    // Subsequence B => all the numbers except 1 number => i.e. the redundant number which can be formed any other way => freq of the bit is greatere than 1 

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < nums[i].size(); j++) 
            freq[nums[i][j]]++;

        
    // Subsequence A => f(A) = OR of all the numbers 
    // Subsequence B => f(B) = OR all nums except one number => redundant number 
    for(int i = 0; i < n; i++) {
        int cnt = 0;

        for(int j = 0; j < nums[i].size(); j++) {
            if(freq[nums[i][j]] > 1) cnt++;
        }   

        // cerr << cnt << endl;

        if(cnt == nums[i].size()) {
            // found the redundant number 
            yes; return;
        }
    }
    
    no;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> nums(n);

        for(int i = 0; i < n; i++) {
            int k; cin >> k;

            for(int j = 0; j < k; j++) {
                int x; cin >> x;
                nums[i].push_back(x);
            }
        }

        solve(n, nums);
    }
}