#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    cin.ignore();
    while(tt--){
        string str;
        getline(cin, str);
        string ans = "";
        if (!str.empty()) ans += str[0]; 

        for(int i = 1; i < str.size(); i++){
            if(str[i] == ' ' && i + 1 < str.size()){
                ans += str[i + 1]; 
            }
        }

        cout << ans << endl;
    }
}
