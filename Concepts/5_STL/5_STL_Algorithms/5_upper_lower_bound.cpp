#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    /* 
        to use lower bound and upper bound the vector and the array need to be sorted then lb and ub works as O(logn)
        arr is 4 5 5 7 8 25
        then lower bound of 5 is 5  // lower bound finds the element asked if it is present or the next bigger element
        so lower_bound(7) is 7 and lower_bound(6) is 7
        if lowerbound is not present then it gives the iterator of the end 
        upper bound gives the next bigger element
        in case of arrays ->> pointers and in case of vectors it gives iterator;
    */

    auto it = lower_bound(a.begin(), a.end(), 5);  // lower_bound(.begin(), .end(), the element)
    auto it2 = upper_bound(a.begin(), a.end(), 5);
    if(it == a.end()){
        cout << "not found" << endl;
    }
    else cout << *it << endl;
    cout << *it2 << endl;   // -->> this will give the ans as 7 so upper bound of 5 is 7
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}