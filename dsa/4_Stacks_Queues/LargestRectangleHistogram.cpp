#include<bits/stdc++.h>
using namespace std;

/*
    ## Largest Rectangle in Histogram: Monotonic Stack Algorithm

    The goal is to find the maximum rectangular area that can be formed within a histogram by identifying, for each bar, 
    the furthest it can extend to the left and right without being blocked by a shorter bar.

    ---

    ### 1. Core Logic

    * **The "Expandable" Window:** For any bar at index  with height , its maximum area is , where **NSE** (Next Smaller Element) 
    is the first shorter bar to the right, and **PSE** (Previous Smaller Element) is the first shorter bar to the left.
    * **The Single Pass:** We use a **strictly increasing monotonic stack** to store indices.
        When we encounter a bar shorter than the current stack top, we have found the **NSE** for that top element.

    ---

    ### 2. Step-by-Step Breakdown

    1. **Initialize:** Create an empty stack to store indices and a `max_area` variable set to 0.
    2. **Iterate:** Loop from  up to  (where  is the number of bars).
    * **Dummy Zero:** Use a virtual height of `0` when . 
        This forces any remaining bars in the stack to be popped and processed.


    3. **The While Loop (The "Pop" Phase):** While the stack isn't empty and the current bar is shorter than (or equal to) the bar at the stack's top:
    * **Identify Height:** Pop the index `top_index`. The height we are calculating for is `heights[top_index]`.
    * **Identify Boundaries:**
    * **NSE:** The current index `i` is the right boundary.
    * **PSE:** The *new* `stack.top()` (the element below the popped one) is the left boundary. 
        If the stack is empty, the left boundary is effectively `-1`.


    * **Update Max:** Calculate `area = height * (i - PSE - 1)` and update `max_area`.


    4. **Push:** Push the current index `i` onto the stack and continue.

    ---

    ### 3. Complexity & Performance

    * **Time Complexity:** . Each index is pushed and popped exactly once.
    * **Space Complexity:**  to store the stack.
    * **Key Advantage:** This "single-pass" version is faster in competitive programming because it avoids multiple iterations and extra auxiliary arrays (like `vector<int> pse`).

*/


// shows calculation of pse and nse in a single go 
/*
    For a particular height we can extend on both sides until a smaller element is encountered 
    so we simply need the previous smaller and the next smaller element for that height 
    and get the rectamgle's width for that height 
    we need pse, nse

    FORMULA => area[i] = heights[i] * (nse - pse - 1)
*/

    //  ========== SINGLE PASS CALCULATION ==================
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // get the previous smaller element => defualt = -1
        // we can do it in go while computing th pse using monotonic increasing stack 
        int max_area = 0;
        stack<int> st;

        for(int i=0; i<=n; i++) {
            // a dmmy zero at the end so that the ans is updated once 
            int curr = (i == n) ? 0 : heights[i];
            int temp_area = 0;
            // pop whenever curr <= st.top 
            // we do the area calculation for the elements that we popped not for i 
            while(!st.empty() && curr <= heights[st.top()]) {
                // for all the elements st.top() > curr =>> the curr is the nse of it 
                int top_index = st.top();
                st.pop();
                // we calculate the area for the st.top
                // nse for st.top is curr (i) and pse is the top of the remaining top in the stack
                if(!st.empty()) 
                    temp_area = heights[top_index] * (i - 1 - st.top());
                else 
                    temp_area = heights[top_index] * (i); 
                    // heights[top_index] * (i - (-1) - 1) 
                max_area = max(max_area, temp_area);
            }
            st.push(i);
        }   
        return max_area;
    }
};




/*
    the bottom of the stack will mean that all the elements after that in the heights will be greater than it 
    The intutuion is that for a particular height we figure how much can it be extended on both the sides 

    For a particular height we can extend on both sides until a smaller element is encountered 
    so we simply need the previous smaller and the next smaller element for that height 
    and get the rectamgle's width for that height 
    we need pse, nse
    PSE: 
    for pse we can traverse in the forward direction and maintain a monotonic increasing stack 
    (bigger element at the bottom) => the top will be the previous smaller element 
    NSE:
    we traverse backward and maintain a monotonic increasing stack (lower at the bottom) 


    FORMULA => area[i] = heights[i] * (nse - pse - 1)
*/


// =========== CALCULATE PSE AND NSE Separately and then solve =================
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = heights.size();
        // get the previous smaller element => defualt = -1
        vector<int> pse(n, -1); 
        stack<int> st;  // a monotonic increasing stack for  

        for(int i=0; i<n; i++) {
            int curr = heights[i];
            // if the stack has bigger elements then pop from it 
            while(!st.empty() && curr < heights[st.top()]) {
                st.pop(); 
            }
            if(!st.empty()) {
                int idx = st.top();
                pse[i] = idx;
            }
            st.push(i);
        }  

        // now we make the the next smaller element => default as n
        // this means that if no element is smaller than x then we can extend our rectangle to the end 
        int max_area = INT_MIN;
        st = stack<int>();    // monotonically increasing stack (bottom is smaller than top)
        for(int i=n-1; i>=0; i--) {
            int curr = heights[i];
            int temp_area = 0;
            
            while(!st.empty() && curr <= heights[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {   // the top element is the nse of the curr 
                int idx = st.top();
                temp_area = heights[i] * (idx - pse[i] - 1);
            }
            else {
                temp_area = heights[i] * (n - pse[i] - 1);
            }
            max_area = max(max_area, temp_area);
            st.push(i);
        } 
        return max_area;
    }
};