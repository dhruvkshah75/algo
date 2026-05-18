// BREADTH FIRST SEARCH ON STRINGS 
#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/k-similar-strings/description/
// IMPORTANT QUESTION 

/*
    instead of swapping randomly, swap at first mismatch and then swap all possiblities for that mistmatch 
    assume string s1 = aadbcdedf and string s2 = aadcbdfe  
    first mistmacth is s1[2] = b and target[2] = d => now search for all 'd's and swap out b with them 
    so we push multiple candidates => so by doing this we correct the positions one by one as we go 
*/
class Solution {
    int bfs(string s1, string target) {
        int n = s1.length();

        unordered_set<string> visited;

        queue<pair<string,int>> q;
        q.push({s1, 0});
        visited.insert(s1);
        // BFS 
        while(!q.empty()) {
            auto [state, level] = q.front();
            q.pop();

            if(state == target) return level;

            // now we must push in after swapping 
            // instead of blindly swapping we swap at first non matching position => lesser candidates per state 
            for(int i = 0; i < n; i++) {
                if(state[i] == target[i]) continue;
                // ith index first mismatch => we will now swap 
                char search = target[i];
                for(int j = i+1; j < n; j++) {
                    if(state[j] == search) {    // got the char to swap to get in correct pos
                        swap(state[i], state[j]);
                        // push the new state if not visited
                        if(visited.find(state) == visited.end()) {
                            q.push({state, level+1});
                            visited.insert(state);
                        }
                        swap(state[i], state[j]);
                        // backtrack => revert the string check further and push newer candidates on the exisiting state 
                    }
                }
                break;
            }
        }
        return -1;
    }

public:
    int kSimilarity(string s1, string s2) {
        // apply bfs on the strings as this would result in a shortest path i.e. k
        return bfs(s1, s2);
    }
};