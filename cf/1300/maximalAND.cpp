#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve(int n, int k, vector<int> &arr) {
    // firstly if we have more than n operations then we set the max bit of all to 1 to make the AND max 
    // we can set the bit 0 to bit 30 => O(31) per number 

    int ops = k / n;

    for(int i = 0; i < ops; i++) {
        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(n, k, arr);
    }
}