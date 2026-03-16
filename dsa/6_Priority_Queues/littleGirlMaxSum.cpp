#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/276/C

struct Query {
    int left;
    int right;
};

void solve(vector<int> &arr, vector<Query>& queries) {
    int n = arr.size(), q = queries.size();

    // The main intution of the question is to get which index is covered the most times and then place the max there 
    // since this question is based on queries with l and r we use diff arr to store the frequency of how many times each index or location comes in the range 

    vector<long long> diff(n + 2, 0);

    for(int i = 0; i < q; i++) {
        // diff[l] += 1 and diff[r] -= 1 => and then take prefix sum to know each index appears in how many queries 
        auto &[l, r] = queries[i];
        diff[l] += 1;
        diff[r + 1] -= 1; 
    }


    // now we take the prefix sum of the difference array 
    for(int i = 1; i <= n; i++) {
        // make it 1 based 
        diff[i] = diff[i-1] + diff[i]; 
    }

    // now we must pair each max element with the index with the most occurrence in the diff array 
    
    sort(diff.begin() + 1 , diff.begin() + n + 1, greater<long long>());   // sort only from diff[1:n] => 1 based part 
    sort(arr.begin(), arr.end(), greater<int>());

    long long result = 0;

    for(int i = 0; i < n; i++) {
        result += diff[i+1] * 1LL * arr[i]; 
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<Query> queries(q);

    for(int i = 0; i < q; i++) 
        cin >> queries[i].left >> queries[i].right;

    solve(arr, queries);

}