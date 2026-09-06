#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/k-closest-points-to-origin/description/

// MEDIUM QUESTION: Very Important question
// Solution using QuickSelect Algorithm: Average Time Complexity O(n)



class Solution {
// first we find the kth closest point to the origin 
// then we traverse through thr array and add all the elements with distance less than the one with with kth one
public:
    int dist(vector<int>&point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    int partition(vector<vector<int>>&points, int left, int right) {
        vector<int> pivot = points[left];  // making the first element i.e, index = left as the pivot
        int i = left, j = right;
        while(i < j) {
            // i: we take all the elements strictly greater than pivot
            while(i < right && dist(points[i]) <= dist(pivot)) i++;
            // j: we take all the elements smaller or equal than the pivot 
            while(j > left && dist(points[j]) > dist(pivot)) j--;
            // we swap the values of i and j if i and j have not crossed paths 
            if(i < j) swap(points[i], points[j]);
        }
        // bring the pivot to the jth postion that is its actual correct postion in the sorted array
        swap(points[j], points[left]);
        // return the partition index 
        return j;
    }

    void quickSelect(vector<vector<int>>&points, int &kth, int left, int right, int k) {
        if(left >= right) return;

        int part = partition(points, left, right);
        if(part == k) {
            kth = part; // or k 
            return;
        }
        // the kth element lies in the right half of the array
        else if(k > part) quickSelect(points, kth, part+1, right, k);
        // kth element lies in the left half of the array
        else quickSelect(points, kth, left, part-1, k);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we are searching for the k-1 index 
        int n = points.size();
        int kth = 0;
        quickSelect(points, kth, 0, n-1, k-1);
        // now we know the kth element closest to the origin 
        return vector<vector<int>>(points.begin(), points.begin() + k);

        // The elements left to the Kth closest element is the ans as these elements are closest to the origin 
        // the order of the elements to the kth element doesnt matter  
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));

    for(int i=0; i<n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution s = Solution();
    vector<vector<int>> ans = s.kClosest(points, k);

    // printing the ans;
    for(int i=0; i<ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }
    cout << endl;
}