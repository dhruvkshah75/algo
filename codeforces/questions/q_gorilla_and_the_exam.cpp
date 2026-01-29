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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int,int> freq;
    vector<int> distinct;
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
        if(freq[a[i]] == 1){
            distinct.push_back(a[i]);
        }
    }
    if(k==0){
        cout << freq.size() << endl;
        return;
    }
    if(k >= freq.size()-1){
        cout << 1 << endl;
        return;
    }
    sort(all(distinct));
    int len = distinct.size();
    int op = 0;
    for(int i=len-1; i>=0; i++){
        if(freq[distinct[i]] <= k){
            int k_l = k - freq[distinct[i]];
            
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// */

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}