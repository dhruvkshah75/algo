// ********************************** Monk and the magical candy bags ********************************

/*  
    our monk loves candy!
    while taking a stroll in the park, he stumbled upon N bags with candies. The ith of these contains Ai candies.
    
    He picks up a bag, eats all the candies in it and drops it on the groud. But as soon as he drops the bag, the number of candies
    in the bag increases magically! Say the bag that used to contain X candies (before eating) now contains [X/2] candies! where [x] 
    is gif(greatest integer function). Amazed by the magical spell, Monk can now have a lot more candies! But he has return home in 
    K minutes. In a single minute, Monk can consume all the candies in a single bag, regardless of the number in it
    Find the maximum number of candies that Monk can consume.

    INPUT: 
    first line contains an integer T t-> test cases
    first line of each test case contains integers N and K.
    Second line of each test case contains N integers, the number of camdies in the bags. 

    OUTPUT: 
    Print the answer to each test case in a new line.

    Constraints:
    1 <= T <= 10;
    1 <= N <= 1e5;
    0 <= K <= 1e5;
    0 <= Ai <= 1e10;

// *************************************************************************************************************************************
*/

// since he is able to eat a bag in 1 min so in K minutes he can eat K bags 

//  so he will choose the bag with max cndies and eat it even after that magic

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        multiset<ll> cnd;
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            cnd.insert(x);
        }
        long long ans=0;
        while(k--){
            auto it = (--cnd.end());
            ll x = *it;
            cnd.erase(it);           // erase is O(1) if we use iterator as the parameter but O(log(n)) if we use value
            ans += (x);
            cnd.insert(floor(x/2)); 
        }
        cout << ans << endl;
    }

}