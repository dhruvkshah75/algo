#include <bits/stdc++.h>
using namespace std;


// question link: https://codeforces.com/contest/670/problem/D2  or https://codeforces.com/contest/670/problem/D1

/*
    Algorithm:
        We use binary search on the no of cookies that can be made 
        and the predicate function canMakeCookies returns TTTTTFFFFF => we find the last occurrence of T 
        So we have to check if we can make x cookies using the magic powder and the ingrediants 
        Which is pretty much straight forward 
        the ith ingrediant needed to make x cookies will be x * a[i] if it less than b[i] then we use magic powder 
        if b[i] > a[i] * 1LL * x then we have enough ingrediant to make the cookie, then go to the next value 
        if the magicPowder falls below 0 then return false  
*/

// returns TTTTTTFFFFFF => find the last occurence of T
// this function returns T if i can make at least x cookies
bool canMakeCookies(vector<int> &a, vector<int> &b ,int x, int k) {
    // a is the needed ingrediant, b is the no of ingrediants i have 
    // can i make x cookies ??
    long long magicPowder = k;   // overflow can occur while subtracting in the if (so we use long long )
    for(int i=0; i<a.size(); i++) {
        if(b[i] < a[i] * 1LL * x) {    // a[i] * x is the required ingrediants needed to make x cookies 
            magicPowder -= (a[i] * 1LL * x - b[i]); 
        }
        if(magicPowder < 0) return false;
    }
    if(magicPowder < 0) return false;
    else return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++)  // a is what is needed 
        cin >> a[i];
    
    for(int i=0; i<n; i++)  // b is what ingrediants i have 
        cin >> b[i];


    // we apply binary search on how many cookies can be made these ingredients given 
    int l = 0, r = 2e9; 
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canMakeCookies(a, b, mid, k)) { ans = mid, l = mid + 1; }
        else r = mid - 1;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}