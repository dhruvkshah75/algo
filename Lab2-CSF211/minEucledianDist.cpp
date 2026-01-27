#include<bits/stdc++.h>
using namespace std;

// can we apply merge sort by breaking them into small parts 
// MINIMUM EUCLEDIAN DISTANCE 

class Solution{
    void merge(vector<vector<int>>&points, int left, int mid, int right, int &ans) {
        // here we apply the logic of calculating the min dist
        for(int i=left; i<=mid; i++) {
            
        }
    }

    void mergeSort(vector<vector<int>>&points, int left, int right, int &ans) {
        if(left >= right) return;
        int mid = left + (right - left)/2;
        mergeSort(points, left, mid, ans);
        mergeSort(points, mid+1, right, ans);
        merge(points, left, mid, right, ans);
    }

    int minDistance(vector<vector<int>>&points) {
        int n = points.size();
        int ans = 0; // the d^2 distance squared 
        mergeSort(points, 0, n-1, ans);

        return ans;
    }
};

int main() {

}