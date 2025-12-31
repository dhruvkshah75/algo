
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        int rem = sum%3;
        if(rem==0){
            cout << 0 << endl;
            continue;
        }
        
        bool can_remove = false;
        for(int i=0; i<n; i++){
            if(a[i]%3 == rem){
                can_remove = true;
                break;
            }
        }
        if(can_remove || rem == 2){
            cout << 1 << endl;
            continue;
        }

        if(rem == 1){
            cout << 2 << endl;
            continue;
        }
    }
}
