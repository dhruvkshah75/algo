#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long solve(int n, int m, vector<long long>& a) {
    long long operations = 0;
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    priority_queue<long long> max_heap;
    for (int i = m - 1; i >= 1; i--) {
        max_heap.push(a[i - 1]);
        
        while (!max_heap.empty() && prefix[i] < prefix[m]) {
            long long max_element = max_heap.top();
            max_heap.pop();
            prefix[m] -= max_element;
            operations++;
        }
    }
    
    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    for (int i = m + 1; i <= n; i++) {
        min_heap.push(a[i - 1]);
        
        while (!min_heap.empty() && prefix[i] < prefix[m]) {
            long long min_element = min_heap.top();
            min_heap.pop();
            prefix[i] += min_element;
            operations++;
        }
    }
    
    return operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << solve(n, m, a) << endl;
    }
    
    return 0;
}