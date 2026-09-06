#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-a-peak-element-ii/description/

/*
    Very Important Algorithm:
        we apply binary search on the columns and then we search for the maximum element
        in the mid column so it already bigger than the above and below elements 
        and then check if it is the peak element, 
        if mat[i][mid+1] is greater than mat[i][mid] the ans lies right columns of mat
        if mat[i][mid-1] is greater than mat[i][mid] then the ans lies in the left columns of the mat

        Time Complexity = O(mlog(n)) m => no of rows and n => no of columns 
*/


class Solution {
public:
    int isPeak(vector<vector<int>>&mat, int m, int n, int i, int j) {
        // given i, j check whether mat[i][j] is the peak or not, it is already the max element in its column, we just need to check for j+1 and j-1
        // if mat[i][j+1] is bigger then shift l to j+1 as the peak element is in that column, return 1
        // if mat[i][j-1] is bigger then shift r to j-1 as the peak element is in that column. return -1
        if(j == 0 && j != n-1) {
            if(mat[i][j+1] > mat[i][j]) return 1;
            else return 0;  // element is peak 
        }
        else if(j == n-1) {
            if(mat[i][j-1] > mat[i][j]) return -1;
            else return 0;  // element is peak
        }
        else {
            if(mat[i][j] > mat[i][j+1] && mat[i][j] > mat[i][j-1]) return 0;
            else return (mat[i][j+1] == max(mat[i][j+1], mat[i][j-1])) ? 1 : -1;
        }
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();     // no of rows 
        int n = mat[0].size();  // no of columns 
        vector<int> ans;

        if(m == 1 && n == 1) {
            ans = {0, 0};
            return ans;
        }

        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            // now we find the max element in the column = mid
            int maxElement = INT_MIN;
            int i = 0, j = mid; // stores the index of the max element in the column = mid
            for(int k=0; k<m; k++) {
                if(mat[k][mid] > maxElement) {
                    maxElement = mat[k][mid];
                    i = k;
                }
            }
            // check if this indices are the peak element or not 
            if(isPeak(mat, m, n, i, j) == 0) {
                ans = {i, j};
                return ans;
            }
            else if(isPeak(mat, m, n, i, j) == 1) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};



int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution s = Solution();
    vector<int> ans = s.findPeakGrid(mat);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
}