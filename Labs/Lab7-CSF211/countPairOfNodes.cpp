#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-pairs-of-nodes/description/

/*
    deg = 2, 3, 4, 5, 8 => left = 2 and right = 8 ==> if left + right > q then all left will work 
    so do right-- 
    using the two pointer approach we get degree[u] + degree[v] > q => this in the sorted degrees array 
    using map<pair<int,int>,int> edge_counts we get all the shared edges between u and v 
    we remove out all the cases when degree[u] + degree[v] > q and then after updating the value degree[u] + degree[v] 
        - shared count <= q if shared count becomes less than q then reduce the count
*/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n+1, 0);

        int k = edges.size();    // no of edges in the graph

        // for storing the edges between them 
        map<pair<int,int>,int> edge_counts;    // {{a,b}, cnt} => a < b always

        for(int i = 0; i < k; i++) {
            int u = edges[i][0], v = edges[i][1];
            degree[u]++;
            degree[v]++;
            edge_counts[{min(u, v), max(u, v)}]++;
        }

        vector<int> sorted_deg = degree;  // 1 based 
        sort(sorted_deg.begin() + 1, sorted_deg.end());

        vector<int> result;

        // for each query we find how many pairs => degree[u] + degree[v] - count of edges b/w u, v
        for(int q: queries) {
            int count = 0;

            // using two pointer approach we solve this => for this we need sorted degree
            int left = 1, right = n;
            while(left < right) {
                if(sorted_deg[left] + sorted_deg[right] > q) {
                    count += (right - left);
                    right--;
                }
                else left++;
            }

            // now correct the count by removing the multiple edges 
            // traverse through the edge_counts and remove the edge count if counted for this query 
            for(auto &[edge, shared_cnt]: edge_counts) {
                auto &[u, v] = edge;
                // remove this edge if it violates incident(a, b) > q
                if(degree[u] + degree[v] > q && degree[u] + degree[v] - shared_cnt <= q)
                    count--;
            }

            result.push_back(count);
        }

        return result;
    }
};