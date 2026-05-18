#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-boomerangs/description 


class Solution {
    int dist(const vector<int>&a, const vector<int>&b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();

        // boomerang is the distance between i and j is equal to i and k 
        // fix i and j and then find k using map 
        int boomerangs = 0;

        // store the distance with the ith point 
        unordered_map<int,int> distance;

        for(int i = 0; i < n; i++) {
            // fill in the map 
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int d = dist(points[i], points[j]);
                distance[d]++;
            }

            // now calculate => we have x points with equal distance with ith point 
            for(auto &[d, cnt]: distance) {
                boomerangs += cnt * (cnt - 1);
            }

            distance.clear();
        }

        return boomerangs;
    }
};