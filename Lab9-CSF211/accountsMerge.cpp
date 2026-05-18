#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/accounts-merge/description/

// HATE YOURSELF QUESTION => DSU implementation to form sets of same accounts 

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // we must apply dsu to get the number of unique accounts
        // merge the accounts of the same connected component  
        DSU d(n, accounts);

        // map each email to a index of the account 
        unordered_map<string,int> emailToIndex;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string currEmail = accounts[i][j];

                if(emailToIndex.count(currEmail)) {
                    // a person with the same email exists => so connect the edge
                    d.unite(emailToIndex[currEmail], i);
                }
                else {
                    emailToIndex[currEmail] = i;
                }
            } 
        }

        return d.merge();
    }

private:

    struct DSU {
        vector<int> parent, size;
        vector<vector<string>> accounts;

        DSU(int n, vector<vector<string>> &accounts) {
            size.resize(n, 1);
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            this->accounts = accounts;
        }

        int find(int u) {
            if(parent[u] != u) 
                parent[u] = find(parent[u]);

            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            // u and v are already the same part of the set
            if(pu == pv) return; 

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        // ==========================================================
        // now we must create the merged accounts information 
        vector<vector<string>> merge() {
            int n = parent.size();

            unordered_map<int,string> owner;
            unordered_map<int,unordered_set<string>> emails;

            for(int i = 0; i < n; i++) {
                if(parent[i] == i) {
                    // root node 
                    owner[i] = accounts[i][0];        
                }
                // find the parent of the current index 
                int pi = find(i);

                for(int j = 1; j < accounts[i].size(); j++) 
                    emails[pi].insert(accounts[i][j]);
            } 

            // now build the final result 
            vector<vector<string>> result;

            for(auto [i, name]: owner) {
                vector<string> temp;

                for(string email: emails[i]) {
                    temp.push_back(email);
                }
                // we much sort the emails (reverse) and then add the name at the end and reverse
                sort(temp.rbegin(), temp.rend());
                temp.push_back(name);

                reverse(temp.begin(), temp.end());

                result.push_back(temp);
            }

            return result;
        }
        // ==========================================================
    };
};