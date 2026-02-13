#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& ends, long long &ans, int left, int mid, int right) {

    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    // calculate the inversions while merging 
    while (i <= mid && j <= right) {
        if (ends[i] <= ends[j]) 
            temp[k++] = ends[i++];
        else {
            // ends[i] > ends[j], so ends[j] is smaller than everything from index i to mid.
            ans += (mid - i + 1); 
            temp[k++] = ends[j++];
        }
    }

    while(i <= mid) temp[k++] = ends[i++];
    while(j <= right) temp[k++] = ends[j++];

    for (int i = left; i <= right; i++) 
        ends[i] = temp[i-left];
}

void mergeSort(vector<int>&ends, long long &ans, int left, int right) {
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(ends, ans, left, mid);
    mergeSort(ends, ans, mid+1, right);
    merge(ends, ans, left, mid, right);
}

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> people(n);
    for(int i=0; i<n; i++)
        cin >> people[i].first >> people[i].second;

    sort(people.begin(), people.end());
    // sort them on the basis of their x coordinate 

    // i and j will greet each other when j is completely inclused in i or either way around 
    // by sorting we make sure that ai < aj, now find inversions on basis of bj < bi
    vector<int> ends(n);
    for(int i=0; i<n; i++)
        ends[i] = people[i].second;

    long long ans = 0;

    mergeSort(ends, ans, 0, n-1);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}