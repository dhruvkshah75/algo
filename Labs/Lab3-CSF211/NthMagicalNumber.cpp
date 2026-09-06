#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/nth-magical-number/description/
// HARD Leetcode Question 

/*
    Time Complexity: O(Log(N)) where N = 1e18
    Algorithm: 
        since n <= 1e9 and a,b <= 4e4 ==>> the max multiple <= 1e18
        We simply apply a binary search on the ans that is the nth magical number between 1 and 1e18
        Now using inclusion and exclusion principle we find how many multiples are there till x 
        : multiples of a + b - lcm(a,b) till x 
        We return True if there are at most n multiples of `a` or `b` till x

*/

class Solution {
public:
    // FFFFFTTTTT => find the first occurrence of T 
    bool predicate(int n, int a, int b, long long x) {
        // check if the multiples till x are at most n then we return T
        int lcm = (a * 1LL * b) / gcd(a, b);
        long long multiples = x/a + x/b - x/lcm;
        return multiples >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        // binary search on answer 
        // apply binary search and then and check if there are at most n numbers 
        long long l = 1, r = 1e18;
        long long ans = 0;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(predicate(n, a, b, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        int mod = 1e9 + 7;
        return ans % mod;
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    Solution s = Solution();
    cout << s.nthMagicalNumber(n, a, b) << endl;
}