#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1915/G

void solve(int n, int m, vector<tuple<int,int,int>> &edges, vector<int> &slow) {
    // we can take a bike that is not in our path as it my be helpful to us to reach the detination in a better 

    vector<vector<pair<int,int>>> adjL(n+1);

    for(int i = 0; i < m; i++) {
        auto [u, v, w] = edges[i];
        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});
    }

    // ============= Dijikstra algorithm ==============================
    //dist[cityNode][bikeTaken] = min time to reach city(node) using bike bought from city i.
    // pq = {dist, cityNode, currentBike} ==> currentBike is index of the bike taken from ith city 

    // use of 2 state dist vector as the min path to reach city i depends on which bike we bought earlier  
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));

    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    
    // start from city 1 with bike from city 1
    pq.push({0, 1, 1}); 
    dist[1][1] = 0;       // distance to reach city 1 in bike from city 1 
    
    while(!pq.empty()) {
        auto [currTime, city, currBike] = pq.top();
        pq.pop();

        // remove stale entries => that we already have a better path to reach this city with currBike
        if(currTime > dist[city][currBike]) continue;

        for(auto [nbg, w]: adjL[city]) {
            int nbgBike = nbg;
            ll newTime = currTime + (ll)slow[currBike] * w;
            
            if(newTime < dist[nbg][currBike]) {
                dist[nbg][currBike] = newTime;
                // now we switch to the next bike if it is better 
                if(slow[nbgBike] < slow[currBike]) pq.push({newTime, nbg, nbgBike});
                else pq.push({newTime, nbg, currBike});
            }
        }
    }

    // now figure out the best way to reach the target ciy = n 
    ll minTime = LLONG_MAX;
    for(ll time: dist[n]) {
        minTime = min(minTime, time);
    }

    cout << minTime << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<tuple<int,int,int>> edges(m);

        for(auto &[u, v, w]: edges) 
            cin >> u >> v >> w;

        vector<int> slow(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> slow[i];
        }

        solve(n, m, edges, slow);
    }
}


/*
    In a standard Dijkstra, the cost of an edge (u, v) is a constant w.
    In this problem, the cost was w * s. Because s (slowness) is not a constant property of the edge, 
    but a property of your journey's history, the standard 1D Dijkstra breaks.
    The Rule: If the cost to traverse an edge depends on decisions made earlier (like which bike you bought), 
    you almost certainly need an extra state


    General Note:
    Understanding when to transition from dist[u] to dist[u][state] is the key to solving "Shortest Path Plus" problems.
    You need an extra dimension in your distance array whenever the future cost or 
    validity of a path depends on a decision made in the past.

    In a simple graph, if you are at node u, the shortest path to the destination doesn't care how you got to u. 
    But if the problem says "you can skip up to K edges" or "you cannot turn left twice," 
    the "how" suddenly matters.

    ================================ NOTE ========================================================================
    BASICALLY we need extra states when the current action or current choice depends on decisions made in the past
    ==============================================================================================================

*/