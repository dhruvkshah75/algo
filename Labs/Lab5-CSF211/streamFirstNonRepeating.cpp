#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// question based on queues 
// we queues as we are supoosed to get the first lower index as the non repeating value 


class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string ans = "";
        // we maintain a queue as soon as the same element 
        // we use the queue as a waiting room where we keep elements in the queue as fifo

        queue<int> q;  // store the indexes of the elements pushed in the queue 

        unordered_map<char,int> cnt;

        for(int i=0; i<s.length(); i++) {
            // first we push the element in the queue (waiting room)
            q.push(i);
            // update the counter hash map 
            cnt[s[i]]++;  
            // pop all th elements with cnt > 1
            while(!q.empty() && cnt[s[q.front()]] > 1) { 
                q.pop();
            }

            if(q.empty()) 
                ans += '#';
            else 
                ans += s[q.front()];
        }

        return ans;
    }
};

int main() {
    string str;
    cin >> str;

    Solution s = Solution();

    cout << s.firstNonRepeating(str) << endl;
}