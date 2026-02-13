#include <bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/contest/1701/problem/C


// predicate function returns FFFFFTTTTTTT => find the first occurence of T
bool canCompleteTask(vector<int> &a, int n, int x, vector<int>&count) {
    int m = a.size();  // no of tasks 

    // can we finish m tasks within x hours ?
    // we check the load for each worker and then see if he can help other workers or if he needs help from other workers 
    long long surplus = 0;
    long long deficit = 0;
    // tarversing through the count array r
    for(int i=1; i<=n; i++) {
        // case 1: worker has more time than the total tasks he is profecient in 
        // this means that the worker has extra time and he can take up other tasks but will take 2 hours to complete 
        if(count[i] < x) {
            surplus += 1LL*((x - count[i]) / 2);
        }
        // case 2: worker is proficent in more than x tasks, that is he need some help from other workers to complete in 2 hours 
        else {
            deficit += 1LL * (count[i] - x);
        }
    }

    return surplus >= deficit;
}


void solve(){
   int n, m;
   cin >> n >> m;
   vector<int> a(m);
   
    for(int i=0; i<m; i++) 
        cin >> a[i];

    // count stores the ith worker is profecient in how many tasks 
    vector<int> count(n+1, 0);
    for(int i=0; i<m; i++) {
        count[a[i]]++;
    }

    // apply binary search on the time taken to complete the task 
    int l = 1, r = 2*m;    // max when a single worker does all the task he is not profecient in 
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canCompleteTask(a, n, mid, count)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}