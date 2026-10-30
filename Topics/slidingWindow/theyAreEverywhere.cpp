
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

/*
 * sliding window of minimum size => get the window which has the smallest size 
 * in which all the distinct pokemans (of all types) 
 * simple two pointers will work out in this question where we want the minimum size window 
 */

void solve() {
	int n; cin >> n;

	string str; cin >> str;

	unordered_set<char> s(str.begin(), str.end());
	int distinct = s.size();

	unordered_map<char,int> mp;
	// used for tracking the freq of chars in the window 

	int l = 0, res = n;

	for(int r = 0; r < n; r++) {
		char c = str[r];
		mp[c]++;

		// shrink the window until it is valid 
		while(mp.size() == distinct) {
			char to_rem = str[l];
			// if removing r makes it 0 then window becomes invalid
			if(mp[to_rem] == 1) break;

			mp[to_rem]--;
			l++;
		}

		if(mp.size() == distinct) {
			res = min(res, r-l+1);
		}
	}

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}