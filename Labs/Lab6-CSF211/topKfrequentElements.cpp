#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/top-k-frequent-elements/description/

/*
    VERY IMPORTANT usage of MIN HEAP using CUSTOM CMP
    We define a min heap with custom priority where the element with the least cnt in the array stays in the top 
    then we maintain a window of k with the top frequency 
    every time we push the element the heap places it in its correct location (based on the priority)
    then pop the top if the heap size exceeds k 

    NOTE: We must iterate through unique elements => VERY IMPORTANT 

    The time complexity instead of being O(N*LogN) is O(N*LogK)
    as the size of heap never exceeds k+1
*/

// implementing custom priority using lamda function 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time complexity = O(N*LogK)
        unordered_map<int,int>cnt;

        // populate the cnt map 
        for(int num: nums) 
            cnt[num]++;

        // define custom cmp using lamda function 
        auto cmp = [&](int a, int b) {
            // return true if 'a' should have lower priority than 'b'
            return cnt[a] > cnt[b]; // Min-heap: smallest count on top
        };

        // keep k elements in the heap => but the heap stores on the basis of least count (custom priority)
        priority_queue<int, vector<int>, decltype(cmp)> min_heap(cmp);

        // traverse through the unqiue elements
        for(auto &[num, count]: cnt) {
            // add the element in the heap => the heap will place it correctly 
            min_heap.push(num);
            
            // if the heap size is more than k then pop the top
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> ans;

        while(!min_heap.empty()) {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }

        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    
    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s = Solution();

    vector<int> ans = s.topKFrequent(nums, k);

    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}