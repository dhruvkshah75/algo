#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://leetcode.com/problems/process-restricted-friend-requests/description/

#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests) {
        // n nodes in the graph
        // for each friend request we make we can loop through all the restrictions and check if this request is allowed 
        int m = requests.size(), k = restrictions.size();

        vector<bool> result(m, false);

        DSU d(n+1);

        // loop through requests 
        for(int i = 0; i < m; i++) {
            // now check if we can approve this request by checking all the requests
            bool approved = true;
            int pU = d.find(requests[i][0]), pV = d.find(requests[i][1]);

            if(pU == pV) {
                // already friends 
                result[i] = true;
                continue;
            }

            for(int j = 0; j < k; j++) {
                int pX = d.find(restrictions[j][0]), pY = d.find(restrictions[j][1]);

                if((pU == pX && pV == pY) || (pU == pY && pV == pX)) {
                    approved = false;
                    break;
                }
            }

            if(approved) {
                d.merge(requests[i][0], requests[i][1]);
                result[i] = true;
            }
        }

        return result;
    }

private:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(all(parent), 0);
        }

        int find(int u) {
            if(parent[u] != u)
                parent[u] = find(parent[u]);
            return parent[u];
        }

        void merge(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};