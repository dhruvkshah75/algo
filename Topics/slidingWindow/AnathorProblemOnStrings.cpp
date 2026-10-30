// ========================= counting using slinding window  ==================================

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

/*
 * we use sliding window concept to calculate the number of substrings with exactly k 1s in it 
 * this can be broken into (cnt <= k) - (cnt <= k-1) =>> this is equal to substrings with k 1s 
 * how to count number of substrings ending with 1s in it <= k
 * get the largest valid sliding window ending at some index r => [l....r]
 * all subarrays ending in r will have <= k 1s in it 
 * [l...r], [l+1...r], [l+2,...r] ..... [r, r] => r-l+1
 */

void solve() {
    int k; cin >> k;

    string str; cin >> str;
    int n = str.size();

    // add a simple check if cnt1 < k then ans = 0
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') cnt1++;
    }

    if(cnt1 < k) {
        cout << 0 << endl;
        return;
    }

    auto cnt = [&](int k) -> int64_t {
        // the number k cant be negative
        if(k < 0) return 0;

        int64_t res = 0;
        int count = 0, l = 0;

        for(int r = 0; r < n; r++) {
            if(str[r] == '1') count++;

            // shrink if the window becomes invalid 
            while(count > k) {
                if(str[l] == '1') count--;
                l++;
            }

            // now the window is valid with count <= k
            res += r-l+1;
        }

        return res;
    };

    int64_t result = cnt(k) - cnt(k-1);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}