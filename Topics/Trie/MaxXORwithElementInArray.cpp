// ======================================== Bit Manupilation + Trie ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description

/* Explanation: bit trie
   we must get the max xor of a number x with some selected numbers from the array 
   => this will take only O(32) with the help of bit trie 
   since each query is already given to us => sort the queries based on the value of m 
   and then take xor of x with all elements <= m

   sort the nums array to correctly insert all the elements in the trie 
   and make sure that before calling findMaxXOR in the trie at least one element is inserted in the trie 
*/

class BitTrie {
private: 
    struct TrieNode {
        TrieNode* children[2];

        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };

    TrieNode* root;

public: 
    BitTrie() : root(new TrieNode()) {}

    /* insert a num in the trie bit wise (MSB first) */
    void insert(int num) {
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    /* find the max xor of num with all elements in trie => O(32) */
    int findMaxXOR(int num) {
        TrieNode* node = root;

        int maxXOR = 0;

        // maximise the no of sets bits (xor = 1)
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1-bit;

            // xor = 1 (opposite_bit ^ bit in nums)
            if(node->children[opposite_bit] != nullptr) {
                maxXOR = maxXOR | (1 << i);
                node = node->children[opposite_bit];
            }
            else {
                node = node->children[bit];
            }
        }

        return maxXOR;
    } 
};

class Solution {
private: 
    struct query {
        int x, m, idx;
        query(int x, int m, int i) : x(x), m(m), idx(i) {}
    };

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();

        vector<query> q;

        for(int i = 0; i < m; i++) {
            q.push_back(query(queries[i][0], queries[i][1], i));
        }

        // sort the queries based on their m values 
        auto cmp = [&](const query &a, const query &b) {
            return a.m < b.m;
        };

        sort(q.begin(), q.end(), cmp);

        // sort the nums so we can insert all nums[j] <= m
        sort(nums.begin(), nums.end());

        // insert elements in the trie only until <= q[i].m
        BitTrie* trie = new BitTrie();
        vector<int> res(m);

        // l => ptr for q and x => ptr for nums array 
        int l = 0, x = 0;

        while(l < m) {
            int limit = q[l].m;

            // insert all num[x] <= limit
            while(x < n && nums[x] <= limit) {
                trie->insert(nums[x]);
                x++;
            }

            // edge case => trie only works if there is at least one element in the trie (denoted by x)

            if(x == 0) {    
                // trie is empty so result is -1
                res[q[l].idx] = -1;
            }
            else {
                int max_xor = trie->findMaxXOR(q[l].x);
                res[q[l].idx] = max_xor;
            }

            l++;
        }

        return res;
    }
};

// Time Complexity = O(N * Log(N) + M * Log(M) + 32 * (N + M))