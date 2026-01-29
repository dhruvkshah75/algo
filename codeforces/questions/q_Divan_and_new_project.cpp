/*
    ********************************************* B. Divan and a New Project ************************************************
                                                time limit per test: 1 second
                                                memory limit per test: 256 megabytes
    The company "Divan's Sofas" is planning to build n+1 different buildings on a coordinate line so that:
    the coordinate of each building is an integer number; no two buildings stand at the same point.
    Let xi be the coordinate of the i-th building. To get from the building i to the building j, Divan spends |xi−xj| minutes, where |y|
    is the absolute value of y.

    All buildings that Divan is going to build can be numbered from 0 to n. The businessman will live in the building 0, 
    the new headquarters of "Divan's Sofas". In the first ten years after construction Divan will visit the i-th building ai times, 
    each time spending 2⋅|x0−xi| minutes for walking.

    Divan asks you to choose the coordinates for all n+1 buildings 
    so that over the next ten years the businessman will spend as little time for walking as possible.

    Input
    Each test contains several test cases. The first line contains one integer number t(1≤t≤103) — the number of test cases.

    The first line of each case contains an integer n(1≤n≤2⋅105) — 
    the number of buildings that "Divan's Sofas" is going to build, apart from the headquarters.

    The second line contains the sequence a1,a2,…,an(0≤ai≤106), where ai is the number of visits to the i-th building.

    It is guaranteed that the sum of n over all test cases does not exceed 2*1e5.

    Output
    For each test case, on the first line print the number T— the minimum time Divan will spend walking.

    On the second line print the sequence x0,x1,…,xn of n+1 integers, where xi(−106≤xi≤106) is the selected coordinate of the i-th building. 
    It can be shown that an optimal answer exists with coordinates not exceeding 1e6.

    If there are multiple answers, print any of them.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        a[0] = -1;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            a[i] = x;
        }
        int sum = 0;
        for(int i=1; i<=n; i++){

        }


    }
}