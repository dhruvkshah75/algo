#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll sum_digits(int x){
    int sum = 0;
    while(x>0){
        int rem =x%10;
        sum+=rem;
        x/=10;
    }
    return sum;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int x, k;
        cin >> x >> k;
        string num ="";
        for(int i=0; i<k; i++){
            num+=x;
        }
        
        ll check1 = (k*sum_digits(x))%3;
        int check2 = (num[num.size()-1] - '0');
        if(check2%2 == 0 || check2 == 5 || check2 == 0 || check1 == 0) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        
    }
}