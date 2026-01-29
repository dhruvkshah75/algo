#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<string> binary_str(n);
        for(int i=0; i<n; i++){
            binary_str[i] = str;
            if(str[i] == '0') binary_str[i][i] = '1';
            else if(str[i] == '1') binary_str[i][i] = '0';
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(binary_str[i][j] == '1') count++;
            }
        }
        cout << count << endl;
    }
}