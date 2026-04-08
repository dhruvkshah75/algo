#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1610/C
// Binary Search on answer => Important Question

// can we invite k friends 
bool canInvite(int k, int n, vector<pair<int,int>> &friends) {
    int count = 0;

    for(int i = 1; i <= n; i++) {
        // curr person = ith person 
        // Person i is the (count + 1)-th person we are inviting => richer than count people already invited 

        int richerPeople = k - 1 - count;
        int poorPeople = count;

        if(richerPeople <= friends[i].first && poorPeople <= friends[i].second) 
            count++;
    }

    return count >= k;
}

void solve(int n, vector<pair<int,int>> &friends) {
    // there are n people at a party 
    int result = 1; 

    // predicate function returns TTTTTTFFFFF => find the last occurrence of T (max friends can be invited)
    int l = 1, r = n;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canInvite(mid, n, friends)) {
            l = mid + 1;
            result = mid;
        }
        else r = mid - 1;
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> friends(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> friends[i].first >> friends[i].second;
        }

        solve(n, friends);
    }
}