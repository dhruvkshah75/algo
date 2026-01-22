#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool should_i_swap(pair<int,int> a, pair<int,int> b){          // a compartor function 
    if(a.first != b.first){
        if(a.first > b.first) return true;
        return false;
    }
    else{
        if(a.second < b.second) return true;
        return false;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i=0; i<n; i++){                       // a basic O(n^2) sorting algorithm
        for(int j=i+1; j<n; j++){
            if(should_i_swap(a[i], a[j])) swap(a[i], a[j]);
        }
    }

    for(auto &i: a){
        cout << i.first << " " << i.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}