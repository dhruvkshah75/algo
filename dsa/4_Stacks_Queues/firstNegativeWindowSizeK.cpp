#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// important question on queues 

/*
    We use queues as we want the first indices 
    We maintain a queue for putting negative elements => not all elements 
*/

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> ans;
        queue<int> q;  

        // at every pass of the array we maintain a window of size k 
        for(int i=0; i<k; i++) {
            if(arr[i] < 0) q.push(i);
        }
        // first we prepopulate the queue 

        // we first store the result of the first window 
        if(!q.empty()) ans.push_back(arr[q.front()]);
        else ans.push_back(0);

        // window i - k + 1 to i
        for(int i=k; i<n; i++) {
            // pop that are not in the window  
            // when i go from i-1 to i => window shifts throwing out the i-k indexed element
            while(!q.empty() && q.front() <= (i - k)) {
                q.pop();
            }
            // now push a new element if negative into the waiting room
            if(arr[i] < 0)
                q.push(i);

            if(!q.empty()) 
                ans.push_back(arr[q.front()]);
            else 
                ans.push_back(0);
        }

        return ans;
    }
};