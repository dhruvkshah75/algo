#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt; 
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<pair<long long,long long>> arr;
        arr.push_back({0, 0});
        for(int i=1; i<=n; i++){
            int a, b;
            cin >> a >> b;
            arr.push_back({a, b});
        }

        int greetings = 0;
        for(int i=1; i<=n; i++){
            if(arr[i].first <= arr[i].second) arr[i].first++;
            
        }
    }
}