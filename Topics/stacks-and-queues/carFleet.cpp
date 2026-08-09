// ================================ monotonic stack ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/car-fleet/description/

/**
 * first of all sort the cars based on their positions to handle them position by position 
 * for a car at pos to reach target will take time => time = (target - pos) / speed
 * the stack will hold the time taken by fleets to reach the car in mononotonic increasing 
 *
 * if the curr_car time > st.top() then this car will form a new fleet 
 * otherwise i.e. curr_car time <= st.top() then it will merge with the closest fleet 
 * 
 * Here the stack is not the traditional nge type => here the stack just stores the last fleet's 
 * time to reach the end  
 * 
 * make use of double as integer division approximates two cars with complete different time into one 
 **/

class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();

        vector<pair<int,int>> cars(n);
        for(int i = 0; i < n; i++) 
        	cars[i] = {position[i], speed[i]};

        // sort the cars on the basis of their position asc 
        sort(cars.begin(), cars.end());

        stack<double> st;
        // monotonic increasing stack which holds the fleet's time to reach the target 

        for(int i = n-1; i >= 0; i--) {
        	double curr_time = 1.0 * (target-cars[i].first) / cars[i].second;

        	// if this car cannot reach the previous fleet then it forms a new fleet itself 
        	if(st.empty() || curr_time > st.top()) st.push(curr_time);
        }

        return (int)st.size();
    }
};