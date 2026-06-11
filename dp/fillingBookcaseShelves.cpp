// ================================================================== linear - dp ======================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/filling-bookcase-shelves/description/

/* Explaination: Can be considered of the pattern of linear dp
   How dp => we are supposed to place books and each choice creates a complete new configuration 
   and greedy doesnt work => some step taken now (greddily) might cause harm in future options 

   Recurrence f(ind) = min height of placing the books 
   each call of f involves placing x number of books in the same shelf 
   height of the shelf required will max(height of books among the x books placed)

   Place x number of books on the same shelf such that (total thickness <= shelfwitdh)
   books are to be placed in the order and every time f is called => means start placing 
   books onwards from books[ind] ... in a new shelf

*/

class Solution {
private: 
    static constexpr int N = 1e3+1;
    int dp[N];

    int f(int ind, vector<vector<int>> &books, int shelfWidth, int n) {
        // base case: all books are placed 
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // try placing books[ind...] in the current shelf
        // max_height and combined_thickness are running variables for [ind..x] for these books 
        int max_height = 0, combined_thickness = 0;
        int res = 1e8;

        for(int j = ind; j < n; j++) {
            combined_thickness += books[j][0];

            // if combined thickness exceeds shelf width then we cannot place more books in this shelf 
            if(combined_thickness > shelfWidth) break;

            max_height = max(max_height, books[j][1]);

            // place the jth book on the shelf and start the new shelf from j+1 th book
            res = min(res, max_height + f(j+1, books, shelfWidth, n));
        }

        return dp[ind] = res;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        memset(dp, -1, sizeof(dp));
        
        // start by placing begenning with the first book
        return f(0, books, shelfWidth, n);
    }
};