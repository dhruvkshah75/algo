#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/robot-collisions/description/
// Important Question on Stacks 

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // in this arrange them on a line and we push all the right moving robots in the stack 
        // and then when a left moving robot appears then pop the top and then make them fight 
        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;

        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // now we sort the robots on the basis of their position 
        sort(robots.begin(), robots.end());

        stack<int> st;       // store the index of the robot in the stack 
        vector<pair<int,int>> result; 
        // store the result in this with their newHealth and actual index => result = {newHealth, originalIdx};

        for(int i = 0; i < n; i++) {
            auto &[pos, currHealth, d, idx] = robots[i];  // current robot 
            if(d == 'R') {
                st.push(i);
                continue;
            }

            // collide the left direction robot with the right robot 
            while(!st.empty() && currHealth > 0) {
                auto &[rPos, rightHealth, r, rIdx] = robots[st.top()];
                if(rightHealth > currHealth) { // right moving robot wins so push this back into the stack with new health
                    rightHealth -= 1;
                    break;
                }
                else if(currHealth > rightHealth) {  // left robot wins 
                    currHealth -= 1;
                    st.pop();
                }
                else {   // have the same health 
                    st.pop();
                    currHealth = 0;
                }
            }

            // left dir robot with positive health and no right dir robots 
            if(st.empty() && currHealth > 0) { 
                result.push_back({currHealth, idx});
            }
        }

        // now add the left over robots in the stack
        while(!st.empty()) {
            auto [pos, health, dir, idx] = robots[st.top()];
            st.pop();
            result.push_back({health, idx});
        }


        // we must sort the result on the basis of the original index
        sort(result.begin(), result.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for(int i = 0; i < result.size(); i++) {
            ans.push_back(result[i].first);
        }

        return ans;
    }
};