#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> a, pair<int,int> b){          // a compartor function 
    if(a.first != b.first){
        if(a.first > b.first) return false;
        return true;
    }
    else{
        if(a.second < b.second) return false;
        return true;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    // the inbuilt cpp sorting algorithm can take three parameters the 3rd parameter is the comparator function
    // *********************************************** V.IMP *********************************************
    sort(a.begin(), a.end(), cmp);  
    // the inbuilt function says if u want to swap then return false and if u dont want to swap then return true;
    //
    for(auto &i: a){
        cout << i.first << " " << i.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}