#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve(){
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    int area1 = l1*b1;
    int area2 = l2*b2;
    int area3 = l3*b3;
    int total = area1 + area2 + area3;
    bool check = false;
    for(int i=1; i<total/2; i++){
        if(i*i == total){
            check = true;
        }
    }
    if(check == false){
        no;
        return;
    }
    if((l1 == l2 && l2 == l3) && (b1+b2+b3 == l1)){
        yes;
        return;
    } 
    else if((b1 == b2 && b2 == b3) && (l1+l2+l3 == b1)){
        yes;
        return;
    } 
    else {
        int area = l1 * b1 + l2 * b2 + l3 * b3;
        int side = sqrt(area);
        if (l1 == side && b2 == b3 && b1 + b2 == side && l2 + l3 == side) {
            yes;
            return;
        }
        if (l2 == side && b2 + b1 == side && l1 + l3 == side) {
            yes;
            return;
        }
        if (l3 == side && b3 + b1 == side && l1 + l2 == side) {
            yes;
            return;
        }

        if (b1 == side && l1 + l2 == side && b2 + b3 == side) {
            yes;
            return;
        } 
        if (b2 == side && l2 + l1 == side && b1 + b3 == side) {
            yes;
            return;
        }
        if (b3 == side && l3 + l1 == side && b1 + b2 == side) {
            yes;
            return;
        }
    }
    no;

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