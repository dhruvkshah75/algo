// =================================================================== Tries ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/search-suggestions-system/

/* Explanation: prefix tries
   When every single word of the searchWord is typed then we must return the the top 3 matching (prefix words)
   these words need to be stored in the trie 
   the result vector size will be the length of the search word so when we traverse the trie 
   
   Sort the product vector strings in lexicographically correct order and when this is done 
   the most important part is when 3 indices are stored as prefix word in the TrieNode structure 
   this ensures that the best 3 strings were stored 
*/

class Trie {
private: 
    struct TrieNode {
        TrieNode* children[26];
        vector<int> best; 
        // best stores the indices of the best 3 suggested strings

        TrieNode() {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

public: 
    Trie() : root(new TrieNode()) {}

    void insert(string &word, int index) {
        // word is product[idx] string 
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }    
            node = node->children[idx];

            // now add this indexed word in the best if best.size() < 3
            if(node->best.size() < 3)
                node->best.push_back(index);
        }
    }

    vector<vector<string>> suggest(string &searchWord, vector<string> &products) {
        int n = searchWord.length();

        vector<vector<string>> res;
        TrieNode* node = root;

        for(int x = 0; x < n; x++) {
            int idx = searchWord[x]-'a';
            vector<string> temp;

            if(node->children[idx] == nullptr) {
                // word does not exist cannot go further => so we must add empty vectors till the end 
                for(int nxt = x; nxt < n;  nxt++) {
                    res.push_back({});
                }
                return res;
            }

            node = node->children[idx];
            // now this node has stored all the best 3 lexicographically suggested strings 
            for(int i: node->best) {
                temp.push_back(products[i]);
            }
            res.push_back(temp);
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        int n = products.size();

        // sort the product string vectors
        sort(products.begin(), products.end());

        Trie trie;

        // insert all the words in the trie data structure 
        for(int i = 0; i < n; i++) 
            trie.insert(products[i], i);
        

        return trie.suggest(searchWord, products);
    }
};