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

// question link: https://codeforces.com/problemset/problem/1702/E

void solve(int n) {
    /* In this question to split dominoes into two sets => the first and foremost question is that a number cannot 
       appear more than 2 times and {1, 1} are restricted 
       Using DSU get the sizes of each component 
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pii> edges(n);

    for(auto &[u, v]: edges) 
        cin >> u >> v;


}