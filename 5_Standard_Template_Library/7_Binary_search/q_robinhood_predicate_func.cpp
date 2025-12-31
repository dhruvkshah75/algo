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


bool isReq(vector<int> &a, ll mid, ll sum){  // predicate function -->> FFFFFTTTT
    double n_avg = (double)(sum+mid)/a.size();
    double threshold = n_avg/2;
    int m_i = a.size()/2;
    if((double)a[m_i] < threshold) return true;
    else return false;
}

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i]*1LL;
    }
    sort(all(a));
    double avg = (double)sum/n;
    if(n==1 || n==2){
        cout << -1 << endl;
        return;
    }
    // FFFFFFFFFTTTTTTT  -->> result of the monotonic predicate function
    ll l=0, r=1e12, mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(isReq(a, mid, sum)) r=mid;
        else l = mid+1;
    }
    if(isReq(a, l, sum)) cout << l << endl;
    else cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 */

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}