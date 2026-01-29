#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9 + 7
#define PI 3.14159265358979323846
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(a) (a).begin(), (a).end()

bool isPalindrome(string &str)
{
    int len = str.size();
    f(i, len)
    {
        if (str[i] != str[len - i + 1])
            return false;
    }
    return true;
}

void solve(){
    int n, x;
    ll k;
    string s;
    cin >> s;
    int cnt = 0;
    int pos = x;
    bool flag = false;
    // fails for RRRRRRRRR and strating point as -1 
    f(i, s.size()){
        if (s[i] == 'R'){
            pos += 1;
            cnt++;
        }
        else if (s[i] == 'L'){
            pos -= 1;
            cnt++;
        }
        if (pos == 0){
            break;
            flag = true;
        }
            
    }
    if(flag) cout << (k + 1) / cnt << endl;
    else cout << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}