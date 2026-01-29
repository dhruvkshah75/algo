#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<string>> words(3, vector<string>(n));
    map<string, int> freq;       // to track how many people used each word     
    // ---->> instead of a hsh array use a map with that key as the string.

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> words[i][j]; 
            freq[words[i][j]]++;
        }
    }
    vector<int> points(3, 0);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            string word = words[i][j];
            if (freq[word] == 1) points[i] += 3;
            else if (freq[word] == 2) points[i] += 1;
            else if (freq[word] == 3) points[i] += 0;
        }
    }

    for (auto &p: points) {
        cout << p << " ";
    }
    cout << endl;
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