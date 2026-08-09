// ========================================= greedy + heaps ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-spending-after-buying-items/description/

/**
 * Explanation: greedy + heaps 
 * we are supposed to maximise the spending => buying a item costs us values[i][j] * d
 * so to maximise the cost we must buy the most expensive item on the later days (higher d)
 * so use a min heap and pop the smallest element 
 * since we are buying all the m*n items so run the loop for m*n times 
 * */

typedef long long ll;

class Solution {
public:
    ll maxSpending(vector<vector<int>> &values) {
        int m = values.size(), n = values[0].size();

        auto cmp = [&](const pair<int,int> &a, const pair<int,int> &b) {
        	// return true if a has lower priority than b 
        	return values[a.first][a.second] > values[b.first][b.second];
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        // pq = {i, j} stores the ith shop and jth item 

        // prefill the pq with rightmost items from each shop 
        for(int i = 0; i < m; i++) 
        	pq.push({i, n-1});

        ll ans = 0;

        for(int d = 1; d <= m * n; d++) {
        	auto [i, j] = pq.top();
        	pq.pop();

        	ans += values[i][j] * 1LL * d;

        	// add the next item of this shop
        	if(j > 0) pq.push({i, j-1});
        }

        return ans;
    }
};
// Time Complexity = O(M * N * Log(M))
