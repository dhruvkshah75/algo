#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, m, k;
        cin >> n >> m >> k;
        int no = (n*m)/k;
        vector<vector<int>> arr(n+1, vector<int>(m+1));
        if(no == 1){
            int count = 0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    cout << count++ << " ";
                }
                cout << endl;
            }
            continue;
        }
        else{
            int num1 = 1;
            int count1 = 0;
            for(int i=1; i<=n; i++){
                for(int j=1; i<=m; j++){

                }
            }
        }
    }
}