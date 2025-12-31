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
    int min = *min_element(a.begin(), a.end());
    // auto it = min_element(a.begin(), a.end());

    /*
        vector is   2 3 1 6 7 6
    */
   int max = *max_element(a.begin()+3, a.end()); // for the above ex a.begin()+3 is the address of 6 
   
   int sum = accumulate(a.begin(), a.end(), 0); // takes 3 parametrs the 3rd parameter the initial sum

   int ct = count(a.begin(), a.end(), 3); // count() gives the count of 3 in the vector 
   int element = *find(a.begin(), a.end(), 2);
   /*
    auto it = find(a.begin(), a.end(), 3);
    if(it == a.end()) cout << "element not present" << endl;
   */

   // to reverse string array or vector
   reverse(a.begin(), a.end());
   string str = "abrefhthdsg";
   reverse(str.begin(), str.end());


   // all are O(n) operations
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}