#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>>&numPair, vector<int>&count, int left, int mid, int right) {
    // here we count the elements smaller than the existing element 
    int j1 = mid + 1;
    for(int i=left; i<=mid; i++) {
        while(j1 <= right && numPair[j1].first >= numPair[i].first) {
            j1++;
        }
        count[numPair[i].second] += (right - j1 + 1);
        // cout << "Count[" << numPair[i].second << "]" << ": " << count[numPair[i].second] << endl; 
    }

    vector<pair<int,int>> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right) {
        if(numPair[i].first > numPair[j].first) temp[k++] = numPair[i++];
        else temp[k++] = numPair[j++];
    }
    // now fill the left out array
    while(i <= mid) temp[k++] = numPair[i++];
    while(j <= right) temp[k++] = numPair[j++];

    for(int i=left; i<=right; i++) numPair[i] = temp[i-left];
}

void mergeSort(vector<pair<int,int>>&numPair, vector<int>&count, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left)/2;
    mergeSort(numPair, count, left, mid);
    mergeSort(numPair, count, mid+1, right);
    merge(numPair, count, left, mid, right);
} 


vector<int> solve(vector<int> &nums){
    int n = nums.size();
    vector<pair<int,int>> numPair(n);
    for(int i=0; i<n; i++) {
        numPair[i] = {nums[i], i};
    }

    vector<int> count(n, 0);
    mergeSort(numPair, count, 0, n-1);

    return count;
}
