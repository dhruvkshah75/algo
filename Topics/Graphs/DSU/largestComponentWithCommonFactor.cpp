// ====================================================================== DSU + Graphs ====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/largest-component-size-by-common-factor/description/

/* Explanation: DSU graphs + number theory concepts 
   Consider the numbers of the array and then connect them to all of theirs factors 
   so if two different nums[i] and nums[j] belong to the same component then 
   either they could have common factor gcd > 1 or their might be at least one element k such that 
   gcd(i, k) > 1 and gcd(k, j) > 1 => then i, k, j belong to the same component 

   so for each number we must find its factors => O(sqrt(M))
   Final Time Complexity = O(N * sqrt(M))
*/

class Solution {
private:
    int N;

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        } 

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return;

            if(size[py] > size[px]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
        }

        bool sameComponent(int x, int y) {
            return find(x) == find(y);
        }
    };

public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        // make the dsu of size of max_element + 1
        N = *max_element(nums.begin(), nums.end()) + 1;

        DSU d(N);

        for(int num: nums) {
            // O(sqrt(num)) to get all the factors of num 

            for(int j = 2; j*j <= num; j++) {
                // connect num to its factors 
                if(num % j == 0) {
                    d.unite(num, j);
                    d.unite(num, num/j);
                }
            }
        }

        // use a map to store the parents and their size of the component
        unordered_map<int,int> mp;
        int res = 1;

        for(int i = 0; i < n; i++) {
            int p = d.find(nums[i]);
            mp[p]++;

            res = max(res, mp[p]);
        }

        return res;
    }
};