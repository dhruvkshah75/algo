#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/contest/1795/problem/C

/*
    Visualization of diff vs extraImagine Tea 0 has volume 25 and tasters have capacities b = [10, 10, 10, 10].
    Binary Search: It finds that Tea 0 can fully satisfy Taster 0 and Taster 
    1.  It runs out at Taster 
    2.  diff (The Full Sips): We mark diff[0]++ and diff[2]--. When we process the final answer, 
        Taster 0 and Taster 1 will see they have 1 full tea waiting for them. 
        They drink their full b[i] (10 each).
    3.  extra (The Leftover): Taster 2 is the "stopping point." 
        They don't get a full sip.Tea 0 volume: 25.Amount drunk by Tasters 0 and 1: 10 + 10 = 20.
        Leftover: 25 - 20 = 5.We store extra[2] += 5.
*/

void solve(vector<int>&a, vector<int>&b) {
    int n = a.size();

    // calculate the prefix sum of b => the tea taster capacity 
    vector<long long> prefix(n + 1, 0);

    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + b[i] * 1LL;
    }

    // now for each tea we get the upper bound => i.e. how many tea tasters will be able to drink it 
    vector<long long> diff(n + 1, 0), extra(n + 1, 0);

    for(int i = 0; i < n; i++) {
        // the tea to be tasted is a[i] + prefix[i] as we want to taste from ith to (n-i)ith 
        auto it = upper_bound(prefix.begin(), prefix.end(), a[i] + prefix[i]);
        int j = distance(prefix.begin(), it) - 1;

        // all the tasters before this drink to their full capacity 
        if(i < j) {
            diff[i] += 1;
            diff[j] -= 1;
        }

        // if there is Taster j then it drink to its partial capacity 
        if(j < n) {
            long long consumed_before = prefix[j] - prefix[i];
            extra[j] += (a[i] - consumed_before);
        }     
    }

    // now final calculation for each taster 
    long long curr_full = 0;

    for(int i = 0; i < n; i++) {
        curr_full += diff[i]; 
        // total by taster[i] is no of full teas * capacity + extra partial drink 
        long long ans = (curr_full * b[i]) + extra[i];
        cout << ans << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        solve(a, b);
    }
}