
/*                                                   EXAMPLE ON PRIORITY QUEUE
*********************************************************** A. Card Exchange **************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
You have a hand of n cards, where each card has a number written on it, and a fixed integer k. You can perform the following operation any number of times:

Choose any k cards from your hand that all have the same number.
Exchange these cards for k−1 cards, each of which can have any number you choose (including the number written on the cards you just exchanged).
Here is one possible sequence of operations for the first example case, which has k=3:

What is the minimum number of cards you can have in your hand at the end of this process?

Input
The first line of the input contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and k (1≤n≤100, 2≤k≤100) — the number of cards you have, and the number of cards you exchange during each operation, respectively.

The next line of each test case contains n integers c1,c2,…cn (1≤ci≤100) — the numbers written on your cards.

Output
For each test case, output a single integer — the minimum number of cards you can have left in your hand after any number of operations

**********************************************************************************************************************************************
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    map<int,int> freq;
    f(i, n){
        cin >> c[i];
        freq[c[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto &x: freq){
        pq.push({x.second, x.first});
    }
    int total = n;
    while(!pq.empty()){
        auto [cnt, val] = pq.top();
        if(cnt < k) break;
        pq.pop();
        int check_cnt = cnt - k;
        if(check_cnt != 0 || pq.empty()){
            pq.push({cnt-1, val});
            total -= 1;
        }
        else if(check_cnt == 0 && !pq.empty()){
            auto [cnt2, val2] = pq.top();
            pq.pop();
            pq.push({cnt2+k-1, val2});
            total -= 1;
        }
    }
    cout << total << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    
}