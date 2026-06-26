// ================================================ Multi Source BFS =======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

/* Explanation: Multi Source BFS 
   We must find out the number of candies we can get 
   starting from the initial boxes => but only those boxes that are open and we found them 
   Opening each box gives certain keys so set these status bits of those boxes to 1 
   => that if they are found then we can open them 

   C++ Syntax note: when traversing through a set or map and then we delete the current element 
   then the iterator to traverse becomes null
   So use the it for traversing and then use this => it = set.erase(it) => this erases the current element 
   and then returns the iterator to the next element 
*/

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
                    vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        // we have boxes 0-n-1

        int res = 0;

        queue<int> q;
        vector<bool> vis(n, false);
        unordered_set<int> boxes;

        for(int i = 0; i < initialBoxes.size(); i++) {
            int b = initialBoxes[i];
            // if box is open then push into the queue
            if(status[b] == 1) {
                q.push(b);
                vis[b] = true;
            }
            else boxes.insert(b); 
        }

        // bfs
        while(!q.empty()) {
            int b = q.front();
            q.pop();

            res += candies[b];

            // opening this box we get certain keys => set status = 1
            for(int k: keys[b]) status[k] = 1;

            for(auto it = boxes.begin(); it != boxes.end();) {
                int a = *it;

                if(status[a] == 1) {
                    q.push(a);
                    vis[a] = true;
                    // this deletes the current element and gives the next it
                    it = boxes.erase(it);
                }
                else it++;
            }

            // now check the contained boxes that we find on opening b 
            for(int x: containedBoxes[b]) {
                if(status[x] == 1) {
                    q.push(x);
                    vis[x] = true;
                }
                else boxes.insert(x);
            }
        }

        return res;
    }
};