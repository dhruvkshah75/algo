
/*        SUBSET GENERATION on LEETCODE (MEDIUM)

    ex input nums = [1, 2, 3]
    output = [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3];
    input: nums = [0]
    output = [], [0];

*/

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

vector<vector<int>> ans;
// best way to create is to include that no or not and then do recursive call

void generate(vector<int> &subset, int i, vector<int> &nums){
    // for n elements there 2^n subsets
    if(i==nums.size()){  // stop when i goes out of range i.e. becomes equal to n
        ans.push_back(subset);
        return;
    }
    // ith element is not in the subset
    generate(subset, i+1, nums);

    //ith element in the subset
    subset.push_back(nums[i]);
    generate(subset, i+1, nums);
    subset.pop_back();
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> empty;
    generate(empty, 0, nums);

    for(auto &subset: ans){
        for(auto &ele: subset){
            cout << ele << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}