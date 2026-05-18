#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/371/C
// 1600 Codeforces question 

// can i make x burgers from what i have 
bool canMakeBurgers(long long x, unordered_map<char,int>&cnt, int nb, int ns, int nc, int pb, int ps, int pc, long long r) {
    // calculate how many ingrediants i want and then check if i can i buy it or not 
    // instead of checking how many can i make 
    long long bread_needed = cnt['B'] * x - nb;
    long long sausage_needed = cnt['S'] * x - ns;
    long long cheese_needed = cnt['C'] * x - nc;

    int ctr = 0;

    // was polycarpus able to make x burgers using r amount  
    if(bread_needed < 0) ctr++;
    else if(pb * bread_needed <= r) {
        ctr++;
        r -= pb * bread_needed;
    }

    if(sausage_needed < 0) ctr++;
    else if(ps * sausage_needed <= r) {
        ctr++;
        r -= ps * sausage_needed;
    }

    if(cheese_needed < 0) ctr++;
    else if(pc * cheese_needed <= r) {
        ctr++;
        r -= pc * cheese_needed;
    }

    return (ctr == 3);   // return true if we can make hamburgers 
}


void solve() {
    string str;
    cin >> str;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    unordered_map<char,int> cnt;
    for(int i=0; i<str.length(); i++) 
        cnt[str[i]]++;

    // we can apply binary search on the ans that is how many hamburgers can be made 
    // predicate function returns TTTTTTFFFFF => return the first occurrence of T
    long long ans = 0;
    long long low = 0, high = 1e12 + 300;    // when everything is priced 1 then he can buy 1e12 + 300 burgers (300 because of his own stock )
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(canMakeBurgers(mid, cnt, nb, ns, nc, pb, ps, pc, r)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ans << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}