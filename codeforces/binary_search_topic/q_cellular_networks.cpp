/*
    V.imp question on binary search and two pointers 
    Question: https://codeforces.com/contest/702/problem/C
*/

// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

const int N = 1e5+10;
vector<int> a(N), b(N);

bool isPossible(int n, int m, int mid){
    int i = 0, j = 0;
    while(i < n){
        while(j < m && abs(a[i]-b[j]) > mid){
            j++;
            if(j == m) return false;
        }
        i++;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    fx(i, n, 0){
        cin >> a[i];
    }
    fx(i, m, 0){
        cin >> b[i];
    }
    int l = -1, r = 2e9, mid;
    // FFFFFTTTT find the first occurence of T
    while(r-l>1){
        mid = (l+r)/2;
        if(isPossible(n, m, mid)) r = mid;
        else l = mid;
    }
    if(isPossible(n, m, l)) cout << l << endl;
    else cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
}