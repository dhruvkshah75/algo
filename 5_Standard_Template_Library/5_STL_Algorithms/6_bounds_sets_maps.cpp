#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
        lower bound and upper bound in maps and sets
        eg is 4 5 5 25 7 8
    */
   int n;
   cin >> n;
   set<int> s;
   for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
   }
   // already sorted 
   // auto it = lower_bound(s.begin(), s,end(), 5) --> in case of sets and maps this is O(n);
   auto it = s.lower_bound(5); // this is a O(logn)

   map<int,int> m;
   // in case of maps it compares on the basis of its keys 
   auto it1 = m.upper_bound(6);
   // if the upper bound is not present then it it1 = m.end(); 
   // if mutiple same no is present then it returns of iterator of the first element

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}