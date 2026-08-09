// ============================================== bitmask dp ==================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)

// question link: https://codeforces.com/problemset/problem/1340/B

/**
 * Here we use bitmasks to handle the comparision of digit (encoded strings)
 * with the matching digit (encoded strings) for easy handling => here mask is not the dp state 
 * 
 * Approach
 * k sticks are not glowing so we are supposed to make k of them to glow 
 * so use dp to try all possible paths to check if using this numbers and this path 
 * can form a valid number or not => k > 0 || k < 0 are left in the end (not allowed) 
 * all the k sticks need to glow after assigning some number 
 * 
 * how to use bitmasks to handle the changes 
 * current string from the input => can have already some set bits and try to match with 9...0's 
 * encoded mask
 *
 * current_mask & digit_mask == current_mask => there should not be bits at zero positions
 * number of bits that are now glowed = setbits(current_mask XOR digit_mask)
 **/

vector<string> digit_str = {
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011",
	"1101111",
	"1010010",
	"1111111",
	"1111011"
};

/*
bool f(int ind, int rem, int n, vector<int> &grid) {
	// base case: all the strings covered 
	if(ind == n) return rem == 0;

	bool res = false;
	int current = grid[ind];
	for(int target: digit_masks) {
		// set bits should not differ (otherwise current cannot be made into target)
		if((current & target) != current) continue;

		int cost = setbits(current ^ target);
		if(rem-cost >= 0) res = res | f(ind+1, rem-cost, n, grid);
	}

	return res;
}
*/

void solve() {
	int n, k;
	cin >> n >> k;

	// store the mask of the numbers in the grid
	vector<int> grid;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		// convert binary string to integer
		int num = stoi(s, nullptr, 2);
		grid.push_back(num);
	}

	// store the digit_str in masks 
	vector<int> digit_masks;

	for(int i = 0; i <= 9; i++) {
		int digit = stoi(digit_str[i], nullptr, 2);
		digit_masks.push_back(digit);
	}


	vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
	// dp[0][k] = possible to form [0...n] digits with k glows left

	dp[n][0] = true;

	for(int ind = n-1; ind >= 0; ind--) {
		for(int rem = 0; rem <= k; rem++) {
			// try all digit_masks to form the number 
			bool res = false;
			int curr_mask = grid[ind];

			for(int target_mask: digit_masks) {
				// set bits in the current are at different position then cannot form cur to target
				if((curr_mask & target_mask) != curr_mask) continue;

				int cost = setbits(curr_mask ^ target_mask);
				if(rem - cost >= 0) res = res | dp[ind+1][rem-cost];
			}

			dp[ind][rem] = res;
		}
	}

	if(!dp[0][k]) {
		// dp[0][k] = final result is false then couldnt build any number at all 
		cout << -1 << endl;
		return;
	}

	// using the do table we reconstruct the max number on the scoreboard 
	// greedily try to build the number with the max digit (x = 0 is the MSB of the number)
	int x = 0, y = k;
	string max_number = "";

	while(x < n && y >= 0) {
		int curr_mask = grid[x];
		
		// try out current digit from 9 to 0
		for(int i = 9; i >= 0; i--) {
			int target_mask = digit_masks[i];

			if((curr_mask & target_mask) != curr_mask) continue;

			int cost = setbits(curr_mask ^ target_mask);
			if(y - cost >= 0 && dp[x+1][y-cost]) {
				// greedily pick this digit as this one would be the max among valid 
				max_number += i + '0';
				y -= cost;
				x++;
				break;
			}
		}
	}

	cout << max_number << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}