#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/contest/1526/problem/C2

void solve(int n, vector<int>&potions) {
    int no_of_drinks = n;

    // store the neg drinks in the min heap 
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // we drink all the drinks and then if health falls bellow 9 then we undrink the one with that has most neg value 
    // for the most negative value we use min heap 
    
    long long health = 0;

    for(int potion: potions) {
        health += (long long)potion; 
        // store the negative drink 
        if(potion < 0) {
            min_heap.push(potion);
        }

        if(health < 0) {
            // undrink the drinks untill health becomes positive 
            while(min_heap.size() > 0 && health < 0) {
                no_of_drinks--;
                // after undrinking the drink update the health 
                health += abs(min_heap.top());
                min_heap.pop();
            }
        }
    }

    cout << no_of_drinks << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> potions(n);

    for(int i=0; i<n; i++)
        cin >> potions[i];

    solve(n, potions);
}