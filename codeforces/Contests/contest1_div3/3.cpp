#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> hsh(N);

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        hsh.clear();
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            hsh[a[i]]++;
        }
        int max_element = hsh[a[0]];
        for(int i=1; i<n; i++){
            if(max_element < hsh[a[i]]) max_element = hsh[a[i]];
        }
        cout << max_element << endl;
    }
}