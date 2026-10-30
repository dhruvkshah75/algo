
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

template <typename T>
void printVec(const vector<T>& v) {
    for(const auto &x: v) cout << x << " ";
    cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
    cerr << "{"; print(p.first); cerr << " ";
    print(p.second); cerr << "}";
}

template <typename T>
void print(const vector<T> &v) {
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * apply binary search on minimum time required for all to meet at some common location 
 * assume x is the time so each player can have interval => [pos-time*v, pos+time*v]
 * we just simply need to calculate the interval which is the intersection of these
 * which is [max(L), min(R)] => if valid segment then it will work 
 * */
    
void solve() {
    int n; cin >> n;

    vector<pii> A(n);

    for(int i = 0; i < n; i++) 
        cin >> A[i].first;

    for(int j = 0; j < n; j++)
        cin >> A[j].second;


    auto isPossible = [&](double time) -> bool {
        // return {true, position} when the intersection is a valid interval
        double L = -1.0, R = 1e10;

        for(int i = 0; i < n; i++) {
            double l = A[i].first - time * A[i].second;
            double r = A[i].first + time * A[i].second;

            L = max(L, l);
            R = min(R, r);
        }

        // invalid interval
        if(R < L || R < 0.0) return false;

        // [L,R] is the intersection segment => so all meet at R 
        return true;
    };

    double low = 0.0, high = 1e9;

    for(int iter = 0; iter < 100; iter++) {
        double mid = (low + high) / 2;

        if(isPossible(mid)) high = mid;
        else low = mid;
    }

    // high will be the result
    cout << fixed << setprecision(10) << high << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}