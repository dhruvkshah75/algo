// *************************************** EKO - EKO ***********************************
/*
Lumberjack Mirko needs to chop down M metres of wood. 
It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. 
However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), 
and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H 
(of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. 
For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, 
and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
That‟s why he wants to set his sawblade as high as possible. 
Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) 
and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, 
the heights of each tree (in metres). The sum of all heights will exceed M, 
thus Mirko will always be able to obtain the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example
Input:
4 7
20 15 10 17
Output:
15

Input:
5 20
4 42 40 26 46
Output:
36

*/

// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
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
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}


// done with the help of a predicate function 
// predicate function is the one which gives true or false
// apply binary search on monotonuc predicate functions
// eg TTTTTTFFFFFF or FFFFFTTTT

/*
    try to form a predicate function such as F F F T T T T then apply a binary search to find the first true.
    if i get the mid as false then my answer will lie to the right wrt to this function and if i get mid as T 
    then it could be that element or to the left
    notes: 
    in this question the predicate function is func(h) that if i cut from height h then is total_wood>=h or not
    start cutting the tree from 0 height then so on by increasing by some amount x so u will get series of T and F
    so using binary search find the last true;
    sorting or setting r as the max value in the array is not prefferable as array size is too big
*/
const int N = 1e6+10;
int n;
ll m;
ll t[N];    // the max size of n is 1e6 declare the array globally.

bool isWoodSufficient(ll h){
    ll wood = 0;
    for(int i=0; i<n; i++){
        if(t[i] >= h){
            wood += t[i]-h;
        }
    }
    if(wood >= m) return true;
    return false;
}

void solve(){

    cin >> n >> m;
    ll total = 0;
    fc(i, n, t);

    ll l = 0, r = 1e9, mid;
    // T T T T T F F F F -->> find 
    while(r-l>1){
        mid = (l+r)/2;
        if(isWoodSufficient(mid)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    // since r is always more than l so first check r is true or not
    if(isWoodSufficient(r)){
        cout << r << endl;
        return;
    }
    else{
        cout << l << endl;
        return;
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}