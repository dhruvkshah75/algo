
#include <bits/stdc++.h>
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
 * the basis vector to represent any number is 1, 11, 111, 1111, ...
 * they are not linearly dependent and can be simplified => 1111 % 11 = 0
 * so we can break this down that every number that can be represented using
 * 1, 11, 111, 1111, ... can be represented as x = 11a + 111b for a, b >= 0
 * 
 * we can simplify this further to x = 11a + 11(10b) + b
 * x = 11(a + 10b) + b
 * b = x % 11
 * y = x - b
 * y / 11 = a + 10b => here a >= 0 for the condition to be valid 
 */

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t--) {
		int x;
		cin >> x;

		int b = x % 11;
		int y = x - b;

		if(y / 11 >= 10 * b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	// O(1) per test case 
} 