/*
    Problem  -->> can use sieve algorithm concept
    Here is another task for you, prepared by Monk himself. So, this is how it goes :

    Given an integer array A of size N, Monk needs you to answer T queries for him. 
    In each query, he gives you 2 integers P and Q. In response to each of these queries, you need to tell Monk the count of numbers in array A. 
    that are either divisible by P, Q, or both.
    The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers, where the 
    integer denotes.

    Input format:
    The next line contains a single integer T denoting the number of queries Monk poses to you. 
    Each of the next T lines contains 2 space separated integers P and Q.

    Output Format:
    For each query, print the answer on a new line.
    N, a[i], T, P, Q <= 2*1e5

    Sample input:
    6
    2 3 5 7 4 9
    2
    4 5
    3 7

    Sample Output:
    2
    3
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
int lcm(int a, int b){
    return (int)((a*1LL*b)/__gcd(a, b));
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> freq;  
    unordered_map<int,int> index;   // stores the index of each element where element is the key
    fx(i, n, 0){
        cin >> a[i];
        freq[a[i]]++;
        index[a[i]] = i;
    }
    int max = *max_element(all(a));
    // based on sieve logic 
    vector<int> cnt(n); // -->> stores the cnt of multiples of that element in the array wrt to the index; 
    for(int i=0; i<n; i++){
        for(int j=a[i]; j<=max; j+=a[i]){
            if(freq.count(j)){
                cnt[i] += freq[j];
            }
        }
    }
    // O(NLog(N));
    int t; // t queries
    cin >> t;
    while(t--){
        int p, q;
        cin >> p >> q;
        auto it_p = index.find(p);
        auto it_q = index.find(q);
        if(index.count(lcm(p, q))){
            auto it_lcm = index.find(lcm(p, q));
            cout << cnt[it_p->second] + cnt[it_q->second] - cnt[it_lcm->second] << endl;
        }
        else{
            cout << cnt[it_p->second] + cnt[it_q->second] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}