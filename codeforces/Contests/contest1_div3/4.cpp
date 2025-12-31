#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n+1);
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            arr[i] = {x, i};
        }
        
    }
}