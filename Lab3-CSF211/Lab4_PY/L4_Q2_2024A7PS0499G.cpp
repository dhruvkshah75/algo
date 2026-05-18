#include <vector>
using namespace std;

// IMPORTANT Question 

// TTTTTFFFF => find the last occurrence of T
bool canPlaceSheep(int n, int m, vector<pair<int,int>>&farm, int dist) {
    // can we place n cows with at a distance of dist
    // Time Complexity: O(m+n) 
    int ctr = 1;
    int last_pos = farm[0].first;
    for(int i=0; i<m; i++) {
        
        if(farm[i].first - last_pos >= dist) {
            ctr++;
            last_pos = farm[i].first;
        }
        if(farm[i].second - last_pos >= dist) {
            ctr++;  // placed a sheep and now update the last_pos
            last_pos = last_pos + dist;
        }
        // if the interval is large enough then we keep putting the sheep in the interval
        // we check if the next sheep can be placed within the current interval
        while(last_pos + dist <= farm[i].second) {
            ctr++;
            last_pos = last_pos + dist;

            if(ctr >= n) 
                return true;
        }
    }
    return (ctr >= n);
}

int solve(int n, int m, vector<pair<int,int>>&farm) {
    // the farm has m ranges 
    
    int l = 1, r = farm[m-1].second - farm[0].first;
    int ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canPlaceSheep(n, m, farm, mid)) { ans = mid, l = mid + 1; }
        else r = mid - 1;
    }

    return ans;
}
