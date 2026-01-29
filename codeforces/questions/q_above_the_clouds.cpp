#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    unordered_map<char, int> freq;
    for(int i=0; i<n; i++){
        freq[str[i]]++;
    }

    int count = 0;
    for(auto &f: freq){
        if(f.second > 2){
            cout << "YES" << endl;
            return;
        }
        else if(f.second == 2){
            count++;
            if(count==1){
                if(str[0] == f.first && str[n-1] == f.first){
                }
                else{
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        if(count > 1){
            cout << "YES" << endl;
            return;
        } 
    }
    cout << "NO" << endl;
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