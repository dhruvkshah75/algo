// link to the question on leetcode https://leetcode.com/problems/next-permutation/description/
// Medium - Arrays


#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &nums){
    cout << "Printing the array" << endl;
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}


void nextPermutation(vector<int>& nums) {
    map<int,int> mp; // store the location of each no
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]] = i;
    }
    int max = *max_element(nums.begin(), nums.end());
    for(int i=nums.size()-1; i>=1; i--){
        int curr = nums[i];
        if(nums[i-1] < curr){
            int num = nums[i-1];
            while(num != max){
                if(mp[num + 1] > i-1){
                    swap(nums[mp[num+1]], nums[i-1]);
                    break;
                }
                num++;
            }
            sort(nums.begin() + i, nums.end());
            return;
        }
    }
    sort(nums.begin(), nums.end());  
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    nextPermutation(nums);
    print(nums);
}