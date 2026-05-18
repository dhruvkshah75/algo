#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/word-ladder-ii/description/


// ====================================================================================
//            Highly unoptimised for space (gives MLE) => enough for interviews 
// ====================================================================================
/*
    We dont delete the strings once we push them in the queue => as their may be multiple shortest 
    paths that might lead to same step and we are supposed to return all such shortest paths 
    eg. bat-> bot -> pot -> .. and bat -> pat -> pot  ==> these are two sequences which end up at pot on level 3 
    so if we deleted pot earlier then it would have been wrong so we delete only after one level is completely been 
    analysed use the level technique 
    while(!q.empty()) {
        int qSize = q.size();
        while(qSize--) {
        
        }
        // here the entire level has been visited 
    }

    BackTracking is the key step here to allow future transformations to start off from the prev value 

*/
class Solution {
private:
    vector<vector<string>> bfs(unordered_set<string> &words, string beginWord, string endWord) {

        vector<vector<string>> result;

        queue<vector<string>> q;
        // q = (vector of strings in the current transformation)
        q.push({beginWord});
        // if begin word is there in the list then delete it 
        if(words.find(beginWord) != words.end()) words.erase(beginWord);

        bool notFound = true;

        while(!q.empty() && notFound) {
            // store the visited strings in the level temporarily and then after the complete level is traversed we delete them from words 
            unordered_set<string> seen;

            int qSize = q.size();
            while(qSize--) {
                vector<string> currState = q.front();
                q.pop();

                if(currState.back() == endWord) {
                    // this is the last level that needs to be proccessed 
                    result.push_back(currState);
                    notFound = false;
                }

                // now we must push its next possible transformations 
                string current = currState.back();

                for(int i = 0; i < current.length(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string newString = current;
                        newString[i] = c;
                        // now add this new string into the current string transformation path if valid 
                        if(words.find(newString) != words.end()) {
                            seen.insert(newString);
                            // only push new elements in the queue if endword is not found 
                            if(notFound) {
                                currState.push_back(newString);
                                q.push(currState);
                                // back tracking step to allow next transformations to go on 
                                currState.pop_back();
                            }
                        } 
                    }
                }
            }
            // delete the seen words from wordsList 
            for(const string &toDelete: seen) 
                words.erase(toDelete);

        }

        return result;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        unordered_set<string> words;

        for(int i = 0; i < n; i++) {
            words.insert(wordList[i]);
        }

        // if the endword is not in the list then return empty 
        if(words.find(endWord) == words.end()) {
            return {};
        }

        // in the queue of bfs we store the entire sequence after each transformation and use backtracking 
        return bfs(words, beginWord, endWord);

    }
};