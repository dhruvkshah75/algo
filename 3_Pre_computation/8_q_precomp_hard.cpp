//*********** Luffy asks "IsPalin" ? ************* */
/*
	Given a string S of lowercase of length N and two integers L and R he wants to know whether all the 
	letters of the substring form index L to R(L and R included) can be rearranged to form palindrome or not.
	he wants to this Q values of L and R

	Constriants: 
	1 <= t <= 10
	1 <= N, Q <= 1,00,000
	1 <= L <= R <= N
	'a' <= S[i] <= 'z' for 1 <= i <= N

	INPUT:
	first line an integer t denoting number of test cases 
	second line for each test case are two integers N and Q 
*/



/*
	Notes: in a palindrome the count of each element is even and only one element count is odd or it may not be 
	so form an array of count of eaxh letter
	right approach: form 26 arrays for storing the count of that element at the respective index and then forming 
	the prefix sum for eaxh of that

	// 2d array hsh is created and converted to for the string in prefix sum
	in time complexity of O(N) for storing the count of each element in the string 

*/

#include<bits/stdc++.h>
using namespace std;
//#define Brute_force

const int N = 1e5+10;  // max size of the string
int hsh[N][26];     // 26 arrays are requirred for each alphabet 0 for a and so on

int main(){
	int t;
	cin >> t;
	while(t--){
		//since the hash array is globally declared it needs to refreshed for every turn
		for(int i=0; i< N; i++){
			for(int j=0; j<26; j++){
				hsh[i][j] = 0;
			}
		}
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		for(int i=1; i<=n; i++){
			hsh[i+1][s[i]-'a']++;  
		}

		// forming the prefix sum array within the same array
		for(int i=0; i<26; i++){
			for(int j=1; j<=n; j++){
				hsh[j][i] += hsh[j-1][i];
			}
		}
		while(q--){
			int l, r;
			cin >> l >> r;
			int oddctr = 0;
			for(int i=0; i<26; i++){
				int charCt = hsh[r][i] - hsh[l-1][i];
				if(charCt%2 != 0) oddctr++;
			}

			if(oddctr > 1) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	
}













#ifdef Brute_force 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		while(q--){
			int l, r;
			cin >> l >> r;
			int hsh[27];   // stores count for each alphabet of str a=1 and z=26;
			for(int i=1; i<=26; i++){
				hsh[i] = 0;
			}

			for(int i=l; i<=r; i++){    // this loop needs to be eliminated 
				hsh[s[i]-'a'+1]++;
			}

			int oddCtr = 0;
			for(int i=1; i<=26; i++){
				if(hsh[i]%2 != 0) oddCtr++;
			}

			if(oddCtr > 1) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	} 
	// time complexity is O(t*q*n) = 10*10^5*10^5
}
#endif