#include<bits/stdc++.h>
using namespace std;
    
// question link: https://leetcode.com/problems/asteroid-collision/description/

/*
    Time Complexity: O(N)
    Algorithm: 
    1. Iterate through the asteroids.
    2. Push positive asteroids() directly onto the stack—they move right and won't hit what's already there.
    3. Handle Negatives(): When a negative asteroid appears, it moves left and "challenges" the stack.
       * While the stack top is positive and smaller than the negative: Pop the stack (it explodes).
       * If it matches the stack top exactly: **Pop** the stack and discard both.
       * If the stack is empty or the top is also negative: **Push** the negative asteroid (it survives).
    4. Result: The survivors stay in the stack. Reverse them at the end to get the final order.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        // we can use stacks => we keep putting the positive elements in stack
        vector<int> ans;
        int i = 0;
        stack<int> st;
        while(i < n) {
            int j = i;
            while(j < n && asteroids[j] > 0) {
                st.push(asteroids[j]);
                j++;
            }
            if(j == n) break;  
            int curr = asteroids[j]; 
            // we pop elements in the stack until the st.top() < abs(asteriods[j]) 
            while(!st.empty() && st.top() > 0 && st.top() < abs(curr)) {
                st.pop();
            }
            if(st.empty() || st.top() < 0) {  
                // if the stack is empty or top is neagtive then we push in stack 
                st.push(curr);   // we store the asteriod in stack 
            }
            else if(st.top() > 0 && st.top() == abs(curr)) {   
                // if the top is equal then both nullify each other  
                st.pop();
            }
            i = j + 1;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> asteroids(n);

    for(int i=0; i<n; i++)
        cin >> asteroids[i];

    Solution s = Solution();

    vector<int> ans = s.asteroidCollision(asteroids);

    for(int a: ans)
        cout << a << " ";
}