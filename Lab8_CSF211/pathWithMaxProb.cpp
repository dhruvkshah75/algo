#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-with-maximum-probability/description/

// opposite of dijikstra => find the longest path => use max heap instead of min heaps 
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // the question is direct on disjikstra algorithm => but multiplying directly will cause precision error
        // d1 * d2 * d3 * d4 * ..  => simply take log(d1 * d2 * d3 * d4 * ..)  = log(d1) + log(d2) + ..
        
        vector<vector<pair<int,double>>> adjL(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        // stores the probability paths as a sum of logs to prevent precision errors => log(0.0) is negative infinity
        vector<double> prob(n, (double)-1e18);
        

        // max heap to store the the dist to node => pq = {dist, node} => we are supposed to find the longest path
        priority_queue<pair<double,int>> pq;
        pq.push({log(1.0), start_node});
        prob[start_node] = log(1.0);

        while(!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            // remove the stale entries => we need maximum probabilities 
            if(currProb < prob[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                double newProb = currProb + log(w);
                if(newProb > prob[nbg]) {
                    pq.push({newProb, nbg});
                    prob[nbg] = newProb;
                }
            }
        }

        // now return the max path of reaching end_node 
        return exp(prob[end_node]);
        
    }
};