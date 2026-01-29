#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

/*
    if we swap i, n-i+1 its position would be influenced by i-1 for ith element and n-i+2 for n-i+1 th element
*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=n/2-1;i>=1;i--){
        if(a[i] == a[i+1] || a[n-i+1] == a[n-i]){
            swap(a[i],a[n-i+1]);
        }
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(a[i] == a[i+1]) count++;
    }
    cout << count << endl;
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