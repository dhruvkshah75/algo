#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/word-ladder/description/

/*
    Question is based on BFS on states of strings 
    here we start from beginWord then we swap all the positions from index 0 to index 10 and try all the 
    26 chars possible and then push only the ones that exist in the wordList 
    => this is brute force of pushing all the states
*/

class Solution {
private:
    int bfs(unordered_set<string> &words, string beginWord, string endWord) {
        unordered_set<string> visited;

        queue<pair<string,int>> q;
        // q = {currentState, level} => level indicates the moves to reach this step 
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [currState, level] = q.front();
            q.pop();

            if(currState == endWord) return level;

            // push the next states by changing one character => 
            // push all the possibilites by swapping at each index of currState so 26*length 
            for(int i = 0; i < currState.length(); i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    string newState = currState;
                    newState[i] = c;
                    if(words.find(newState) != words.end() && visited.find(newState) == visited.end()) {
                        q.push({newState, level+1});
                        visited.insert(newState);
                    }
                }
            }
        }

        return 0;
    }


public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        // question is based on bfs of states 
        unordered_set<string> words;

        for(int i = 0; i < n; i++) {
            words.insert(wordList[i]);
        }

        if(words.find(endWord) == words.end()) return 0;

        return bfs(words, beginWord, endWord);
    }
};


// =======================================================================
//                  SPACE OPTIMISED CODE 
// =======================================================================
class SpaceOptimisedSolution {
private:
    int bfs(unordered_set<string> &words, string beginWord, string endWord) {
        // instead of using visited we can just erase from words
        queue<string> q;
        // q = {currentState} we also keep track of level indicates the moves to reach this step 
        q.push(beginWord);
        words.erase(beginWord);
        int level = 1;       

        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                string currState = q.front();
                q.pop();

                if(currState == endWord) return level;

                // push the next states by changing one character => 
                // push all the possibilites by swapping at each index of currState so 26*length 
                for(int i = 0; i < currState.length(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string newState = currState;
                        newState[i] = c;
                        if(words.find(newState) != words.end() ) {
                            q.push(newState);
                            words.erase(newState);
                            
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }


public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        // question is based on bfs of states 
        unordered_set<string> words;

        for(int i = 0; i < n; i++) {
            words.insert(wordList[i]);
        }

        if(words.find(endWord) == words.end()) return 0;

        return bfs(words, beginWord, endWord);
    }
};