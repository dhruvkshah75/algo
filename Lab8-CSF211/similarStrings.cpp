#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/similar-string-groups/description/

// ======================================================================================
//                  Optimised Code (Without DSU) only BFS 
// ======================================================================================
/*
    We can consider the question by making a graph 
    nodes: strings 
    edges: when 2 strings are similar 
    Simply create an adjacency List and then apply bfs to get the number of connected components 
*/
class OptimisedSolution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        // we must find the number of groups are formed => no of connected components present 

        vector<vector<int>> adjL(n);
        // we store the nodes as the indexes from the strs array 

        // O(N^2 * L)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        // now we calculate the number of connected components 

        int count = 0;
        unordered_set<int> vis;

        for(int i = 0; i < n; i++) {
            if(vis.find(i) == vis.end()) {
                count++;
                bfs(adjL, i, vis);
            }
        }

        return count;
    }

private:
    bool isSimilar(string &s1, string &s2) {
        int diff = 0;  // no of places where s1 and s2 differ => should not be more than 2 

        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
                if(diff > 2) return false;
            }
        }

        // since the words are anagrams so the diff will always be 0 or 2 (even number)
        return true;
    }

    void bfs(vector<vector<int>> &adjL, int start, unordered_set<int> &vis) {
        // we use a visited set for marking nodes 
        // BFS
        queue<int> q;

        q.push(start);
        vis.insert(start);

        while(!q.empty()) {
            int nodeIdx = q.front();
            q.pop();

            for(int nbgIdx: adjL[nodeIdx]) {
                if(vis.find(nbgIdx) != vis.end()) continue;

                q.push(nbgIdx);
                vis.insert(nbgIdx);
            }
        }
    }
};


// =====================================================================
//              Unoptimised Code (Without DSU or Optimization)
//              Kind of like a Brute force solution
// ======================================================================

/*
    Since this question is based on connected components we can use DSU 
*/

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // we are allowed to swap only one place 
        // we can think of this question as multiple connected components 

        unordered_set<string> words;
        // this also ensures there are no duplicates 

        for(int i = 0; i < n; i++) 
            if(words.find(strs[i]) == words.end())
                words.insert(strs[i]);

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(words.find(strs[i]) != words.end()) {
                // the number of times bfs is called is the number of groups that are needed 
                cnt++;
                bfs(words, strs[i]);
            }
        }

        return cnt;
    }

private:

    void bfs(unordered_set<string> &words, string &start) {

        queue<string> q;
        q.push(start);
        words.erase(start);
        // instead of marking words we remove it from the current set 

        while(!q.empty()) {
            string node = q.front();
            q.pop();

            // now we must push the possibilities by swapping places 
            for(int i = 0; i < node.length(); i++) {
                for(int j = i + 1; j < node.length(); j++) {
                    swap(node[i], node[j]);
                    if(words.find(node) != words.end()) {
                        q.push(node);
                        words.erase(node);
                    }
                    // now we backtrack 
                    swap(node[i], node[j]);
                }
            }
        }
    }
};

// ========================================================================================
//                  Optimised Solution using DSU 
// ========================================================================================

