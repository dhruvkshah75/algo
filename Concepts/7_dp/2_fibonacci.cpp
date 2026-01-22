#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fx(i, n, a) for(int i=a; i<n; i++)

const int N = 1e5 + 10;
int dp[N];
// TOP DOWN approach  -->> generally uses recursion

int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n]; // memoise  // this step prevents recursion from happening if dp[n] was calculated once 
    return dp[n] = fibonacci(n-1) + fibonacci(n-2);   
    // this lines stores the value in dp and also returns it 
}
// O(n) rather than O(2^n)

void solve(){
    memset(dp, -1, sizeof(dp));  // fills the array with -1  
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;

    // or anathor way is BOTTOM UP approach as u start from the bottom

    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    fx(i, n+1, 2){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}