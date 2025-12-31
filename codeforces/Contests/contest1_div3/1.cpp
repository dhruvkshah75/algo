#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        vector<int> d(n+1);
        vector<int> hsh(2);
        for(int i=1; i<=n; i++){
            cin >> d[i];
            hsh[d[i]]++;
        }
        if(hsh[0] == n){
            cout << "YES" << endl;
            continue;
        }
        int index = 0;
        for(int i=1; i<=n; i++){
            if(d[i] == 1){
                index = i;
                break;
            } 
        }
        int l_index = 0;
        for(int i=n; i>0; i--){
            if(d[i] == 1){
                l_index = i;
                break;
            }
        }

        int left = l_index - index + 1;
        if(left <= x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}