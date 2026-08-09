// ==================================== sliding window + binary search =====================================

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

// question link: https://codeforces.com/problemset/problem/1073/C

/**
 * apply simple binary search on answer i.e. x is the length of subsegment in which we are allowed to make changes 
 * so for the predicate function => use sliding window of fixed size x check if we can make some changes to L,R,U,D
 * and something like that to make the string of operations valid 
 * 
 * predicate function returns ....FFFFFTTTTT..... => find the first occurrence of T
 **/

unordered_map<char,int> freq;

bool isPossible(string &str, int k, int x, int y) {
	int n = str.length();
	unordered_map<char,int> window;
	// window of fixed size k 

	// total net displacement 
	int totalX = freq['R'] - freq['L'];
	int totalY = freq['U'] - freq['D'];

	int l = 0;
	for(int r = 0; r < n; r++) {
		window[str[r]]++;

		if(r-l+1 > k) {
			// shrink from left by 1 
			window[str[l]]--;
			l++;
		}

		if(r-l+1 == k) {
			// if changes are made in this window then does the final result become eqaul
			int windowX = window['R'] - window['L'], windowY = window['U'] - window['D'];

			// the displacement made outside this window 
			int outsideX = totalX - windowX, outsideY = totalY - windowY;
			// the net displacement needed inside the window will be target - outside 
			int requiredX = x - outsideX, requiredY = y - outsideY;

            int min_moves = abs(requiredX) + abs(requiredY);

            // if the window size is enough, => min moves <= k and remaining moves must cancel out 
            if(min_moves <= k && (k - min_moves) % 2 == 0) {
            	return true;
            }
		}
	}

	return false;
}

void solve() {
	int n, x, y;
	string str;

	cin >> n;
	cin >> str;
	cin >> x >> y;

	freq.clear();

	// base case: cannot reach the target very far
	int distance = abs(x) + abs(y);
	if(distance > n || (n - distance) % 2 != 0) {
        cout << -1 << endl;
        return;
    }
	
	// store the freq of the characters in str 
	for(int i = 0; i < n; i++) freq[str[i]]++;

	// base case: check if the string is already valid or not 
	if(freq['R'] - freq['L'] == x && freq['U'] - freq['D'] == y) {
	    cout << 0 << endl;
	    return;
	}

	int low = 1, high = n, ans = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(str, mid, x, y)) {
			high = mid-1;
			ans = mid;
		}
		else low = mid+1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	solve();
}

