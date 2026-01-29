#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> c(n);
        for(int i=0; i<n; i++){
            cin >> c[i].first;
        }
        for(int i=0; i<n; i++){
            cin >> c[i].second;
        }

        //(x-xi)^2 +y^2 <= ri^2;

        for(int i=0; i<n; i++){
            int center = c[i].first;
            int radius = c[i].second;
            
        }

    }
}