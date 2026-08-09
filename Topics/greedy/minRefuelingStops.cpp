// ==================================== greedy + heaps ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-number-of-refueling-stops/description

/**
 * Solution is pretty obvious than it seems 
 * just use simpl greedy, pick the station with the max fuel and move on 
 * but we cannot just pick up fuel randomly => as this will not give the right min number of refueling stations 
 * Instead move till all the fuel is used up and then when we cannot further go ahead to the next station then 
 * pick out the max fuel from the station that we had seen and then go ahead to the next station 
 **/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        int n = stations.size();

        // store the fuel values of the stations that we visited 
        priority_queue<int> pq;

        int ans = 0, fuel = startFuel;
        int curr_pos = 0;

        for(int i = 0; i < n; i++) {
        	int st_pos = stations[i][0], st_fuel = stations[i][1];
        	int dist = st_pos - curr_pos;

        	// if we cannot reach this current station then collect fuel from the previous stations 
    		while(!pq.empty() && fuel < dist) {
    			fuel += pq.top();
    			pq.pop();
    			ans++;
    			// we used prev visited station with max fuel 
    		}

            if(dist <= fuel) {
                pq.push(st_fuel); 
                curr_pos = st_pos; // store that we visited this station and update fuel and pos
                fuel -= dist;
            }
        }

        // it is possible that we might not have been able to reach the end so use the stations 
        while(!pq.empty() && target - curr_pos > fuel) {
        	fuel += pq.top();
        	pq.pop();
        	ans++;
        }

        if(target - curr_pos <= fuel) return ans;
        else return -1;
    }
};