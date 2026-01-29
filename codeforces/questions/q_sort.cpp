#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p1(n+1, vector<int>(26, 0)); // rows indiacte the position of the element and column indicates if it is present or not where index denotes its character;
    vector<vector<int>> p2(n+1, vector<int>(26, 0));

    for(int i=1; i<=n; i++){
        char c;
        cin >> c;
        p1[i][c-'a']++;
        for(int j=0; j<26; j++){
            p1[i][j] += p1[i-1][j];         // this stores the freq of each character at their loc 
        }
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        p2[i][c-'a']++;
        for(int j = 0; j<26; j++){
            p2[i][j] += p2[i-1][j];
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i=0; i<26; i++){
            int v1 = p1[r][i] - p1[l-1][i];
            int v2 = p2[r][i] - p2[l-1][i];
            ans+=abs(v1-v2);
        }
        cout << ans/2 << endl;
    }

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