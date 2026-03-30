#include<bits/stdc++.h>
using namespace std;

// question link: 

// THEREOM to calculate inverse with respect to some mod is inverse(a) ≡ a^(p−2) % p

typedef long long ll;

class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        int mod = 1e9+7;

        // =====================================
        // calculate nCr 
        vector<ll> fact(n + 1), inv_fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i-1] * i) % mod;
    
        // inv(x) = x^(mod-2) % mod
        // fast power calculation => O(log(exp))
        auto power = [&](ll base, ll exp, ll mod) {
            ll result = 1;
            base %= mod;
            while (exp > 0) {
                if (exp & 1) result = result * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return result;
        };

        inv_fact[n] = power(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; i--)
            inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;

        // C(n, r) in O(1)
        // C(n, r) = fact(n) / fact(n-r)*fact(r) istead of doing that calculate inverse fact
        auto C = [&](int n, int r) -> ll {
            if (r < 0 || r > n) return 0;
            return fact[n] % mod * inv_fact[r] % mod * inv_fact[n-r] % mod;
        };

        // ===============================================================
        
        
        // we have n people => 0 to n-1
        int result = 0;
        // for k people to be seen we can assign x+y == k on both sides 
        int left = pos, right = n - pos - 1;
        
        for(int x = 0; x <= k; x++) {
            int y = k - x;
            // x people on left must have chosen L and y people on the right must have chosen R
            if(x > left || y > right) continue;
            // ans will be C(left, x) 
            result = (result + C(left, x) * C(right, y)) % mod;
        }

        return result * 2 % mod;
    }
};