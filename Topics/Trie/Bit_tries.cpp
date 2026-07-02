// ======================================== tries + bits manupilations ==============================

#include<bits/stdc++.h>
using namespace std;

/* Note for tries of bits 
   We wont be simply just storing 9 as 1001
   we need to store it for all bits => all 32 bits 0000...1001
   depth of trie will be at max 32 => as int has 32 bits 

   Bit Trie (XOR Trie) — used for problems involving bitwise XOR, maximum XOR, minimum XOR on a set of numbers.

   
   Bit tries are useful in case of XOR 
   1 ^ 0 is 1 and 0 ^ 0 is 0 
   1 ^ 1 is 0
   XOR of same bits is 0 and XOR of different bits is 1 


   The numbers are stored with MSB first and then LSB
   the bit starts from i = 31 to i >= 0
   each query is O(32) => constant Time Complexity 

   How to check if the ith bit is set or not 
   Use right shift 

   Some Important Bit manupulation 
    1. check if the bit is set or not
       (num >> i) & 1 => this will tell wether the bit is set or not 

    2. set the ith bit 
       (1 << i) = 2 ^ i => left shift and then or this with our num 
       num | (1 << i)

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
    BitTrie() {
        root = new TrieNode();
    }

    /* insert a number => MSB first */
    void insert(int num) {
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--) {
            // using right shift get the status of the ith bit 
            int bit = (num >> i) & 1; 

            if(node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }

            node = node->children[bit];
        }
    }

    /* returns the maximum xor of number num in the bit trie */
    int findMaxXOR(int num) {
        TrieNode* node = root;

        int maxXOR = 0;

        // we want to maximize the number of set bits 
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // search for the opposite bit 
            int oppositeBit = 1 - bit;
            
            // if opposite bit exists then select that (xor = 1)
            if(node->children[oppositeBit] != nullptr) {
                maxXOR = maxXOR | (1 << i);   // set the bit in res 
                node = node->children[oppositeBit];
            }
            else {
                // opposite bit does not exist => so take xor = 0
                node = node->children[bit];
            }
        }

        return maxXOR;
    }

    int findMinXOR(int num) {
        TrieNode* node = root;

        int minXOR = 0;

        // minimize the number of set bits 
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // we want the XOR to be 0 => minimize the number of set bits 
            if(node->children[bit] != nullptr) {
                node = node->children[bit];
            }
            else {
                // bit does not exist => so now the XOR = 1 
                minXOR = (1 << i) | minXOR;
                node = node->children[1-bit];
            }
        }
        
        return minXOR;
    }

};

