## Solution to the question 


Think of the array as a single number (like `[1, 2, 3]` is **123**). You want to rearrange the digits to get the **next possible number** that is just slightly bigger than the current one.

### The 4-Step Recipe:

1. **Find the "Dip" (From the right):**
Start walking from the end of the line towards the front. You are looking for the first number that is **smaller** than the one immediately to its right.
* *Analogy:* You are climbing down a mountain. You want to find the first spot where the path goes "down" instead of "up". This number is your **Pivot**.


2. **Find the "Next Best Fit":**
Look at all the numbers to the right of your Pivot. Find the smallest number among them that is still **bigger** than your Pivot.
* *Why?* We want to increase the Pivot, but only by the smallest amount possible to keep the number close to the original.


3. **Swap Them:**
Switch the places of your **Pivot** and that **Next Best Fit** number.
4. **Reverse the Tail:**
Everything to the right of where your Pivot used to be is now in "descending order" (biggest to smallest). To make the new number as small as possible, simply **reverse** that entire back section so it goes from smallest to biggest.

---

### The "All Descending" Case:

If you walk all the way to the start and never find a "smaller" number (e.g., `3, 2, 1`), it means you are already at the biggest possible combination.

* **The Answer:** Just **reverse the whole list** to start over at the smallest combination (e.g., `1, 2, 3`).

### CODE

```cpp
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
```