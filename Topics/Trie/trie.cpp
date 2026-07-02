// ================================================= tries ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

/* Explanation: 
   What does a trie data structure support 
   1. insert(word) => insert the string 'word' into the trie data structure 
   2. search(word) => to check if the string 'word' is present in the trie or not 
   3. startWith(word) => to check if there any string that starts with the given prefix string 'word'


   How exactly trie works ??
   This is like creating a tree data structure => each node has 26 children => characters 'a' to 'z'

   Trie is like a tree data structure so we make a TrieNode => each node has boolean flag to indicate whether this is the last node or not 
   and each node has 26 children => 'a' to 'z'


   insert, search, startsWith => O(L)

   Trie Wins in the cases where we want to make prefix queries 
   To check "does any word start with prefix p?" you'd have to iterate over all n words and check => TC: O(N*L)
   Here the trie data structure helps to check the prefix in O(L)
*/

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false) {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    TrieNode* find(string s) {
        // start with the root node
        TrieNode* node = root;

        for(char c: s) {
            int idx = c-'a';

            if(node->children[idx] == nullptr) 
                return nullptr;
            node = node->children[idx];
        }
        
        // return the node after the last char of s is matched 
        return node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';

            // check if char c exists or not => if not then create a node
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }

        node->isEnd = true;
    }

    // returns true if the word is present in the trie data-structure
    bool search(string word) {
        TrieNode* node = find(word);
        // if the returned node is not nullptr and with isEnd = true => then we found the word 
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};



// ================================================================================================================================ 

/*  Currently the trie does not deal with how many words start the given prefix or how many words start with 
 *  We need to implement more functions for this to correctly work 
 *
 *  What more is needed ?
 *  Implement "TRIE” data structure from scratch with the following functions.
 * 
 *  Trie(): Initialize the object of this “TRIE” data structure.
 *
 *  insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.
 *
 *  countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
 *
 *  countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
 *
 *  erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.
 *
 * 
 *  Simply same as normal trie where we either search the word or check for the prefix in the trie 
 *  So here we just replace all methods with count such number of words and also allow to erase the occurrence of a word 
 */

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        int cntEndWith;   // how many words end exactly here 
        int cntPrefix;    // how many words pass through this node (prefix)

        TrieNode() : cntEndWith(0), cntPrefix(0) {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

public: 
    Trie() : root(new TrieNode()) {}

    /** insert a new word in the string */
    void insert(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c - 'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
            node->cntPrefix++;  // update the nodes's prefix cnt 
        }
 
        node->cntEndWith++;  // update the node's cntEndWith -> node ends here
    }

    /** returns the cnt of number of words in the trie */
    int countWordsEqualTo(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';
            // the word does not exist as char c not found
            if(node->children[idx] == nullptr) return 0;

            node = node->children[idx];
        }

        return node->cntEndWith;
    }

    /** returns the cnt of number of words that have prefix */
    int countWordsStartingWith(string &prefix) {
        TrieNode* node = root;

        for(char c: prefix) {
            int idx = c-'a';
            if(node->children[idx] == nullptr) return 0;
            node = node->children[idx];
        }

        return node->cntPrefix;
    } 

    /** delete one occurrence of the word */
    void erase(string &word) {
        // first check if the word exists or not (i.e cntEndWith > 0)
        if(countWordsEqualTo(word) == 0) return;

        // safely remove one occurrence of the word => as verified that the word exists 

        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';
            node = node->children[idx];
            node->cntPrefix--;
        }
        // delete the cntEndWith of the word 
        node->cntEndWith--;
    }
};