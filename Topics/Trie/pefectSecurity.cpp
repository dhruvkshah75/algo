// ==================================== BitTrie - XOR queries ========================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";

// question link: https://codeforces.com/problemset/problem/923/C

/*
 * Using BitWise XOR tries 
 * Store the permutation before hand in the bit trie with the options to delete or erase elements from the trie 
 * now traverse through all the elements of A one by one and get the minXOR using the trie 
 * and doing so remove the occurrence of the number that we used it with 
 * Why do we need to delete the occurence of Pi => it is because one value can be used at most once 
 * and in doing so we get the lexicographically smallest message 
 */

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

	void insert(int num) {
		TrieNode* node = root;

		for(int i = 30; i >= 0; i--) {
			int bit = (num >> i) & 1;

			if(node->children[bit] == nullptr) {
				node->children[bit] = new TrieNode();
			}
			node = node->children[bit];
			node->cntPrefix++;
		}
	}

	int getMinXOR(int num) {
		// calculate the min XOR of num and delete the number in the trie with hom we get the minXOR
		TrieNode* node = root;

		int res = 0;

		for(int i = 30; i >= 0; i--) {
			int bit = (num >> i) & 1;
			int opp_bit = 1 - bit;
			// to get the minXOR we want to get more occurrences of 0 => bit XOR bit = 0
			if(node->children[bit] != nullptr && node->children[bit]->cntPrefix > 0) {
				node = node->children[bit];
			}
			else if(node->children[opp_bit] != nullptr && node->children[opp_bit]->cntPrefix > 0){
				// set the ith bit of res 
				res = res | (1 << i);
				node = node->children[opp_bit];
			}
			else {
				// fallback => this case never occurs
				break;
			}
			// remove the occurrence of the number that gives minXOR
			node->cntPrefix--;
		}

		return res;
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> A(n);
	for(int i = 0; i < n; i++) cin >> A[i];

	BitTrie trie;

	// insert all the numbers of the permuted key in the trie 
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		trie.insert(x);
	}

	// now form the result using minXOR 
	for(int i = 0; i < n; i++) {
		int res = trie.getMinXOR(A[i]);
		cout << res << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
