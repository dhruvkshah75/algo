// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
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



bool check(){

}

void generate(vector<int> &subset, int i, vector<int> &nums){
    
    
}


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++){
        cin >> nums[i];
    }
    sort(all(nums));
    vector<int> empty;
    generate(empty, 2, nums);

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