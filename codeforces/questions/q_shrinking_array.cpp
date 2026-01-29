// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

// Custom upper_bound: returns index of first element > x
int upper_bound(vector<int> &v, int x) {
    int l=0, r=v.size()-1, mid;
    while (r-l>1) {
        mid = (l+r)/2;
        if (v[mid] <= x) l = mid+1;
        else r = mid;
    }
    if (v[l] > x) return l;
    if (v[r] > x) return r;
    return -1;
}

// Custom lower_bound: returns index of first element >= x
int lower_bound(vector<int> &v, int x) {
    int l=0, r=v.size()-1, mid;
    while (r-l>1) {
        mid = (l+r)/2;
        if (v[mid]<x) l = mid+1;
        else r = mid;
    }
    if (v[l] >= x) return l;
    if (v[r] >= x) return r;
    return -1;
}

void solve() {
    int n;
	cin >> n;
	vector<int> a(n);
    fc(i, n, a);
	
	for (int i = 1; i < n; i++){
		if (abs(a[i-1] - a[i]) <= 1){
			cout << 0 << endl;
			return;
		}
	}
	for (int i = 1; i + 1 < n; i++){
		if((a[i-1] < a[i] && a[i] > a[i + 1]) || (a[i-1] > a[i] && a[i] < a[i+1])){
			cout << 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}