#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://codeforces.com/contest/2204/problem/C

/*
    unique = multiples of x - multiples of lcm(x, num1) - multiples of lcm(x, num2) + multiples of lcm(x, num1, num2)
    unqiue multiples of x and num1 only = multiples of lcm(x, num1) - multiples of lcm(x, num1, num2)
*/

ll lcm(ll a, ll b) {
    int g = __gcd(a, b);
    return (a * 1LL * b) / g;
}

ll uniqueMultiples(ll x, ll num1, ll num2, ll m) {
    return m / x - m / lcm(x, num1) - m / lcm(x, num2) + m / lcm(x, lcm(num1, num2)); 
}

ll uniqueMultiples(const pair<ll,ll> &num, ll num2, ll m) {
    return m / lcm(num.first, num.second) - m / lcm(lcm(num.first, num.second), num2);
}

ll uniqueMultiples(const tuple<ll,ll,ll> &num, ll m) {
    auto [a, b, c] = num;
    return m / lcm(a, lcm(c, b));
}


void solve(ll a, ll b, ll c, ll m) {
    // calculate the only multiples of a till m 

    vector<ll> result(3, 0);

    // only one of them went to collect water on ith day 
    result[0] += uniqueMultiples(a, b, c, m) * 6;
    result[1] += uniqueMultiples(b, a, c, m) * 6;
    result[2] += uniqueMultiples(c, a, b, m) * 6;

    // two of them went to collect water on ith day 
    result[0] += uniqueMultiples({a, b}, c, m) * 3 + uniqueMultiples({a, c}, b, m) * 3;
    result[1] += uniqueMultiples({b, a}, c, m) * 3 + uniqueMultiples({b, c}, a, m) * 3;
    result[2] += uniqueMultiples({c, a}, b, m) * 3 + uniqueMultiples({c, b}, a, m) * 3;

    // all 3 went to collect water that day 
    for(int i = 0; i < 3; i++) {
        result[i] += uniqueMultiples({a, b, c}, m) * 2;
    }

    // print the result
    for(int i = 0; i < 3; i++) 
        cout << result[i] << " ";
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        solve(a, b, c, m);
    }
}
