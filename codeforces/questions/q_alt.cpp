#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    vector<int> phone_num;
    unordered_map<int, int> freq;
    string str;
    cin >> str;
    for(int i=0; i<10; i++){
        int x = (int)(str[i] - '0');
        freq[x]++;
        phone_num.push_back(x);
    }
    vector<int> ans;
    int index = -1;
    for(int i=9; i>=0; i++){
        if(freq[i] == 0){
            index = i;
            break;
        }
    }
    for(int i=9; i>index; i--){
        if(freq[i] > 0){
            ans.push_back(i);
            freq[i]--; 
        }
    }
    // i have to start filling at the index = ans.size();
    while(ans.size() < 10){
        int index = ans.size();
        for(int j=index; j>=0; j--){
            if(freq[10-j] >= 1){
                ans.push_back(10-j);
                freq[10-j]--;
                break;
            }
        }
    }

    for(auto &x: ans) cout << x;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}