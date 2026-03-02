#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximal-rectangle/description/
// This question is extended version of maximal rectangle in a histogram 
// We convert each row into that question and calculate the maxRectangle 

/*
    We solve this question similar to the largest rectangle in a histogram 
    We maintain a heights array while moving in each row => and we convert the problem for each 
    row into the question of largest rectangle in histogram 
    And get the area of the rectangle by using monotonic increasing stack 

    to calculate the max rectangle we calculate the max rectangle by calculating the nse and pse 
    the rectangle with heights[i] will range from pse + 1 to nse - 1 
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxRectangle = 0;

        vector<int> heights(cols, 0);
        // if we encounter a 1 then we increase heights[i] and if we get a 0 then reset the height 

        for(int i=0; i < rows; i++) {
            // now populate the heights array for each row 
            for(int j=0; j < cols; j++) {
                if(matrix[i][j] == '0') 
                    heights[j] = 0;
                else 
                    heights[j] += 1;
            }

            // now since the hegihts is populated we have a histogram => where we find the largest rectangle 
            stack<int> st;
            // store indices => monotonic increasing stack to get the pse and nse 

            for(int j=0; j <= cols; j++) {
                // add a dummy value at the end to eempty out the stack 
                int curr = (j == cols) ? 0 : heights[j];
                // the curr element is the nse of top index in the stack 
                while(!st.empty() && curr <= heights[st.top()]) {
                    int top_idx = st.top();
                    st.pop();

                    int h = heights[top_idx];
                    int w = j;

                    if(!st.empty()) {
                        int pse_idx = st.top();
                        w = j - pse_idx - 1;
                    }

                    int currRectangle = h * w;
                    maxRectangle = max(maxRectangle, currRectangle);
                }

                st.push(j);
            }
        }

        return maxRectangle;  
    }
};