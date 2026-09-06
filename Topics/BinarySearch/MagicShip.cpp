// ============================ binary search + math ============================================

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
#define setbitsll(x) __builtin_popcountll(x)

// question link: https://codeforces.com/problemset/problem/1117/C 

int startX, startY, endX, endY;
unordered_map<char,int> mp;
pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// 0 = R, 1 = U, 2 = L, 3 = D

bool canReach(ll x, string &str) {
	int n = str.length();
	
	ll times = x / n;
	int extra = x % n;

	ll curr_x = startX, curr_y = startY;

	for(int i = 0; i < n; i++) {
		ll mul = times + ((i < extra) ? 1 : 0);
		
		int wind = mp[str[i]];
		auto [dx, dy] = dir[wind];

		curr_x += 1LL * mul * dx;
		curr_y += 1LL * mul * dy;
	}

	ll rem = abs(endX - curr_x) + abs(endY - curr_y);
	return (rem <= x);
}

void solve() {
	cin >> startX >> startY;
	cin >> endX >> endY;

	int n;
	cin >> n;
	string str;
	cin >> str;

	if(startX == endX && startY == endY) {
		cout << 0 << endl;
		return;
	}

	mp['U'] = 1;
	mp['D'] = 3;
	mp['R'] = 0;
	mp['L'] = 2;

	ll low = 1, high = 1e18;
	ll ans = -1;

	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if(canReach(mid, str)) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}