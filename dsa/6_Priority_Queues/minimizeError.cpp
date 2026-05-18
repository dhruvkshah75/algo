#include<bits/stdc++.h>
using namespace std;


// question link: https://codeforces.com/problemset/problem/960/B
// Important usage of max_heap => greedy solution 

void solve(vector<int>&a, vector<int>&b, int k) {
    // we take all the abs differences and then store in the max_heap and then we can deal with it 
    // k1+k2 <= 1e3 ==> so not a big issue 

    priority_queue<int> max_heap;

    // populate the heap 
    for(int i=0; i<a.size(); i++) {
        max_heap.push(abs(a[i] - b[i]));
    }

    // heap contains only positives and 0 => but we are supposed to push exactly k1+k2 operations
    // keep subtracting the top by 1 and until 1 and then push it again 
    while(k > 0) {
        int top = max_heap.top();
        max_heap.pop();
       
        // push abs of top - 1 => if the no becomes neg we make it pos as the error is squared 
        max_heap.push(abs(top - 1));
        k--; 
    }

    long long error = 0;
    while(max_heap.size() > 0) {
        int top = max_heap.top();
        max_heap.pop();
        // add to the result
        error += top * 1LL * top;
    }

    cout << error << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
        cin >> b[i];

    solve(a, b, k1 + k2);
}