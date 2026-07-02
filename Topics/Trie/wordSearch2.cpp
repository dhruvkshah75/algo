// ================================================= tries ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/word-search-ii/description/

/* Explanation: tries + dfs 
   Here we implement the words to form a trie and then we keep using dfs to search the next node 
   the dfs should not keep calling the search() method as it would continuosly check for the the word 
   starting from the top again => which is kind of ineffeicent 
   so rather the dfs should keep the track of the node in the trie  

   Here the trie is only needed for insertion and nothing extra is needed 
   the dfs handles the case of matching the string to next word and so on

   Trie is useful here as it allows us to check if the current word is in prefix or not 
   that the path that we are following 
*/

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for(char c: word) {
            int idx = c-'a';
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            // move to next node further 
            node = node->children[idx];
        }
        // mark the last node with isEnd = true => word is completed
        node->isEnd = true;
    }
};

class Solution {
private:
    int m, n;
    Trie* trie;
    vector<string> res;

    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    void dfs(string &curr, int i, int j, TrieNode* node, vector<vector<char>> &board) {
        // return if already visited 
        if(board[i][j] == '#') return;

        int idx = board[i][j] - 'a';

        // current cell not found in the trie
        if(node->children[idx] == nullptr) return;

        node = node->children[idx];

        // since the cell is found in the trie => add this cell in the string and mark visited 
        curr.push_back(board[i][j]);
        board[i][j] = '#';

        // check if the word is correclty found
        if(node != nullptr && node->isEnd) {
            res.push_back(curr);
            node->isEnd = false;  // mark it false => to prevent duplicate words being counted 
        } 

        for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;

                if(ni >= m || ni < 0 || nj >= n || nj < 0 || board[ni][nj] == '#') continue;

                // call dfs for this neighbouring cell
                dfs(curr, ni, nj, node, board);
        }
        
        // backtrack 
        curr.pop_back();
        board[i][j] = (char)(idx + 'a');
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trie = new Trie();

        // insert all the word from the words into the trie for checking if a word exists (checking prefixes effeciently)
        for(string &word: words) 
            trie->insert(word);

        // we start dfs from all cells and then try getting all string on the path and when a word is encountered 
        // then add it to the res 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string curr = "";
                dfs(curr, i, j, trie->root, board);
            }
        }

        return res;
    }
};