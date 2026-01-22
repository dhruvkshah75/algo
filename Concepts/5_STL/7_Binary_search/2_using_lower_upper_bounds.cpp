// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}



// how to do lower bounds and upper bounds using binary search

int upper_bound(vector<int> &v, int element){
    int l = 0, r = v.size()-1;
    int mid;
    while(r-l>1){
        mid = (r+l)/2;
        if(v[mid] <= element){   // since v[mid] is less than or equal to element element it from the search space
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    if(v[l] > element) return l;
    if(v[r] > element) return r;
    return -1;
}

  // lower element is that element or a element that is just bigger
int lower_bound(vector<int> &v, int x){     
    int l = 0, r = v.size()-1;
    int mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(v[mid] < x) l = mid+1;
        else r = mid; 
    }
    if(v[l] >= x) return l;
    if(v[r] >= x) return r;
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    f(i, n) cin >> v[i];
    sort(all(v));
    int element;
    cin >> element;
    int index = lower_bound(v, element);
    cout << index << " " << (index!=-1)?v[index]:-1 << endl;

    int u_index = upper_bound(v, element);
    cout << u_index << " " << (u_index!=-1)?v[u_index]:-1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
}