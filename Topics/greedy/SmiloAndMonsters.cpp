// ===================================================== greedy ===================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)

// question link: https://codeforces.com/problemset/problem/1891/C

/**
 * Here we must use min number of operations to kill all the monsters 
 * simple 2 pointers with sorting will suffice 
 * killing monsters using attack 2 is best on larger hordes 
 * use pointer i for attacks on smaller horders and pointer j for attack 2 on larger horders 
 * 
 * last case when i = j => assume we use k single attacks => (rem-k) - (combo + k) = 0
 * this one will be the best way to get the result to min 
 * k = (rem - combo + 1) / 2 
 * total attacks to be made will be k + 1 (k single attacks and then 1 combo attack with x = curr_combo + k)
 * */

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	// sort the array for applying two pointers 

	int l = 0, r = n-1;
	ll attacks = 0, combo = 0;

	while(l < r) {
		// kill the smaller horde with combo attack < arr[r]
		if(arr[l] + combo < arr[r]) {
			attacks += arr[l];
			combo += arr[l];
			l++; 
		}
		else {
			// killing some monsters from lth horde we can use combo on arr[r]
			int extra = arr[r] - combo;
			arr[l] -= extra;
			attacks += extra;

			// kill the rth horde using one attack of type 2 and reset combo
			attacks += 1;
			r--;
			combo = 0;
		}
	}

	// now deal with the case of l == r
	if(l == r) {
		if(arr[l] == 1) attacks += 1;
		else {
			// we must use combo attack in effecient way
			ll rem = arr[l];
			attacks += min(rem, (rem-combo+1)/2 + 1);
		}
	}

	cout << attacks << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}