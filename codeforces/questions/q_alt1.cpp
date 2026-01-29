#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279
#define bob cout << "Bob" << endl;
#define alice cout << "Alice" << endl;


void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> a(n+1);
    int sum_a = 0;
    vector<int> b(n+1);
    int sum_b = 0;
    for(int i=0; i<n; i++){
        if(str[i] == 'A'){
            a[i+1] = 1;
            sum_a += 1;
        } 
        else if(str[i] == 'B'){
            b[i+1] = 1;
            sum_b += 1;
        } 
    }
    int index = 0;
    for(int j=1; j<=n; j++){
        if(a[j] == 1){
            index = j;
            break;
        }
    }

    for(int i=index; i<n; i++){
        if(sum_a <= 0){
            bob;
            break;
        }   
        if(sum_b <= 0){
            alice;
            break;
            }
        if(a[i+1] == 0) continue;
        for(int j=i+2; j<=n; j++){
            if(j == n){
                if(b[0] == 1){
                    b[0] = 0; sum_b -= 1;
                    a[0] = 1; sum_a += 1;
                    break;
                }
            }
            else if(b[j] == 1){
                b[i] = 1; sum_b += 1;
                a[i] = 0; sum_a -= 1;
                break; 
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}