#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/449/B

struct Node {
    ll dist;
    int node;
    bool is_train; 
};

void solve(int n, int m, int k) {
    // first => simplify the trains => only keep the shortest path of train to reach ith vertex 

    vector<vector<pair<int,int>>> adjL(n+1);

    // input of the roads 
    for(int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adjL[u].push_back({v, x});
        adjL[v].push_back({u, x});
    }

    // custom comparator for pq => min heap on dist and if same dist keep the roads on top 
    auto cmp = [&](const Node &a, const Node &b) {
        // return true if a has less priority than b
        if(a.dist == b.dist) {
            // if a is train it should be below as a can be shut down 
            if(a.is_train) return true;
            else return false;
        }
        return a.dist > b.dist;
    };

    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

    vector<ll> dist(n+1, LLONG_MAX);
    // use a bool vector to denote if we use the train in the shortest path to reach the ith vertex 
    vector<bool> used_train(n+1, false); 

    // push the vertext 1 => source vertex 
    dist[1] = 0;
    pq.push({0, 1, false});

    int closedTrains = 0;

    // min_train[i] = min dist to reach ith node using the train from 1
    vector<int> min_train(n+1, 0);
    // close down the duplicate edges of trains and keep the smallest one 
    for(int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;

        if(min_train[s] == 0) min_train[s] = y;  // first train to reach 
        else if(y < min_train[s]) {
            // found a better path to reach => so close the previous train route 
            min_train[s] = y;
            closedTrains++;
        }
        else closedTrains++;  // this train route to reach s stop is not the shortest 
    }

    // update the dist with trains distances and push the trains routes into the pq as they all are the neigbours of vertex 1
    for(int i = 2; i <= n; i++) {
        if(min_train[i] > 0) {
            // train reached the ith node 
            dist[i] = min_train[i];
            used_train[i] = true;
            pq.push({(ll)min_train[i], i, true});
        }
    }

    // now apply dijikstra and see if we get a better road to reach the ith vertex then remove the ith train 

    while(!pq.empty()) {
        auto [currDist, node, train] = pq.top();
        pq.pop();

        // remove the stale entries => we already have a better path
        if(currDist > dist[node]) continue;

        for(auto [nbg, w]: adjL[node]) {
            ll newDist = dist[node] + w;
            
            if(newDist < dist[nbg]) {
                // found a strictly better path via road 
                dist[nbg] = newDist;
                used_train[nbg] = false;
                pq.push({newDist, nbg, false});
            }
            else if(newDist == dist[nbg]) {
                // found a road that ties with train => choose road but dont push as the train already in pq 
                used_train[nbg] = false;
            }
        }
    }

    // if there was a train (min_dist[i] > 0 && used_train[i] = false => so closed down the train route 
    for(int i = 2; i <= n; i++) {
        if(min_train[i] > 0 && !used_train[i]) 
            closedTrains++;
    }

    cout << closedTrains << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    solve(n, m, k);
}