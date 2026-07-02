// ================================================ tries ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://takeuforward.org/plus/dsa/problems/number-of-distinct-substrings-in-a-string

// ================================ Very Important Logic ================================================

/* What does the question mention ? 
 * Given a string s, determine the number of distinct substrings (including the empty substring) of the given string.
 * A string B is a substring of a string A if B can be obtained by deleting several characters (possibly none) 
 * from the start of A and several characters (possibly none) from the end of A.
 * Two strings X and Y are considered different if there is at least one index i such that the character of X at index i
 * is different from the character of Y at index i (X[i] != Y[i]).
 * 
 * Approach:
 * How exaclty does trie help here => it just inserts the a substring exactly once if inserted then does not deal it again 
 */

/* Explanation: tries 
   Simple thought is => when we insert (it means it was not there) so increment cnt of substrings 
   and when already exists we are inserting => dont cnt again 

   Simple logic is start with l = 0 => string [0...end] insert it into the trie character by character 
   Every distinct substring corresponds to a unique path in the trie. So if you insert all suffixes of the string into a trie, 
   the number of nodes = number of distinct substrings (including empty string).

   one loop for starting index => [i...end] for all i => add the nodes character by character and we keep adding so increase the cnt 
   and when already exists node => dont increment cnt 

   for this only the TrieNode struct is neede as rest is pretty much useless 


    basically inserting all substrings in the trie => but insertion is to be done character by character to avoid extra O(N) factor 
    Final Time Complexity => O(N^2)
*/

struct TrieNode {
    TrieNode* children[26];

    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution{	
public:
	int countDistinctSubstring(string &s) {
        int n = s.length();

        TrieNode* root = new TrieNode();
        int cnt = 1;   // start with cnt = 1 as empty substring always exists "" => root 

        // insert all suffixes 

        for(int i = 0; i < n; i++) {
            TrieNode* node = root;
            
            for(int j = i; j < n; j++) {
                int idx = s[j]-'a';
                // node does not exist => substring [j...end] encountered first time 
                if(node->children[idx] == nullptr) {
                    node->children[idx] = new TrieNode();
                    cnt++;
                }

                node = node->children[idx];
            }
        } 

        return cnt;
	}
};