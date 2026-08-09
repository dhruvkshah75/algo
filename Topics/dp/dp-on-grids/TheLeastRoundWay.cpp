// ========================================= grid dp ====================================================

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
#define setbitsll(x) __builtin_popcountll(x)

// question link: https://codeforces.com/problemset/problem/2/B

/**
 * to get leading zeros we need to consider the multiplicity of 2 and 5 
 * among all the elements encountered in the path as we multiply numbers in path 
 * run two dp recurrences 
 * 1. min number of 2s (including multiplicity) to reach the end 
 * 2. similarly min number of 5s to reach the end 
 * 
 * the final best path with minimum number of case 1, case 2
 **/

const int MAXN = 1005;

int n;
int cnt2[MAXN][MAXN];
int cnt5[MAXN][MAXN];

int grid[MAXN][MAXN];

int cntFactor(int num, int factor) {
	int count = 0;
	while(num % factor == 0) {
		num /= factor;
		count++;
	}
	return count;
}

/*
int f(int r, int c, int type) {
	// base case: invalid cell accessed 
	if(r >= n || c >= n) {
		return 1e9;
	}

	// base case: last cell reached 
	if(r == n-1 && c == n-1) {
		if(type == 2) return cnt2[r][c];
		else return cnt5[r][c];
	}

	int down = f(r+1, c, type);
	int right = f(r, c+1, type);
	int current = (type == 2) ? cnt2[r][c] ? cnt5[r][c];
	return current + min(down, right);
}
*/

void solve() {
	cin >> n;

	int zeroRow = -1, zeroCol = -1;
	// prefer a path with with 0 in it 

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];

			if(grid[i][j] == 0) {
				zeroRow = i;
				zeroCol = j;
			}
		} 
	}

	// precompute the cnt2 and cnt5 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 0) {
                // Prevent the normal DP from selecting zero.
                cnt2[i][j] = 1e9;
                cnt5[i][j] = 1e9;
            }
            else {	
				cnt2[i][j] = cntFactor(grid[i][j], 2);
				cnt5[i][j] = cntFactor(grid[i][j], 5);
            }
		}
	}

	vector<vector<int>> dp1(n+1, vector<int>(n+1, 1e9)), dp2(n+1, vector<int>(n+1, 1e9));
	// dp1 for 2 and dp2 for 5 

	dp1[n-1][n-1] = cnt2[n-1][n-1];
	dp2[n-1][n-1] = cnt5[n-1][n-1];

	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			// skip the [n-1][n-1] base case
			if(i == n-1 && j == n-1) continue;

			// for 2 
			dp1[i][j] = cnt2[i][j] + min(dp1[i+1][j], dp1[i][j+1]);

			// for 5
			dp2[i][j] = cnt5[i][j] + min(dp2[i+1][j], dp2[i][j+1]); 
		}
	}

	int result = min(dp1[0][0], dp2[0][0]);

	// A path through zero gives an answer of 1 which is better if result is more than 1 
    if(zeroRow != -1 && result > 1) {
        cout << 1 << endl;

        string path;

        path += string(zeroRow, 'D');
        path += string(zeroCol, 'R');
        path += string(n - 1 - zeroRow, 'D');
        path += string(n - 1 - zeroCol, 'R');

        cout << path << endl;
        return;
    }

	cout << result << endl;

	int row = 0, col = 0;
	// if the min is from dp1 then then get the path from dp1 

	string path = "";
	while(row != n-1 || col != n-1) {

		if(row == n-1) {
	        path.push_back('R');
	        col++;
	    }
	    else if(col == n-1) {
	        path.push_back('D');
	        row++;
	    }
	    else {
	        int down = (dp1[0][0] <= dp2[0][0]) ? dp1[row+1][col] : dp2[row+1][col];
	        int right = (dp1[0][0] <= dp2[0][0]) ? dp1[row][col+1] : dp2[row][col+1];

	        if(down <= right) {
	            path.push_back('D');
	            row++;
	        }
	        else {
	            path.push_back('R');
	            col++;
	        }
	    }
	}

	cout << path << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
