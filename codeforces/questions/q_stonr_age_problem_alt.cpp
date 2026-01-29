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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    ll sum = 0;
    f1(i, n){
        cin >> a[i];
        sum += a[i];
    }
    stack<int> s;  // stack is for storing the changes made when t=2;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int i, x;
            cin >> i >> x;
            if(!s.empty()){
                ll prev_value = s.top();
                s.pop();
                a[i] = x;
                sum = sum - prev_value + x;
                cout << sum << endl;
                continue;
            }
            else{
                sum = sum - a[i] + x;
                a[i] = x;
                cout << sum << endl;
                continue;
            }
        }
        if(t==2){
            int x;
            cin >> x;
            sum = 1LL*x*n;
            s.push(x);
            cout << sum << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}