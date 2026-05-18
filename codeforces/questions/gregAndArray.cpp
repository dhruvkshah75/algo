#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/295/A

struct Query {
    int l;
    int r;
    int d;
};

struct Operation {
    int x;
    int y;
};

void solve(vector<Query> &queries, vector<long long> &arr, vector<Operation> &op) {
    // we must first find out how many times a query is applied 

    // all arrays 1 based indexing 
    int q = queries.size(), n = arr.size(), k = op.size();

    // first we make a array that stores how many times the ith query is applied 
    vector<long long> diff(q + 1, 0);

    for(int i = 1; i < k; i++) {
        auto [x, y] = op[i];
        diff[x] += 1;
        diff[y + 1] -= 1;
    }

    // take the prefix sum of the diff1 array => diff1[i] holds how many times is the ith query applied 
        cerr << "Printing the diff: ";

    for(int i = 1; i < q; i++) {
        diff[i] = diff[i - 1] + diff[i];
        cerr << diff[i] << " ";
    }
    cerr << endl;

    vector<long long> diff2(n + 2, 0);


    // now update the arr stores the result after each query 
    // traverse through the queries => and apply the ith query diff[i] times 
    for(int i = 1; i < q; i++) {
        auto [l, r, d] = queries[i];
        diff2[l] += d * diff[i];
        diff2[r+1] -= d * diff[i];
    }

    // now take the prefix sum of the arr and print the elements 

    for(int i = 1; i < n; i++) {
        diff2[i] = diff2[i-1] + diff2[i];
        cout << arr[i] + diff2[i] << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n + 1, 0);

    for(int i = 1; i <= n; i++)
        cin >> arr[i];


    vector<Query> queries(m + 1);

    for(int i = 1; i <= m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        queries[i] = {l, r, d};
    }

    vector<Operation> op(k + 1);
    
    for(int i = 1; i <= k; i++)
        cin >> op[i].x >> op[i].y;

    
    solve(queries, arr, op);
}