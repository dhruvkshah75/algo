
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// returns TTTTTTFFFFF ==> find the last occurrence of T for this predicate function 
bool maxSouvenirs(vector<int> &arr, int S, int x, ll &total) {
    vector<ll> ans(arr.size());
    for(int i=0; i<arr.size(); i++) {
        ans[i] = arr[i] * 1LL + (i + 1) * 1LL * x;
    }  

    sort(ans.begin(), ans.end());

    total = 0;
    for(int i=0; i<x; i++) {
        if(total > S) {
            total = 0;
            return false;
        }
        total += ans[i];
        if(total > S) {
            total = 0;
            return false;
        }
    }
    return true;
}

void solve(){
    int n, S;
    cin >> n >> S;
    vector<int> arr(n);

    for(int i=0; i<n; i++) 
        cin >> arr[i];

    int l = 0, r = n;
    int ans = 0;
    long long total = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(maxSouvenirs(arr, S, mid, total)) {
            ans = mid; 
            l = mid + 1;
        }
        else r = mid - 1;
    }

    bool s = maxSouvenirs(arr, S, ans, total);

    cout << ans << " " << total << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}