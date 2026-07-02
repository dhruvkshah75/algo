// ======================================================== tries ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/replace-words/description/

/* Explanation: tries + 2 pointers (instead of using hash tables)
   we must replace each word in sentence with a word from dictionary if possible with 
   the word from the dictionary being the prefix of the word from the sentence 
   So create a new method => that returns the word from the trie which is a prefix of the 
   word from the sentence  

   To save space dont generate words in the sentence (use start and end pointers) and pass the 
   entire sentence by referrence 
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
    Trie() {
        root = new TrieNode();
    }

    // insert the word in the trie
    void insert(string &word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';
            
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            } 
            node = node->children[idx];
        }

        // mark this node as the end of the word 
        node->isEnd = true;
    }

    string getPrefix(int start, int end, string &word) {
        // return the smallest string from trie which is the prefix of word 
        TrieNode* node = root;
        string res = "";

        for(int ind = start; ind < end; ind++) {
            char c = word[ind];
            int idx = c - 'a';
            // check if the word is formed or not 
            if(node->isEnd) return res;

            // did not find a prefix word in the dict => check if this c exists or not 
            if(node->children[idx] == nullptr) break;

            res += c;
            node = node->children[idx];
        }

        return word.substr(start, end-start);
    }
};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string &sentence) {
        int sz = dictionary.size(), n = sentence.length();

        Trie* trie = new Trie();

        for(string &s: dictionary) 
            trie->insert(s);

        string res = "";

        int l = 0;

        while(l < n) {
            int r = l;

            while(r < n && sentence[r] != ' ') r++;

            // add the result of the prefix matching and then add a space 
            res += trie->getPrefix(l, r, sentence);
            res += ' ';

            l = r+1;
        }

        // in the end one extra space gets added => remove that 
        res.pop_back();

        return res;
    } 
};