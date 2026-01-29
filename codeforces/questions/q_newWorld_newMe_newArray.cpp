#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, k, p;
        cin >> n >> k >> p;
        //vector<int> a(n);
        int min_op;
        min_op = ceil((double)fabs(k)/p);
        if(min_op <=n) cout << min_op << endl;
        else cout << -1 << endl;
        
    }
}