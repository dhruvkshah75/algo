
#include <bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

// Algorithm: Solve like moving down a staircase by starting at the top right corner 
// If the current element is larger than the target then it cannot be in that column as the column is sorted in ascending order 
// Then we go the next column by col-- 
// if the current element is smaller than target then it must lie in the nect row so we do row++;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // start from the top right corner => 
        // makes more sense as we will have the biggest element of the current row 
        int row = 0, col = n - 1;
        while (col >= 0 && row < m) {
            if (matrix[row][col] == target) 
                return true;
            // If current element is greater than target, target cannot be in this column (move left)
            else if (matrix[row][col] > target) 
                col--;
            // If current element is smaller than target, the target cannot be in this row (move down)
            else 
                row++;
        }
        return false;
    }
};

// Time-Complexity O(m + n)  => better than O(m*Log(n))

