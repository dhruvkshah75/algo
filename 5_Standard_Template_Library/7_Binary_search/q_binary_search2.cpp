
/*
    SPOJ question on AGG COW --->> advanced binary search whith predicate functions
*/

/*

Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. 
The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).
His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input:
    t – the number of test cases, then t test cases follows.
    Line 1: Two space-separated integers: N and C
    Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output:
    For each test case output one integer: the largest minimum distance.
*/

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

    // think about a monotonic predicate function
    // so the predicate function would be something like 
    // minimum dist = 0 -->> T min_distance = 1 ->> T so on to form TTTTTTFFFFF

int n, c;     // defined globally as it is also used in the predicate function

bool canPlaceCows(vector<int> &pos, int minDis){              // the predicate function which will give so find the last occurrence of T
    int lastPos = -1;
    int cows_ct = c;
    for(int i=0; i<n; i++){
        if(pos[i]-lastPos >= minDis || lastPos == -1){
            cows_ct--;
            lastPos = pos[i];
        }
        if(cows_ct == 0) break;  // i.e. all the cows are placed suc that the distnace between two cows is greater than minDis
    }
    if(cows_ct == 0) return true;
    else return false;
}

void solve(){
    cin >> n >> c;
    vector<int> pos(n);
    fc(i, n, pos);
    sort(all(pos));
    int l=0, r=1e9, mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(canPlaceCows(pos, mid)) l=mid;
        else r = mid-1;
    }
    if(canPlaceCows(pos, r)){
        cout << r << endl;   // here r is the minimum distance 
    }
    else{
        cout << l << endl;  // here l is the min distance 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}