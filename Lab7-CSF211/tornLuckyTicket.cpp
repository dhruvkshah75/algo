#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1895/C
// VERY IMPORTANT Question on Hashing 


int sumLeft(string &str, int la, int mid) {
    int currentSum = 0;
    // calculate the sum of the provided string 
    for(int i = 0; i < la; i++) {
        if(i < mid) currentSum += (str[i] - '0');
        else currentSum -= (str[i] - '0');
    }

    return currentSum;
}

int sumRight(string  &str, int la, int lb, int mid) {
    int currentSum = 0;
    // calcualte the negatiive sum for right half of the si+sj 
    for(int i = 0; i < lb; i++) {
        if(la + i < mid) currentSum += (str[i] - '0');
        else currentSum -= (str[i] - '0');
    }

    return currentSum;
}

void solve(vector<string> &tickets) {
    int n = tickets.size();

    // we calculate for all possible length 
    vector<pair<int,int>> possibleLen = {
        {1, 1}, {1, 3}, {1, 5}, {2, 2}, {2, 4},
        {3, 1}, {3, 3}, {3, 5}, {4, 2}, {4, 4},
        {5, 1}, {5, 3}, {5, 5}
    };

    long long result = 0;

    for(auto &[la, lb]: possibleLen) {
        int mid = (la + lb) / 2;
        unordered_map<int,int> left;
        // now populate the left map 
        for(string &str: tickets) {
            if(str.length() == la) {
                int sum = sumLeft(str, la, mid);
                left[sum]++;
            }
        }

        unordered_map<int,int> right;
        // populate the the right map with sum of right half strings of length lb 
        for(string &str: tickets) {
            if(str.length() == lb) {
                // here the sum will be negative 
                int sum = sumRight(str, la, lb, mid);
                right[sum]++;
            }
        }

        // now we find how many pairs are possible 
        for(auto &[leftSum, cnt1]: left) {
            if(right.find(-leftSum) != right.end()) {
                int cnt2 = right[-leftSum];
                result += cnt1 * 1LL * cnt2;
            }
        }
    }

    cout << result << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> tickets(n);

    for(int i = 0; i < n; i++) 
        cin >> tickets[i];

    solve(tickets);
}