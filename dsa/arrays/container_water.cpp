// leetcode q link: https://leetcode.com/problems/container-with-most-water/description/

/*
    Algorithm:
        Initialize left and right pointers at array ends. 
        Calculate area as (right - left) * min(height[left], height[right]). 
        Move the shorter pointer inward (left if height[left] < height[right], else right), 
        updating max area until pointers meet.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len - 1;
        int ans = 0;
        while(i <= j){
            // to maximise the temp => area 
            int temp = min(height[j], height[i])*(j - i);
            ans = max(ans, temp);
            if(height[i] < height[j]) i++;
            else if(height[i] > height[j]) j--;
            else {  // when both the heights are same 
                i++;
                j--;
            }
        }

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin >> height[i];
    }

    Solution s = Solution();
    int area = s.maxArea(height);
    cout << area << endl;
}