#include<bits/stdc++.h>
using namespace std;

// leetcode question link: https://leetcode.com/problems/separate-squares-i/description

/*
    Algorithm: Advanced Binary Search using Predicate function
    This algorithm uses **Binary Search on the Answer** (specifically on the real-number line) to find the correct Y-coordinate. 
    Since the function of "Area Below vs. Y-coordinate" is monotonic (strictly increasing), 
    we can efficiently narrow down the precise value.
    Here is the step-by-step algorithm for the code provided:

    ### 1. Define the Search Space
    Initialize the binary search boundaries for the potential Y-coordinate of the line:
    * **`l` (Low):** `0` (The minimum possible Y coordinate).
    * **`r` (High):** `1e9` (A value large enough to cover the highest possible square top based on problem constraints).

    ### 2. Binary Search Loop
    Enter a loop that continues as long as the search range is larger than the required precision ():
    * **Condition:** `while (r - l > 1e-5)`
    * **Midpoint:** Calculate the candidate Y-coordinate: `mid = (l + r) / 2`.

    ### 3. Check Area Distribution (The `areaCheck` function)
    For the current candidate line `y = mid`, calculate the total area of squares strictly **above** 
    the line (`highArea`) and strictly **below** the line (`lowArea`).
    Iterate through every square in the input array. For each square with bottom-left  and side length :

    1. **Calculate Top Edge:** Let .
    2. **Determine Position relative to `mid`:**
    * **Case A: Intersection ()**
    The line cuts through the square. Split the square's area:
    * Add  to `highArea`.
    * Add  to `lowArea`.


    * **Case B: Completely Below ()**
    The entire square is below the line.
    * Add  (total square area) to `lowArea`.


    * **Case C: Completely Above**
    The entire square is above the line.
    * Add  to `highArea`.

    ### 4. Adjust Search Range
    Compare the calculated areas to decide which half of the search space to discard:
    * **Condition:** `return (highArea > lowArea)`
    * **Logic:**
    * If `highArea > lowArea`, the area above is too large. This means our line `mid` is **too low**. We must search higher.
    * **Action:** Set `l = mid`.
    * Otherwise (`highArea <= lowArea`), the area below is too large (or they are equal). 
    * This means our line `mid` is **too high**. We must search lower.
    * **Action:** Set `r = mid`.

    ### 5. Termination and Result
    Once the loop terminates (when `r - l` is extremely small), 
    the value `l` (or `r`) represents the Y-coordinate where the areas are effectively equal.
    * **Return `l**`.
    ---

    ### Summary of Logic
    * **Goal:** Find  where .
    * **Monotonicity:** As the line moves **up** (Y increases), increases and  decreases. 
    * Because of this predictable behavior, we can use binary search instead of complex geometry calculations.        
*/

class Solution {
public:
    // binary predicate function which returns T or F 
    bool areaCheck(vector<vector<int>> &squares, double l) {
        int n = squares.size();
        double lowArea = 0.0, highArea = 0.0;
        for(int i=0; i<n; i++){
            int y1 = squares[i][1], len = squares[i][2];
            int y2 = len+y1;
            if(l < (double)y2 && l > (double)y1){
                highArea += ((double)y2-l)*(double)len;
                lowArea += (l-(double)y1)*(double)len;
            }
            else if((double)y2 <= l) lowArea += (double)len*(double)len;
            else  highArea += (double)len*(double)len;
        }
        return (highArea > lowArea);
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 1e9;
        while(r-l > 1e-5){
            double mid = (l+r)/2;
            if(areaCheck(squares, mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> squares(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
    }
    
    Solution s = Solution();
    double ans = s.separateSquares(squares);
    cout << ans << endl;
}
