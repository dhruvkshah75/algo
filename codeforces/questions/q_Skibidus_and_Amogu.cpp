#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

void solve(){
    string str;
    cin >> str;
    vector<char> ans(str.size()-1);
    for(int i=0; i<str.size()-1; i++){
        if(i == str.size()-2){
            ans[i] = 'i';
            break;
        }
        ans[i] = str[i];
    }
    for(auto &x: ans) cout << x;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}