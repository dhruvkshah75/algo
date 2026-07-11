// ====================================================== prefix trie ========================================= 

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

/* Explanation: tries 
   simply maintain the tries data structure and update the cntPrefix 
   the score a word will be the sum of cntPrefix for all prefix of word[i]
*/

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        int cntPrefix;

        TrieNode() : cntPrefix(0) {
            for(int i=0; i<26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

public: 
    Trie() : root(new TrieNode()) {}

    void insert(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->cntPrefix++;
        }
    }

    int calcScore(string &word) {
        // word definetly exists in the trie 
        TrieNode* node = root;
        int score = 0;

        for(char c: word) {
            int idx = c-'a';
            node = node->children[idx];
            score += node->cntPrefix;
        }
        return score;
    }

};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        Trie trie;

        for(string &str: words) 
            trie.insert(str);

        // now get the score of each word 
        vector<int> res;

        for(string &str: words) {
            res.push_back(trie.calcScore(str));
        }

        return res;
    }
};