#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    map<int,int> freq;
    f(i, n){
        cin >> c[i];
        freq[c[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto &x: freq){
        pq.push({x.second, x.first});
    }
    int total = n;
    while(!pq.empty()){
        auto [cnt, val] = pq.top();
        if(cnt < k) break;
        pq.pop();
        int check_cnt = cnt - k;
        if(check_cnt != 0 || pq.empty()){
            pq.push({cnt-1, val});
            total -= 1;
        }
        else if(check_cnt == 0 && !pq.empty()){
            auto [cnt2, val2] = pq.top();
            pq.pop();
            pq.push({cnt2+k-1, val2});
            total -= 1;
        }
    }
    cout << total << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    
}