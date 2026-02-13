#include<bits/stdc++.h>
using namespace std;

// question => Lab3 PYQ 

// simply apply merge sort while merging at every step the ans = max(ans, P[right] - P[left])

void merge(vector<int>&P, int left, int mid, int right, int &ans) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right) {
        if(P[i] < P[j])
            temp[k++] = P[i++];
        else 
            temp[k++] = P[j++];
    }

    while(i <= mid) temp[k++] = P[i++];
    while(j <= right) temp[k++] = P[j++];

    for(int i=left; i<= right; i++) P[i] = temp[i-left];
}

void mergeSort(vector<int>&P, int left, int right, int &ans) {
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(P, left, mid, ans);
    mergeSort(P, mid+1, right, ans);
    // before merging we get the ans => the most important question 
    // (technically for all questions we do manupilations before merging the two sorted arrays)
    ans = max(ans, P[right] - P[left]);
    // after merging the 2 arrays the indexes move around
    merge(P, left, mid, right, ans);
} 

int solve(vector<int>&P) {
    int n = P.size();
    int ans = 0;

    mergeSort(P, 0, n-1, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> P(n);
    for(int i=0; i<n; i++)  
        cin >> P[i];

    int ans = solve(P);
    cout << ans << endl;
}
