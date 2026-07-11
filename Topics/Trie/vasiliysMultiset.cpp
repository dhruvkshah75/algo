#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/706/D

// simple implementation of bit trie to get max XOR 

class BitTrie {
private:
    struct TrieNode {
        TrieNode* children[2];
        int cntPrefix;

        TrieNode() : cntPrefix(0) {
            children[0] = children[1] = nullptr;
        }
    };

    TrieNode* root;

public:
    BitTrie() : root(new TrieNode()) {}

    /* insert 1 occurence of num */
    void insert(int num) {
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->cntPrefix++;
        }
    }

    /* erases one occurrence of number from the trie */
    void erase(int num) {
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            node = node->children[bit];
            node->cntPrefix--;
        }
    }

    /* find the max xor of num with elements present int the set => O(32) */
    int findMaxXOR(int num) {
        TrieNode* node = root;

        int max_xor = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp_bit = 1-bit;

            // maximize the number of set bits (xor = 1)
            if(node->children[opp_bit] != nullptr && node->children[opp_bit]->cntPrefix > 0) {
                max_xor = max_xor | (1 << i);
                node = node->children[opp_bit];
            }
            else if(node->children[bit] != nullptr && node->children[bit]->cntPrefix > 0) {
                node = node->children[bit];
            }
            else {
                break;
            }
        }

        return max_xor;
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    BitTrie trie;
    trie.insert(0);
    // 0 always exist in the trie

    while(q--) {
        string t;
        char s;
        cin >> s >> t;

        int number = stoi(t);

        if(s == '+') trie.insert(number);
        else if(s == '-') trie.erase(number);
        else {
            int max_xor = trie.findMaxXOR(number);
            cout << max_xor << endl;
        }
    }
}