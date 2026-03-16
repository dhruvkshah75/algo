#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1527/C

void solve(vector<int> &nums) {
    // we must find the weight of all the subsequences 
    int n = nums.size();

    // we must count how many times (i, j) will be in the subsegment 
    // => left will be 0, 1, 2, .. i => (i + 1) choices and right will j, j + 1, .. n => (n - j) choices 
    // for the (i, j) pair => the number of subarrays it will be a part of (i + 1) * (n - j)

    unordered_map<int,long long> mp;

    long long result = 0;

    for(int j=0; j<n; j++) {
        result += mp[nums[j]] * 1LL * (n - j);
        mp[nums[j]] += (j+1);
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(n);

        for(int i=0; i<n; i++) 
            cin >> nums[i];
        
        solve(nums);
    }
}