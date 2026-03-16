#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/2068/C

// Time Complexity: O(N*Log(N))
void solve(vector<int> &ads, int k) {
    int n = ads.size();

    // we must make groups of size 3, 2, 1 => for 3 take the smallest and largest and then the middle one with the condition of k

    // a tree based strcture => very useful here to solve the question 
    multiset<int> ms;

    for(int i = 0; i < n; i++) 
        ms.insert(ads[i]);

    // using multiset is good as it gives bounds and deletes the element and adjusts the structure as well
    int groups = 0;   // the ans will be groups - 1 => as we dont watch ad after the last 

    while(!ms.empty()) {
        groups++;

        // firstly we take the smallest in the set 
        multiset<int>::iterator it = ms.begin();
        int curr = *it;
        ms.erase(it);        // remove the taken element 

        // smallest one is bigger than k then only group of size 1 is allowed 
        if(curr >= k)
            continue;

        // group formed only of size 1 
        if(ms.empty())
            break;

        // take the middle one that does not exceed the sum to k 
        int largest_allowed = k - curr - 1;
        // we take up the prev of upper bound
        multiset<int>::iterator it1 = ms.upper_bound(largest_allowed);

        if(it1!= ms.begin()) {
            auto it = prev(it1);
            // add this in the group and then delete this entry 
            ms.erase(it);
        }
        // if no valid middle then add the last one (empty slot) 

        // now the third one => this is a free slot as curr sum of videos is less than k 
        if(!ms.empty()) {
            multiset<int>::iterator it = prev(ms.end());
            // add the largest and delete it 
            ms.erase(it);
        }
    }

    cout << groups - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> ads(n);

        for(int i=0; i<n; i++)
            cin >> ads[i];

        solve(ads, k);
    }
}