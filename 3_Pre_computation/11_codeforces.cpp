#include<bits/stdc++.h>
using namespace std;

const int N = 2*1e5 + 10;
int arr[N];
int hsh[N]; //stores the count of all the element where the index is the element value and what it stores is the index

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i=0; i<n+10; i++){
            hsh[i] = arr[i] = 0;
        }

        for(int i=1; i<=n; i++){
            cin >> arr[i];
            hsh[arr[i]]++;
        }

        if(hsh[arr[1]] == n){
            cout << 0 << endl;
            continue;
        }
        int maxCount = -1;
        int max=0;
        for(int i=1; i<=n; i++){
            if(hsh[arr[i]] >= maxCount){
                maxCount = hsh[arr[i]];
                max = arr[i];
            }
        }

        
        
    }
}