 
/*
    apple -->> 0
    banana -->> 1
    orange -->> 2
    lichi -->> 3
    // find the common fruits among two people
    person 1 -->> 2, 3  ---->> 1100 is the bitmask representation of this by making 2nd and 3rd bit as set
    person 2 -->> 0, 1, 2  -->>  0111 is the bitmask representation 
    person 3 -->> 1, 3   -->> 1010 is the bitmask representation 
    to find intersection take and  
*/

#include<bits/stdc++.h>
using namespace std;

/*
    there are N <= 5000 workers. Each worker is available during some days of this month(which is 30 days). For each worker u are given a set 
    of numbers, each from the interval [1, 30], representing his/her availabilty. you need to assign an important project to two workers but 
    they will be able to work on the project only when they are both available. Find two workers which are best for this job - maximize 
    the number of days when both the workers are available 
    --->> question on bitmasks
    // we can use __builtin_popcount(x[i] & x[j]);
    input format:
    5
    4
    1 4 7 9
    6
    2 9 1 7 25 29
    7
    1 23 4 7 25 29
    10
    2 28 8 7 9 10 30 21 18 19
    4
    1 11 29 7

*/

void solve(){
    int n;
    cin >> n;
    vector<int> masks(n, 0);
    for(int i=0; i<n; i++){
        int num_days;
        cin >> num_days;
        int mask = 0;
        for(int j=0; j<num_days; j++){
            int day;
            cin >> day;
            mask = (mask | (1 << day));   // to make that bit set
        }
        masks[i] = mask;
    }
    int max_days = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int common_days = __builtin_popcount(masks[i] & masks[j]);
            max_days = max(max_days, common_days);
        }
    }
    cout << max_days << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}