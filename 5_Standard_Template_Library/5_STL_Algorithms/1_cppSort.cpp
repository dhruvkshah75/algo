#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    inbuilt sort uses introsort which is considered to be the best sorting algorithm 
    is a mix of quick sort, heap sort, insertion sort
*/

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);  // parameters are adresses from where it will start sorting to the adress of the next element it wants 
    // similar to vector<int> a(n);  sort(a.begin(), e.end());

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin()+2, arr.end());     // time complexity of the sort() is O(nlog(n));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}