// ========================================= binary search ========================================================

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

// question link: https://codeforces.com/problemset/problem/1730/B

/**
 * all the people move simultaneously so the person that takes 
 * the max time will be the ans for this problem => so the time each person takes 
 * to dress also matters 
 * 
 * binary search seems obvious => we must apply binary search on minimum time for all
 * people to reach the destination 
 * 
 * suppose t is the total time in which all people reach the destination 
 * so for each person to reach dest the person has t[i] + |xi - x0| <= t 
 * 
 * for each person the reachable space (where can x0 lie) [xi + T - ti, xi - T + ti]
 * so all such intervals' intersection must be valid 
 * i.e. max Left <= min Right
 **/

pair<double,double> canReach(double T, vector<pair<int,int>> &v) {
	int n = v.size();
	double L = -1e18;
	double R = 1e18;

	for(int i = 0; i < n; i++) {
		auto [x, t] = v[i];
		double left = x - T + t;
		double right = x + T - t;

		// get the intersection for all intervals 
		L = max(L, left);
		R = min(R, right);
	}

	// if the intersection is valid interval then return true 
	return {L, R};
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i].first;

	for(int j = 0; j < n; j++) 
		cin >> v[j].second;


	double low = 0, high = 2e8;

	for(int it = 0; it < 100; it++) {
		double mid = (low + high) / 2.0;
		pair<double,double> result = canReach(mid, v);

		if(result.first <= result.second) high = mid;
		else low = mid;
	}

	// after 100 iterations low = high = ans = min Time 
	pair<double,double> ans = canReach(high, v);
	double x0 = (ans.first + ans.second) / 2.0;
	cout << fixed << setprecision(10) << x0 << endl;
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