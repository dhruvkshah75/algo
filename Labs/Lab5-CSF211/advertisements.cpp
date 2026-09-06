#include<bits/stdc++.h>
using namespace std;

// question link: https://cses.fi/problemset/task/1142/
// Similar to the MAXIMUM RECTANGLE IN A HISTOGRAM => ../dsa/4_Stacks/LargestReactangleHistogram.cpp

// the max area for a particular column can lie between pse and nse of it 

long long maxRectangle(vector<int>&arr) {
    // the max area for a particular element would be the that it can extend from pse to nse 
    // previous smaller element to the next smaller element 

    int n = arr.size();
    stack<int> st;          // using a monotonic increasing stack
    long long area = 0;

    for(int i=0; i<=n; i++) {
        // we add a dummy 0 at the end, beacuse the array is sorted then the stack will never be invoked 
        int curr = (i == n) ? 0 : arr[i];

        long long temp_area = 0;
        
        while(!st.empty() && curr <= arr[st.top()]) {   
            int top_index = st.top();
            // for this top element in the stack => curr is the next smaller element (nse)
            // and the pse (prev smaller element) of top element is the element below it 
            st.pop();
            // we calculate the area for the top element not the curr 
            if(!st.empty()) {  // the pse of top exists 
                temp_area = arr[top_index] * 1LL * (i - st.top() - 1);
            }
            else {  // the pse of the top element doesnt exist => then it extend till the end on the left
                temp_area = arr[top_index] * 1LL * i;
            }
            area = max(area, temp_area);
        }
        
        st.push(i);
    }

    return area;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    long long area = maxRectangle(arr);
    cout << area << endl;
}


