#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1140/C

struct Song {
    int length;
    int beauty;
};

void solve(int k, vector<Song> &songs) {
    // maximimize the pleasure for at most k songs 
    // the most beauty is at the top so as we move ahead we know the least beauty 

    int n = songs.size();

    // store the songs in the minheap with the least length on the top 
    auto cmp = [&](const Song &a, const Song &b) {
        // return true if a has less priority than b 
        return a.length > b.length;
    };

    priority_queue<Song, vector<Song>, decltype(cmp)> minHeap(cmp);

    long long current_sum = 0;
    long long max_pleasure = 0;

    for(int i = 0; i < n; i++) {
        // we keep filling the heap until the heap.size() <= k
        minHeap.push(songs[i]);
        current_sum += songs[i].length * 1LL;

        // remove the one with the worst length from the heap 
        if(minHeap.size() > k) {
            current_sum -= minHeap.top().length;
            minHeap.pop();
        }

        // we traverse from most beauty to least beauty so we always know what the least beauty is 
        // calculate the max pleasure at each step 
        int minBeauty = songs[i].beauty;   // this is the min beauty of the current slot 

        max_pleasure = max(max_pleasure, minBeauty * 1LL * current_sum);
    }

    cout << max_pleasure << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Song> songs(n);

    for(int i=0; i<n; i++)
        cin >> songs[i].length >> songs[i].beauty;

    // sort the array on the basis of beauty in descending order 
    auto cmp = [&](const Song &a, const Song &b) {
        return a.beauty > b.beauty; 
        // sort in descending order of beauty 
    };

    sort(songs.begin(), songs.end(), cmp);

    solve(k, songs);
}