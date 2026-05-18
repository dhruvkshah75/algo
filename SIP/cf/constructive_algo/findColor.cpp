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

// question link: https://codeforces.com/problemset/problem/40/A

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    int d2 = x * x + y * y;
    int k = sqrt(d2);

    // On circle boundary
    if(k * k == d2) {
        cout << "black" << endl;
        return 0;
    }

    int quad = (x < 0) ^ (y < 0);

    if((k + quad) % 2 == 0)
        cout << "black" << endl;
    else
        cout << "white" << endl;
}