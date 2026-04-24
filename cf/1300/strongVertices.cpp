#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1857/D

// Can be done in O(N)
void solve(int n) {

    /* Given condition for Au - Av >= Bu - Bv => we can rearrange to get (Au - Bu >= Av - Bv)
       V[u] >= V[v] => then there is a edge u -> v
       instead of sorting => only take those which is equal to max_element 
       For a vertex u to be strong => there should be a path from u to all other vertices */

    // storing the val a[i] - b[i] and the index of the vertex 
    vector<pli> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i].first;

    for(int i = 0; i < n; i++) {
        ll x; 
        cin >> x;

        v[i].first -= x;
        v[i].second = i;
    }

    // sort in descending order 
    sort(allr(v));

    vector<int> nodes;

    ll prev = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        if(prev == LLONG_MIN) {
            nodes.push_back(v[i].second);
            prev = v[i].first;
        }
        else if(prev == v[i].first) {
            nodes.push_back(v[i].second);
        }
        else {
            break;
        }
    }

    // we must print strong vertices in ascending order 
    sort(all(nodes));

    cout << nodes.size() << endl;

    for(int &node: nodes) 
        cout << node + 1 << " ";  // make the nodes 1 based 
    cout << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
    }
}