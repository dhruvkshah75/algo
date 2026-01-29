#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            a.push_back(x);
        }

        vector<int> a_c =a;
        for(int i=1; i<n-1; i++){
            int b = a_c[i-1];
            int f = a_c[i+1];
            int m = a_c[i];
            if(a_c[i-1] > a_c[i+1]){
                a_c[i-1]--;
                a_c[i+1]++;
            }
            else if(a_c[i-1] <= a_c[i+1]){
                a_c[i-1]++;
                a_c[i+1]--;
            }
        }
        int count = 1;
        for(int i=1; i<n; i++){
            if(a_c[i] == a_c[0]) count++;
        }
        if(count == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}