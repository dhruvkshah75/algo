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
#define allr(x), x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/295/B
// floyd Warshall's algorithm 

void solve(int n, vector<vector<int>> &adjMat, vector<int> &del) {
    // a[i][j] = 1e5 and n = 500 => longest worst path is N-1 edges => 499 * 1e5 (int)

    vector<vector<int>> dist = adjMat;

    // in floyd warshall algorithm we add intermediate vertices to get the shortest path via that vertex => here we remove one vertex

    /*  Very Important Note: 
        Similar to DSU + offline processing where we process the queries in reverse so instead of deletion we get insertions 
        Here we do the same process the deletion array in the reverse order => which becomes insertion 
        so which is exactly equal to floyd warshall 
        
        Always Remember => deletion in the reverse direction is Insetion */

    vector<ll> result;

    // also maintain a vector to know which vertices are added and only add their shortest path 
    vector<bool> isAdded(n+1, false);


    for(int k = n-1; k >= 0; k--) {
        // now the vertex mid is added to the graph 
        int mid = del[k];
        isAdded[mid] = true;

        ll curr_sum = 0; 

        // calculate the shortest distance with mid as the intermediate node => insertion of nodes in the reverse
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
                // only add to the current sum if both i and j are added to the graph 
                if(isAdded[i] && isAdded[j]) 
                    curr_sum += dist[i][j];
            }
                
        result.push_back(curr_sum);
    }

    reverse(all(result));

    for(ll sum: result) 
        cout << sum << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adjMat(n+1, vector<int>(n+1, 1e9));

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> adjMat[i][j];

    vector<int> del(n);

    for(int i = 0; i < n; i++) 
        cin >> del[i];

    solve(n, adjMat, del);
}