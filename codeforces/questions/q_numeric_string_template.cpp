// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    fc(i, n, a);

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (s.size() != n) {
            no;
            continue;
        }
        unordered_map<char, int> char_to_num;
        unordered_map<int, char> num_to_char;
        bool valid = true;
        for(int i=0; i<n; i++){
            if(char_to_num.count(s[i])){   // use this as this does not create a key with value as 0
                if (char_to_num[s[i]] != a[i]){
                    valid = false;
                    break;
                }
            } 
            else{
                char_to_num[s[i]] = a[i];
            }
            if(num_to_char.count(a[i])){
                if(num_to_char[a[i]] != s[i]){
                    valid = false;
                    break;
                }
            } 
            else{
                num_to_char[a[i]] = s[i];
            }
        }
        if(valid){
            yes;
        } 
        else no;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}