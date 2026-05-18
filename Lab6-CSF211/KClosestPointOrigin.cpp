#include<bits/stdc++.h>
using namespace std;

// question link: 
// Earlier solved this question using quick select algorithm 

// Time complexity: O(N*LogK)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we maintain priority queue based on closeness to the origin 

        int n = points.size();

        auto cmp = [&](const vector<int> &a, const vector<int>&b) {
            int distA = a[0] * a[0] + a[1] * a[1];
            int distB = b[0] * b[0] + b[1] * b[1];
            // If cmp(a, b) is true, it means a has lower priority than b
            // Returns true if a should be "below" b (Max-Heap)
            return distA < distB;
        };
        // max heap with custom priority;
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> max_heap(cmp);

        for(int i=0; i<n; i++) {
            max_heap.push(points[i]);
            // if the size of heap becomes k + 1 pop the top which is the farthest from the origin 
            if(max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> ans;

        while(!max_heap.empty()) {
            ans.push_back(max_heap.top());
            max_heap.pop();
        }

        return ans;
    }
};