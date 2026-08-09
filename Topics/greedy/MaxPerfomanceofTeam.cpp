// ======================================== sorting + heaps + greedy ==================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-performance-of-a-team/description/

/**
 * we are supposed to pick k engineers => perfomance of the team is sum of speeds * min of their effiecencies 
 * so deal with this thing we can do one thing is to fix the worker with effeciency as x 
 * and include the other k-1 workers such that effiency > x
 * so sort the engineers based on their effiency in ascending order and traverse in the reverse 
 * note: if all k could not form a team => we could form a team with at most k engineers 
 * but k is prefferable as speed is positive so more the better 
 * 
 * fixing the v[ind] then take the best k-1 engineers from v[ind+1....n]  
 * for getting the highest speed in v[ind+1....n] use min heap and running sum of the heap 
 **/

typedef long long ll;

class Solution {
private: 
	const int MOD = 1e9+7;

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        // store the engineers toegthor so sorting works 
        vector<pair<int,int>> v(n);

        for(int i = 0; i < n; i++) 
        	v[i] = {speed[i], efficiency[i]};


        sort(v.begin(), v.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
        	return a.second < b.second;
        });

        // min heap to store the k-1 workers's speed whose effeciency >= x
        priority_queue<int, vector<int>, greater<int>> pq;

        ll best = v[n-1].first * 1LL * v[n-1].second;
        ll speed_sum = v[n-1].first;
        pq.push(v[n-1].first); // add this one in the heap for next calc

        for(int ind = n-2; ind >= 0; ind--) {
        	// v[ind] is the fixed engineer 
            
            // update the min heap to have exactly k-1 elements 
        	if(pq.size() == k) {
        		speed_sum -= pq.top();
        		pq.pop();
        	}

        	speed_sum += v[ind].first;
        	best = max(best, speed_sum * v[ind].second);
        	pq.push(v[ind].first);

        }

        return (int)(best % MOD);
    }
};