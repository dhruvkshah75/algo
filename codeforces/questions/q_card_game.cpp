#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279
#define alice cout << "Alice" << endl;
#define bob cout << "Bob" << endl;

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

    for(int i=0; i<n; i++){
        if(sum_a <= 0){
            bob;
            break;
        }
        if(sum_b <= 0){
            alice;
            break;
        }

        if(str[i] == 'A'){
            for(int j=i+2; j<=n; j++){
                if(b[j] == 1 && j!=n){
                    b[i] = 1; sum_b += 1;
                    a[i] = 0; sum_a -= 1;
                    break; 
                }
                else if(b[j] == 1 && j == n){
                    b[i] = 0; sum_b -= 1;
                    a[i] = 1; sum_a += 1;
                    break;
                }
            }
        }
        else if(str[i] == 'B'){
            for(int j=i+2; j<=n; j++){
                if(a[j] == 1 && j!=n){
                    a[i] = 1; sum_a += 1;
                    b[i] = 0; sum_b -= 1;
                    break;
                }
                else if(a[j] == 1 && j == n){
                    a[i] = 0; sum_a -= 1;
                    b[i] = 1; sum_b += 1;
                    break;
                }
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