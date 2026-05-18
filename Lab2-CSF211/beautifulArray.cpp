#include<bits/stdc++.h>
using namespace std;

// question link: 
// CONFIDENCE BREAKERN FOR A REASON 

class Solution {
public:
    vector<int> beautifulArray(int n) {
        // odd + even = 2*A[k] this is not possible as odd + even is odd 
        // so we do odd + even 
        vector<int> res = {1};
        while(res.size()<n) {
            vector<int> tmp;
            for(int i=0; i < res.size(); i++) {
                if(2 * res[i] - 1 <= n) tmp.push_back(2*res[i] - 1);
            }

            for(int i=0; i<res.size(); i++) {
                if(2 * res[i] <= n) tmp.push_back(2*res[i]);
            }
            res = tmp;
        }
        return res;
    }
};