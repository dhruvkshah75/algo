#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1353/D

struct Segment{
    int x;
    int y;
};

void solve(int n) {

    vector<int> result(n+1, 0);    // 1 based array 

    // we use a max heap to store the longest current segment 
    auto cmp = [&](const Segment &a, const Segment &b) {
        // return true if a has lower priority than a 

        // then return the left subarray 
        if(a.y - a.x + 1 == b.y - b.x + 1) 
            return a.x > b.x;

        return ((a.y - a.x + 1) < (b.y - b.x + 1));
    };

    priority_queue<Segment, vector<Segment>, decltype(cmp)> maxHeap(cmp);
    // we use the max heap to keep the longest segment at the top 

    int ctr = 1;
    maxHeap.push({1, n});

    while(ctr <= n) {
        auto [l, r] = maxHeap.top();
        maxHeap.pop();

        // now push the other two segments created after setting the middle element
        if((r - l + 1) & 1) {
            result[(r + l) / 2] = ctr;
            // check if the new segments are valid or not 
            int mid = (r + l) / 2;

            if(l + 1 <= mid)
                maxHeap.push({l, mid - 1});
            
            if(mid + 1 <= r) 
                maxHeap.push({mid + 1, r});
        }  
        else {
            result[(r + l - 1) / 2] = ctr;
            
            int mid = (r + l - 1) / 2;

            if(l + 1 <= mid) 
                maxHeap.push({l, mid - 1});
            
            if(mid + 1 <= r)
                maxHeap.push({mid + 1, r});
        }
        ctr++;
    }

    // now print the result 
    for(int i = 1; i <= n; i++) 
        cout << result[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
    }
}
