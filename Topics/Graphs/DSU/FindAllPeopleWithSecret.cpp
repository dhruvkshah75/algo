// ======================================================= Graphs - DSU =====================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// question link: https://leetcode.com/problems/find-all-people-with-secret/description/

// ======================================== Very Important Question =========================================================

/* Explanation: DSU (disjont set union)
   We must find all the people to whom the secret can be shared 
   Firstly we sort the meetings based on the time (ascending)
   person 0 tells the firstPerson and then we process the meetings 
   The key is to process meetings that are at the same time => they are to be processed togethor 
   Firstly make all the connections at time t and then check who all know the secret and add them to the res 
   and reset those components that dont know the secret 

   Key of the Question: Use DSU to make connections of people and then reset those not knowing the secret 
   DSU + reseting (Most imporant Part)

   NOTE:
   Here DSU keeps the note of the connected component that knows the secret and we make only temporary connections at time t 
   then we reset those connections that are not the part of the secret component 
*/

class Solution {
private:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);   // path compression
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return;

            if(size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
        }
    };

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 0 - n-1 people 
        int m = meetings.size();

        // sort the meetings based on the timings (time t)
        sort(meetings.begin(), meetings.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });

        DSU d(n);

        // use set for res to prevent duplicates 
        unordered_set<int> res;
        res.insert(0);
        res.insert(firstPerson);

        // person 0 shares the secret to the firstPerson 
        d.unite(0, firstPerson);

        int ind = 0;

        while(ind < m) {
            int j = ind, t = meetings[ind][2];

            while(j < m && meetings[j][2] == t) {
                d.unite(meetings[j][0], meetings[j][1]);
                j++;
            }

            // figure out which component knows the secret and reset those who dont know
            for(int k = ind; k < j; k++) {
                int p1 = meetings[k][0], p2 = meetings[k][1];
                // p1 is of component that knows the secret 
                if(d.find(p1) == d.find(0)) {
                    res.insert(p1);
                    res.insert(p2);
                }
                else {
                    // p1 and p2 dont know the secret even after the meetings at time t 
                    d.parent[p1] = p1;
                    d.parent[p2] = p2;
                    // reset p1 and p2
                }
            }

            ind = j;
        }

        return vector<int>(res.begin(), res.end());
    }
};
