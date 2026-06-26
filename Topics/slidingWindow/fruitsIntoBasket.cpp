// ================================================== Sliding Window ======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/fruit-into-baskets/description/

/* Explanation: Sliding Window of variable size (2nd pattern) 
 * Here we start from the sliding window of size 1 and then we expand the sliding window 
 * until a new fruit type comes which is different from the fruit types in basket 1 and basket 2 
 * when we cannot expand further we start shrinking the sliding window untill one of the basket becomes empty 
 * 
 * we must return the length of the longest window size 
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0, res = 1;
        
        pair<int,int> b1 = {fruits[0], 1}, b2 = {-1, 0};

        while(r+1 < n) {
            // expand the window to include r+1
            // if the new fruit matches any of the basket fruit then put in it 

            if(b1.first == fruits[r+1]) {
                // newer fruit matches the basket1 so just add it 
                b1.second++;
                r++;
            }
            else if(b2.first == fruits[r+1]) {
                b2.second++;
                r++;
            }
            else if(b1.second == 0) {
                // basket 1 is empty fill the new 
                b1 = {fruits[r+1], 1};
                r++;
            }
            else if(b2.second == 0) {
                b2 = {fruits[r+1], 1};
                r++;
            }
            else {
                // cannot expand in the right so we must now shrink until one basket is available 
                while(b1.second > 0 && b2.second > 0) {
                    // remove the fruit[l]
                    if(fruits[l] == b1.first) b1.second--;
                    else if(fruits[l] == b2.first) b2.second--;

                    l++;
                }
                // reset the basket whose fruit cnt = 0
                if(b1.second == 0) b1 = {-1, 0};

                if(b2.second == 0) b2 = {-1, 0};
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};

// ========================================= Cleaner version of the above code ====================================================

/* Explanation: Sliding Window of variable size (2nd pattern) 
 * Here we start from the sliding window of size 1 and then we expand the sliding window 
 * until a new fruit type comes which is different from the fruit types in basket 1 and basket 2 
 * when we cannot expand further we start shrinking the sliding window untill one of the basket becomes empty 
 * 
 * we must return the length of the longest window size 
 * 
 * Simply use a map that should always contain exactly 2 baskets => check if the window is valid if not then shrink the
 * window from the left by doing l++ and when basket cnt = 0 (means no fruit in it) then erase that key 
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0, res = 1;
        
        // initialise the window with 1 element 
        unordered_map<int,int> basket;
        basket[fruits[0]]++;

        while(r+1 < n) {
            // expand the window on the right include r+1
            basket[fruits[r+1]]++;
            r++;

            // check if the window is not invalid => there should be only 2 baskets 
            while(basket.size() > 2) {
                basket[fruits[l]]--;

                if(basket[fruits[l]] == 0) 
                    basket.erase(fruits[l]);
                l++;
            }
        
            res = max(res, r-l+1);
        }

        return res;
    }
};