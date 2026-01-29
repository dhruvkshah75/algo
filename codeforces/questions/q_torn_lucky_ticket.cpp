#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<string> v;
    v[0] = "0";
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){

        }
    }

    int combinations = 0;
    // for each combination of two stings Si+Sj
    string s; // --> which is the combination of two 
    vector<int> pf;
    if(s.length()%2 == 0){
        for(int i=1; i<=n; i++){
            pf[i] = pf[i-1] + s[i] - '0';
        }
        if(pf[n] == 2*pf[n/2]) combinations++;
    }
    

}