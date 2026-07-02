// ======================================== tries ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-word-in-dictionary

/* Explanation: tries 
   for a word to have all the prefixes => in the trie => every node must isEnd = true 
   so store all the words in the trie and use a modified search to also check wether all nodes in the path 
   have isEnd = true 
   and update the maxLen of such word that is found and then check this for only those strings whose len >= matchLen

   OR 
   sort the strings first on the basis of their length and then to break ties on the basis of lexicographical order 
   and when we find a result => search returns true => this one is the best string of all 
*/

/* Explanation: tries 
   for a word to have all the prefixes => in the trie => every node must isEnd = true 
   so store all the words in the trie and use a modified search to also check wether all nodes in the path 
   have isEnd = true 
   and update the maxLen of such word that is found and then check this for only those strings whose len >= matchLen

   OR 
   sort the strings first on the basis of their length and then to break ties on the basis of lexicographical order 
   and when we find a result => search returns true => this one is the best string of all 
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

public: 
    Trie() : root(new TrieNode()) {}

    void insert(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c - 'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }

        node->isEnd = true;
    }

    // returns true if the word has all prefixes in the trie 
    bool searchWithAllPrefixes(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c - 'a';

            if(node->children[idx] == nullptr) return false;
            // move to the next node 
            node = node->children[idx];

            // this path until node => must be a word 
            if(!node->isEnd) return false;
        }

        // the last node itself must also be a word
        return (node->isEnd);
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        int n = words.size();

        string res = "";
        int maxLen = 0;
        
        // created a stack object of Trie
        Trie trie = Trie();

        for(string &s: words)
            trie.insert(s);


        for(int i = 0; i < n; i++) {
            // if curr word is smaller than current answer => then dont check 
            if(words[i].length() < maxLen) continue;

            if(trie.searchWithAllPrefixes(words[i])) {
                // when of the same length then compare lexicographically
                if(res.length() == words[i].length() && words[i] > res) continue; 

                res = words[i];
                maxLen = res.length();
            }
        }

        return res;
    }
};