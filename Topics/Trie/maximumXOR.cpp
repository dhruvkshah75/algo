// ===================================================== bit trie ================================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

/* Explanation: Tries of bits 
   Implement the bit trie => since we need to check maximum xor 
   to get the max xor of any random number with array of elements => takes only O(32)
   so this can be done effeciently using the bit trie 
   In the bit trie the numbers bits are arranges from msb at the top to the bottom 

   Then get the max xor by taking the xor of every num with all the elements in the array 
   O(32 * N) => O(32) for max xor of num with all elements in the array 
   so do this for all num belonging to the array 
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

    /* insert the num as bits (MSB first) */
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

    /* return the maxXOR of a number with all elements of the array => O(32) */
    int findMaxXOR(int num) {
        TrieNode* node = root;

        int maxXOR = 0;

        // maximize the number of set bits (maximize cases when XOR = 1)
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit;

            // we search for opposite bit as (xor of different bits = 1)
            if(node->children[opposite_bit] != nullptr) {
                maxXOR = maxXOR | (1 << i);
                node = node->children[opposite_bit];
            }
            else {
                // opposite bit is not available so xor of bit = 0
                node = node->children[bit];
            }
        }

        return maxXOR;
    }

    /* return the minXOR of a number with all elements => O(32) */
    int findMinXOR(int num) {
        TrieNode* node = root;

        int minXOR = 0;

        // minimize the number of set bits => (minimize the cases when XOR = 1)
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->children[bit] != nullptr) {
                node = node->children[bit];
            }
            else {
                // since XOR = 1 => set the bit 
                minXOR = minXOR | (1 << i);
                node = node->children[1-bit];
            }
        }

        return minXOR;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        BitTrie trie;

        for(int num: nums) 
            trie.insert(num);

        int maxXOR = 0;

        // try all possible max xors with each num from the array 
        for(int num: nums) {
            maxXOR = max(maxXOR, trie.findMaxXOR(num));
        }

        return maxXOR;
    }
};