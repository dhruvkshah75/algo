#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1237/B

void solve(int n, vector<int> &a, vector<int> &b) {
    
    /* We use a simple two pointer approach => ptr i for cars entering the tunnel and ptr j for cars leaving the tunnel 
       when i != j then the some other car than i left before then it => it means j overtook */

    int i = 0, j = 0, cnt = 0;

    unordered_set<int> seen;

    while(i < n && j < n) {
        if(a[i] == b[j]) {
            seen.insert(a[i]);
            i++; 
            j++;
        }
        else if(a[i] != b[j]) {
            if(seen.count(a[i])) {
                // expected car already exited earlier → skip this a[i] car 
                i++;
            }
            else {
                // if b[j] exits earlier before a[i] => b[j] overtakes 
                seen.insert(b[j]); 
                cnt++;
                j++;
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for(int &x: a)
        cin >> x;

    for(int &x: b)
        cin >> x;

    solve(n, a, b);
}