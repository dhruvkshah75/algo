// =============================================== heaps - priority queues ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/meeting-rooms-iii/description/

/* Explanation: heaps + hash table + simulation 
   Each meeting must be alloted the available room with least number 
   and each meeting goes on for [start, end) => we can start a new meeting at end time 
   use a set to store the the available rooms so we can get the room with the min number in O(Log(N))

   min heap = {end_time of the meeting, room in which the meeting takes place} 
   heap must contain only n values at the same time 
   and use a hash map to cnt how many meets took place in the room x 
   so Time Complexity = O(M*Log(N) + M*Log(M))
*/

typedef long long ll;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        // prefill the set with all the available rooms 
        set<int> st;
        for(int i = 0; i < n; i++) 
            st.insert(i);

        vector<int> cnt(n, 0);
        // cnt[i] = stores the number of meetings that took place in room i

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        // pq = {end_time, room of the meeting}

        for(int i = 0; i < m; i++) {
            ll start_time = meetings[i][0], end_time = meetings[i][1];

            // free all the rooms whose meet is completed 
            while(!pq.empty() && pq.top().first <= start_time) {
                auto [end, room] = pq.top();
                pq.pop();
                // room is now free so update it 
                st.insert(room);
            }

            // if n rooms are not filled then fill the smallest room 
            if(pq.size() < n) {
                int room = *st.begin();
                st.erase(room);
                pq.push({end_time, room});  // now the room is occupied 
                cnt[room]++;
            }
            else {
                // all rooms are occupied => so this meet is delayed wait for the earliest meet to finish 
                auto [end, room] = pq.top();
                pq.pop();

                // start this meet at time = end
                ll duration = end_time - start_time;
                pq.push({end + duration, room});
                cnt[room]++;
            }
        }

        // get the smallest room number with max meetings 
        auto it = max_element(cnt.begin(), cnt.end());
        int best_room = distance(cnt.begin(), it);

        return best_room;
    }
};