// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Given array of n integers. All integers are present in even count except one 
    Find that one integer which has odd count in O(N) time complexity and O(1) space 
    constraints: 
    N < 1e5 and a[i] < 1e5;
*/

void solve(){
    // take xor of all no all no with even count will cancel out and the one with the odd count will be left 
    int n;
    cin >> n;
    int x;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        ans = ans ^ x;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}