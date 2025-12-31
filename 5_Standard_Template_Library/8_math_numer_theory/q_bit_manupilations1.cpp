
/*
Problem
Monk loves cycling. He wants to buy his favorite bicycle costing P dollars. 
But his father won’t give him the money so easily as he wants Monk to understand the importance of money. So they made a deal.
Monk starts with Zero dollars in his piggybank. On each day, Monk will go to another city where God of Money lives, and will get as much as dollars he wants from him.

At the end of each day, Monk brings the piggybank to his father, who counts the money in the piggybank and deposits as much more money as the amount that is present in the piggybank, 
which eventually doubles the amount in piggybank. As a result, the money in the piggybank keeps growing. 
Note that, his father does not deposit any money if the piggybank is empty.
Monk wants to ask God of Money for as minimum dollars as possible. 
Find the minimum dollars that Monk has to ask from God of Money, so that he has exactly P dollars in his piggybank, 
irrespective of the number of days he takes.

Input:
The first line consists of integer T. T testcases follow. The first line of each testcase consists of an integer P, denoting the cost of the bicycle.

Output:
For each testcase, print the answer in a single line.

Constraints:
1 <= T <= 10;
1 <= P <= 1e18;

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve(){
    ll p;
    cin >> p;
    /*
        on first day he takes x1 amount from god father makes it to 2x1 
        on the next day he takes x2 amount from god -->> 2x1 + x2 and father makes it 2^2x1 + 2x2
        so this will be 
        total money == 2^n*x1 + 2^n-1*x2 + .... + 2^2*xn-1 + 2xn;
        amount taken from god -->> x1 + x2 + x3 + .. + xn -->> to minimize this xi will take values 0 or 1 
        // to form the the number exactly u would have to contantly take money from god it will be either 0 or 1 on that particular day 
        ans == set bits in the number 
    */
   int ans = __builtin_popcountll(p);
   cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
}