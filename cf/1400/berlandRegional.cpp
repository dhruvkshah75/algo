#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1519/C

void solve(int n, vector<pair<int,int>> &stud) {
    // store all the students of a university in a map 
    unordered_map<int,vector<int>> mp;

    for(int i = 0; i < n; i++) {
        auto [university, skill] = stud[i];
        mp[university].push_back(skill);
    }

    // now for each university sort them and take the prefix sum to get the sum in O(1)
    vector<vector<ll>> prefix(n+1);

    for(auto &[university, students]: mp) {
        sort(students.begin(), students.end(), greater<int>());

        // now store the prefix sums of skills for that university 
        vector<ll> pf;
        pf.push_back(0);   
        for(int i = 0; i < students.size(); i++) {
            ll sum = students[i] + pf.back();
            pf.push_back(sum);
        } 

        prefix[university] = pf;
    }
    // O(N*Log(N))

    // now calculate the strength for each value of k 
    vector<ll> ans(n+1, 0);
    // traverse through each university 
    for(int i = 1; i <= n; i++) {
        if(prefix[i].empty()) continue;

        int m = prefix[i].size() - 1;

        for(int k = 1; k <= m; k++) {
            int can_take = (m / k) * k;
            // for each can_take size we take the best skilled students and using prefix get in O(1)
            ans[k] += prefix[i][can_take];
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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
        // n = no of universities (1 to n)

        vector<pair<int,int>> stud(n);

        for(int i = 0; i < n; i++) 
            cin >> stud[i].first;     // student in which university 

        for(int i = 0; i < n; i++)
            cin >> stud[i].second;    // skill of ith student

        solve(n, stud);
    }
}