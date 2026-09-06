#include <bits/stdc++.h>
using namespace std;

// in this jump the current height will be smaller and the next height will be bigger 
struct Jump {
    int currHeight;
    int nextHeight;
};

int solve(int n, std::vector<int> &h, int l, int b) {
    // get the max heights that are there and use ladder on them 

    // we can use a min heap to store the last min case when i used a ladder => if i have a bigger jump then that remove the ladder and use bricks 

    auto cmp = [&](const Jump &a, const Jump &b) {
        // return true if a has lower priority than b 
        return (a.nextHeight - a.currHeight) > (b.nextHeight - b.currHeight);
    };

    priority_queue<Jump, vector<Jump>, decltype(cmp)> minHeap(cmp);

    // fill the min heap until the size is l => size to never excced l 
    int result = 0;
    int bricks_left = b;
    
    for(int i = 0; i + 1 < n; i++) {
        
        if(h[i] >= h[i+1]) {
            // we can jump without any assistance 
            result = i + 1;
        }
        else {
            // we can jump we must ladder or bricks 
            if(minHeap.size() < l) {
                // if size is less than l then we can use a ladder 
                // cout << "Ladder used for : " << h[i] << " " << h[i+1] << endl;
                minHeap.push({h[i], h[i+1]});
                result = i + 1;
            }
            else {
                int curr_jump = h[i+1] - h[i];
                // all the ladders are consumed => throw out the ladder that was used for the smallest height and use bricks
                if(!minHeap.empty()) {
                    auto [h1, h2] = minHeap.top();
                    // we must pop only if the curr jump is more than the heap top jump 
                    if(h2 - h1 <= curr_jump) {
                        // now we can use bricks if available
                        if(bricks_left >= h2 - h1) {
                            bricks_left -= (h2 - h1);
                            minHeap.pop();

                            // now use ladder to jump this distance
                            minHeap.push({h[i], h[i+1]});
                            result = i + 1;
                        }
                        else break;
                    }
                    else {
                        // this jump is smaller than top jump then use bricks 
                        if(bricks_left >= curr_jump) {
                            bricks_left -= curr_jump;
                            result = i + 1;
                        }
                        else break;
                    }
                }
                else {
                    // if the min heap is mepty we must use bricks always 
                    if(bricks_left >= curr_jump) {
                        bricks_left -= curr_jump;
                        result = i + 1;
                    }
                    else break;
                }

            }
        }
    }
    // ans will be 1 based 
    return result + 1;

}