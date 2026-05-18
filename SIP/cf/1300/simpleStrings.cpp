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

// question link: https://codeforces.com/problemset/problem/665/C

void solve(string &str) {
    // whenerver str[i] == str[i-1] replace str[i] with a new char such that str[i+1] str[i] and str[i-1] is distinct 
    int n = str.length();

    for(int i = 1; i < n; i++) {
        if(str[i] == str[i-1]) {
            // change str[i]
            for(char c = 'a'; c <= 'z'; c++) {
                if(str[i-1] != c && (i+1 >= n || c != str[i+1])) {
                    str[i] = c;
                    break;
                }
            }
        }
    }

    cout << str << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    solve(str);
}