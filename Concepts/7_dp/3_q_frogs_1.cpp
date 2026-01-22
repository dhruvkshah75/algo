
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;

// question:

/*
    Problem Statement
    There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.
    There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
    If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi−hj∣ is incurred, 
    where j is the stone to land on.Find the minimum possible total cost incurred before the frog reaches Stone N.

    Constraints
    All values in input are integers. 2 ≤ N ≤ 1e5
    1 ≤ hi ≤ 1e4 ​

    Output
    Print the minimum possible total cost incurred.
*/

// Solution begins here: 

/*
        1 2 3 4 5 6  -->> to reach 6 find the min coset M1 to reach 4 and then min cost to reach 5 is M2
        then find 
        |h6 - h4| for going from 4-->> 6 
        |h6 - h5| for going from 5 -->> 6 
        doing this for each step using recursive
*/

const int N = 1e5+10;
vector<int> h(N);
int dp[N];  // store the minimum cost to reach that stone 

int func(int i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    // way 1
    cost = min(cost, func(i-1) + abs(h[i]-h[i-1]));
    // way 2
    if(i > 1)
        cost = min(cost, func(i-2) + abs(h[i]-h[i-2]));

    return dp[i] = cost; 
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    fx(i, n, 0){
        cin >> h[i];
    }
    cout << func(n-1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}