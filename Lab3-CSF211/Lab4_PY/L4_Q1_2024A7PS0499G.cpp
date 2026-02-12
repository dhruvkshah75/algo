#include <vector>
using namespace std;

/*
    The logic is keeping track of currentMin and currentMax 
    we update => curMax = max(curMax, curMax*nums[i]) and similarly for curMin 
    and when the number nums[i] < 0 (negative) then we simply swap the currentMin and current Max multiplying
    with a negative number changes the order 
    CHANGED Version of Kadane's Algorithm
*/

int solve(vector<int>& nums) {
    // expected time complexity is O(n)
    if (nums.empty()) return 0;

    // Initialize with the first element
    int res = nums[0];
    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // If the current number is negative, swapping max and min 
        // is a shortcut for the flipping logic.
        if (nums[i] < 0) {
            swap(curMax, curMin);
        }

        // At each step, the new curMax is either the current number alone
        // or the current number multiplied by the previous curMax.
        curMax = max(nums[i], curMax * nums[i]);
        curMin = min(nums[i], curMin * nums[i]);

        // Keep track of the highest product seen globally
        res = max(res, curMax);
    }
    return res;
}
