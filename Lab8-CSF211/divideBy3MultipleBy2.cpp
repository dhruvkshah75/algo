#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/977/D

// similar to water jug problem => for each number we have two possibilities for the future number

void solve(int n, vector<ll> seq) {
    // we pick the starting element one by one

    // store the value versus index 
    unordered_map<ll,int> mp;

    for(int i = 0; i < n; i++) 
        mp[seq[i]] = i;


    for(int i = 0; i < n; i++) {
        // keep seq[i] as starting element 
        unordered_map<ll,int> cur_mp = mp;  // fresh copy each time
        vector<int> parent(n, -1);

        int endNodeIndex = -1;

        queue<int> q;  // store INDICES not values
        q.push(i);

        cur_mp.erase(seq[i]);

        // BFS
        while(!q.empty()) {
            int nodeIdx = q.front();
            q.pop();
            ll nodeVal = seq[nodeIdx];
            
            // push in the two possibilities 
            // nodeVal * 2
            if(cur_mp.find(2 * nodeVal) != cur_mp.end()) {
                parent[cur_mp[2 * nodeVal]] = nodeIdx;
                q.push(cur_mp[2 * nodeVal]);
                // update the endNodeIndex so we can print the path using parent index array 
                endNodeIndex = cur_mp[2 * nodeVal];
                cur_mp.erase(2 * nodeVal);
            }

            // nodeVal / 3 (if divisible by 3)
            if(nodeVal % 3 == 0 && cur_mp.find(nodeVal/3) != cur_mp.end()) {
                parent[cur_mp[nodeVal / 3]] = nodeIdx;
                // store the parent of this element as parent of idx is nodeIdx 
                q.push(cur_mp[nodeVal / 3]);
                endNodeIndex = cur_mp[nodeVal / 3];
                cur_mp.erase(nodeVal/3);
            }
        }

        if(!cur_mp.empty()) continue;

        // IMPORTANT PART reconstruct path using parent indices
        vector<ll> path;

        int curr = endNodeIndex;
        while(curr != -1) {
            path.push_back(seq[curr]);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        for(ll val: path) 
            cout << val << " ";
        cout << endl;


        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> seq(n);

    for(int i = 0; i < n; i++) 
        cin >> seq[i];

    solve(n, seq);
}