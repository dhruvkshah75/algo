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


void solve(){
	int x, y, k; cin >> x >> y >> k;
	for(int i = 0; i < k - k % 2; i++){
		cout << x - (i & 1 ? 1 : -1) * (i / 2 + 1) << " " << y << "\n";
	} 
	if(k%2 == 1){
		cout << x << " " << y << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}