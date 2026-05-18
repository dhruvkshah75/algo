#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/jump-game-iv/description/

#define pii pair<int,int> 

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // use bfs to reach the end 
        int target = n - 1;

        // base case when start and target are the same 
        if(n == 1) return 0;

        vector<bool> vis(n, false);

        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> same;
        // store the indexes of the same elements with a label 

        for(int i = 0; i < n; i++) {
            if(mp.count(arr[i])) {
                same[mp[arr[i]]].push_back(i);
            }
            else {
                mp[arr[i]] = i;
                same[mp[arr[i]]].push_back(i);
            }
        }

        unordered_set<int> seen;
        // to prevent going through all the nbg of already seen node 
        queue<pii> q;
        // q = {currIdx, level}
        q.push({0, 0});
        vis[0] = true;

        while(!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();

            if(curr == target) return level;

            if(curr + 1 < n && !vis[curr + 1]) {
                q.push({curr + 1, level + 1});
                vis[curr + 1] = true;
            }

            if(curr - 1 >= 0 && !vis[curr - 1]) {
                q.push({curr - 1, level + 1});
                vis[curr - 1] = true;
            }

            if(mp.count(arr[curr])) {
                int index = mp[arr[curr]];

                if(seen.find(index) != seen.end()) 
                    continue;
                seen.insert(index);

                for(auto idx: same[index]) {
                    if(vis[idx]) continue;

                    q.push({idx, level + 1});
                    vis[idx] = true;
                }
            }
        }

        return -1;
    }
};