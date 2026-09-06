#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// predicate function would return TTTTTFFFFFF 
bool isPossible(vector<ll>&power, int r, int k, ll x) {
    // can i get the strength as x by putting k towers 
    int placed = 0;
    int last_placed = 0;
    for(int i=0; i<power.size(); i++) {
        if(power[i] < x) {
            ll to_put = x - power[i];
            if(i + r < power.size()) {
                power[i+r] += to_put;
                placed += to_put;
            }
        }
    }
    return (placed <= k);
}
 
long long solve(int n, std::vector<int> &stations, int r, int k) {
    if(n == 1) {
        return stations[0] + k;
    }
    // k is the additional power stations we can put 
    // r is the range 
    vector<ll> prefix(n, 0);
    prefix[0] = stations[0] * 1LL;
    for(int i=1; i <= n; i++) {
        prefix[i] = prefix[i-1] + stations[i] * 1LL;
    }

    // prefix could be used to calculate the no of towers provide power to that city 
    vector<ll> power(n);  // stores the current power situation 
    for(int i=0; i<n; i++) {
        // range of each tower i is i + r and i - r
        // prefix[i+r] - prefix[i-r-1]
        if(i-r-1 > 0 && i + r < n) 
            power[i] = prefix[i+r] - prefix[i-r-1];
        else if(i+r < n) 
            power[i] = prefix[i+r];
        else if(i-r-1 > 0)
            power[i] = prefix[n-1] - prefix[i-r-1];
        else 
            power[i] = prefix[n-1];   
    }

    ll left = *min_element(power.begin(), power.end());
    ll right = n + k;     // maximum that can be achived would be all the stations existing + new k
    ll ans = 0;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        if(isPossible(power, r, k, mid)) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return ans;
}
