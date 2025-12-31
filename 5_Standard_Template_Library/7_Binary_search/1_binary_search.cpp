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

void solve(){
    // binary search applies on a monotonic function

    /*
        monotonic functions are those which maintain a order
        eg 1 2 3 4 5 is a increasing array so it will be monotonic if its always or decreasing
        eg 6 5 4 3 2 is monotonic as all the elements are decreasing // should follow a order
    */

    int n;
    cin >> n;
    vector<int> v(n);
    f(i, n){
        cin >> v[i];
    }                    
    // array is sorted in ascending order;

    // eg array is 2 3 4 5 6 7    -->> to_find is 5

    int to_find;
    cin >> to_find;
    // binary search occurs till low is equal to high
    // this is two pointer technique;
    int l = 0, r = n-1;
    int mid;
    while(r - l > 1){          // stops when high - low equals 1
        int mid = (l+r)/2;
        if(v[mid] < to_find){
            l = mid+1;
        }
        else if(v[mid] >= to_find){
            r = mid;
        }
    }
    if(v[l] == to_find) cout << l << endl;
    else if(v[r] == to_find) cout << r << endl;
    else cout << "not found" << endl;

    // after every step search space reduces by half 
    // time complexity is O(Log(n));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}