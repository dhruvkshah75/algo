#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int size = n;
        vector<int> arr(n+10, 0);
        vector<int> pf(n+10, 0);

        for(int i=1; i<=n; i++){
            cin >> arr[i];
            pf[i] = pf[i-1] + arr[i];
        }
        vector<int> l(n), r(n);
        for(int i=0; i<n; i++){
            cin >> l[i] >> r[i];
        }

    }
}