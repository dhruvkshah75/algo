// question link: https://leetcode.com/problems/spiral-matrix/description/

// Algorithm 
/*
    1. Initialize Boundaries First, define four pointers that mark the "walls" of the unprocessed portion of the matrix:
        top: Points to the first row (starts at 0).
        bottom: Points to the last row (starts at rows - 1).
        left: Points to the first column (starts at 0).
        right: Points to the last column (starts at columns - 1).

    2. The Main Loop Enter a loop that continues as long as the boundaries have not crossed each other 
        (i.e., top <= bottom AND left <= right). Inside this loop, perform the traversal in four phases:
        Phase A: Left to Right (Top Wall)
            Iterate from the left boundary to the right boundary.
            Add elements from the top row to your result list.
            Update: Increment top (move the top wall down), as this row is now fully processed.
        Phase B: Top to Bottom (Right Wall)
            Iterate from the (new) top boundary to the bottom boundary.
            Add elements from the right column to your result list.
            Update: Decrement right (move the right wall left).
        Phase C: Right to Left (Bottom Wall)
            Check: First, verify that top <= bottom. (This is necessary because top was incremented in Phase A; 
            if the matrix was a single row, we must stop here to avoid duplicates).
            Iterate from the right boundary down to the left boundary.
            Add elements from the bottom row to your result list.
            Update: Decrement bottom (move the bottom wall up).
        Phase D: Bottom to Top (Left Wall)
            Check: Verify that left <= right. (Necessary because right was decremented in Phase B).
            Iterate from the bottom boundary up to the top boundary.
            Add elements from the left column to your result list.
            Update: Increment left (move the left wall right).
            
    3. Termination Once the loop finishes (meaning the boundaries have met or crossed), return the result list.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]); 
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

void printArray(vector<int> &arr){
    cout << "Printing the array: " << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiralOrder(matrix);
    printArray(ans);
}