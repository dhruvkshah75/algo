#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1506/D

void solve(vector<int>&a) {
    int n = a.size();

    // we store all the frequencies of elements in the map 
    unordered_map<int,int> cnt;

    for(int i=0; i<n; i++)
        cnt[a[i]]++;

    // now we push all the unique elements in the max heap 
    auto cmp = [&](const int &a, const int &b) {
        // return true if `a` has less priority than `b`
        return cnt[a] < cnt[b];
    };

    priority_queue<int, vector<int>, decltype(cmp)> maxHeap(cmp);

    // populate the max heap 
    for(auto &[num, count]: cnt) {
        maxHeap.push(num);
    }

    // greedy approach is to pair those two elements which have the most count 
    // now the element with the max count is at the top 
    while(!maxHeap.empty()) {
        int x1 = maxHeap.top();
        maxHeap.pop();

        if(maxHeap.empty()) {
            // if second unique element is not present then repush x1 and then break
            maxHeap.push(x1);
            break;
        }

        int x2 = maxHeap.top(); 
        maxHeap.pop();

        // decrease their count 
        cnt[x1] -= 1;
        cnt[x2] -= 1;

        // if the count becomes 0 then wont push that one 
        if(cnt[x1] == 0 && cnt[x2] == 0) 
            continue;
        else if(cnt[x1] == 0)
            maxHeap.push(x2);
        else if(cnt[x2] == 0)
            maxHeap.push(x1);
        else {
            // push both => as neither of their count is 0
            maxHeap.push(x1);
            maxHeap.push(x2);
        }
    }

    int result = 0;
    // either the heap is empty or it has 1 element in it 
    if(maxHeap.empty())
        cout << 0 << endl;
    else 
        cout << cnt[maxHeap.top()] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);

        for(int i=0; i<n; i++) 
            cin >> a[i];

        solve(a);
    }
}