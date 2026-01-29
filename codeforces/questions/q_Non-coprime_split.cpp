#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int l, r;
        cin >> l >> r;
        if(l!=r){
            if(l%2==0){
                if(l-2 <= 0) cout << 
                cout << 2 << " " << l-2 << endl;
            }  
            else if(l%2!=0){
                int next = l+1;
                cout << 2 << " " << next
            }
        }
        else if(l == r){
            if(l%2 == 0 ) cout << 2 << " " << l-2
        }
    }
}