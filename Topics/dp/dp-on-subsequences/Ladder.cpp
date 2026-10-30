// ============================ dp + two pointers ============================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
    cerr << "[ ";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << " ]" << endl;
}

/**
 * dp1[i] = length of longest increasing sequence ending at index i
 * dp2[i] = length of longest dsc sequence starting at index i
 * this is the precomputation needed to answer the queries in O(1)
 * 
 * now to answer the queries O(1) we need to do some precomputation
 * we calculate end[i] => this stores the index of the last element for 
 * the increasing sequence so that we can make this jmp in O(1)
 **/

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n+2);
    A[0] = A[n+1] = 0;

    for(int i = 1; i <= n; i++) cin >> A[i];

    vector<int> dp1(n+2, 0), dp2(n+2, 0);
    
    for(int i = 1; i <= n; i++) {
        if(A[i] >= A[i-1]) dp1[i] = dp1[i-1] + 1;
        else dp1[i] = 1;
    }

    for(int i = n; i >= 1; i--) {
        if(A[i] >= A[i+1]) dp2[i] = dp2[i+1] + 1;
        else dp2[i] = 1;
    }

    // create the end array from the dp1 array
    vector<int> end(n+1);
    end[n] = n;

    for(int i = n-1; i >= 1; i--) {
        if(A[i] <= A[i+1]) end[i] = end[i+1];
        else end[i] = i;  
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        int end_idx = end[l];
        int right_len = r - end_idx + 1;

        if(dp2[end_idx] >= right_len) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}