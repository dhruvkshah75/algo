// VERY IMPORTANT Question 
#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/the-skyline-problem/description/
// LEETCODE HARD: Based on Merge Sort (Divide and Conquer)

class Solution {
    vector<vector<int>> mergeTwoSkylines(vector<vector<int>>&left, vector<vector<int>>&right) {
        vector<vector<int>> result;
        int i = 0, j = 0;   // the two pointers for left and right skylines 
        int h1 = 0, h2 = 0; 
        // we maintain the current heights of the left and right as while going to the next  we need the previous heights

        while(i < left.size() && j < right.size()) {
            int p1, p2;   // => this is what we will insert into the result depending on some cases 
            // case1: when left x coord < right x coord 
            if(left[i][0] < right[j][0]) {
                // we have to put {p1, ..} => .. is the height that we are supposed to put
                p1 = left[i][0];
                h1 = left[i][1];  // => since we are adding the left point to the ans we update the current height h1
                p2 = max(h1, h2);
                i++;
            }
            // case 2: when the right x coord < left x coord 
            else if(left[i][0] > right[j][0]) {
                p1 = right[j][0];
                h2 = right[j][1];  // since we are on the right skyline then update the curr right height h2
                p2 = max(h1, h2);  
                j++;
            }
            // case 3: when left x coord = right x coord
            else {
                p1 = left[i][0];
                h1 = left[i][1];   // since both are at the same x coord then we move past both of them
                h2 = right[j][1];  // so we update the left and right current height 
                p2 = max(h1, h2);
                i++;
                j++;
            }

            // add the {p1, p2} only if the previous elements p2 is not same or if {p1, p2} is the first element
            if(result.empty() || result.back()[1] != p2) {
                result.push_back({p1, p2});
            }
        }

        // Append remaining points from either side, standard merge case as either left or right one may get exhausted 
        while (i < left.size()) result.push_back(left[i++]);
        while (j < right.size()) result.push_back(right[j++]);

        return result;
    }

    vector<vector<int>> mergeSort(vector<vector<int>>&buildings, int left, int right) {
        if(left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
            // when only one skyline is there return it points 
        }
        int mid = left + (right - left) / 2;
        vector<vector<int>> leftSkyline = mergeSort(buildings, left, mid);
        vector<vector<int>> rightSkyline = mergeSort(buildings, mid+1, right);
        // now we merge the left and the right skylines 
        return mergeTwoSkylines(leftSkyline, rightSkyline);
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();

        return mergeSort(buildings, 0, n-1);
    }

};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> buildings(n);

    for(int i=0; i<n; i++)
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];

    Solution s = Solution();

    vector<vector<int>> ans = s.getSkyline(buildings);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}