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
    int n;
    cin >> n;
    map<int, int> constraint;
    vector<int> type3;
    bool flag = false;
    for(int i=0; i<n; i++){
        int a, x;
        cin >> a >> x;
        if(a == 2 && !flag){
            flag = true;
            constraint[a] = x;
        }
        if(a == 1 && constraint[a] < x) constraint[a] = x;
        else if(a == 2 && constraint[a] > x && flag) constraint[a] = x;
        else if(a == 3) type3.push_back(x);
    }
    int len = type3.size();
    int ctr = 0;
    for(int i=0; i<len; i++){
        if(type3[i] <= constraint[2] && type3[i] >= constraint[1]) ctr++;
    }
    int ans_check = constraint[2]-constraint[1];
    if(ans_check < 0){
        cout << 0 << endl;
        return;
    }
    cout << ans_check - ctr + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}