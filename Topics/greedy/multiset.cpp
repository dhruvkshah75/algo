
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

/*
 * use pbds data structure to handle this requirements of the question
 * since it is a multiset duplicates are possible so we must use pair in the pbds 
 * and keep a map with the indices of each element so that we can delete one of the 
 * occurrences of the element
 */

void solve() {
    int n, q;
    cin >> n >> q;

    int cnt = 0;
    ordered_set<pair<int,int>> s;
    map<int,vector<int>> mp;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert({x, i});
        mp[x].push_back(i);
        cnt++;
    }

    // now answer the queries in O(LogN)
    while(q--) {
        int k;
        cin >> k;

        if(k < 0) {
            k = abs(k);
            int val = *s.find_by_order(k);
            
            // get the index and remove the entry from the map
            int ind = mp[val].back();
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);

            s.erase({val, ind});
        }
        else {
            // insert k into the multiset
            s.insert({k, cnt});
            mp[k].push_back(cnt);
            cnt++;
        }
    }

    if(s.begin() == s.end()) cout << 0 << endl;
    else cout << *s.begin() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}