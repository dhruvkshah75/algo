#include<bits/stdc++.h>
using namespace std;

int factorail(int n){
    if(n==0) return 1;
    return n*factorail(n-1);
}

// 1. number of function calls --> n
// 2. What is the complexity of each function --> O(1) + O(1) = O(1)
// 3. overall time complexity is O(1*n) = O(n)

int main(){
    int n;
    cin >> n;
    int fact = factorail(n);
    cout << fact << endl;
}