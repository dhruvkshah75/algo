// ==================================== number theory ===========================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";

// question link: https://codeforces.com/problemset/problem/735/D

/*
 * We are supposed to split the given number into k different numbers (k >= 1)
 * and get the max divisor of each => it is better to split the number into a sum of its primes 
 * as for prime numbers the max divisor apart from the number itself will be 1 => 1 minimises the total sum 
 * 
 * We use the goldbachs conjecture which is valid for numbers in the range of 1e9 
 * Time complexity to check if a number is prime or not is O(sqrt(N))
 * 
 * 1. if n is prime then max divisor = 1 
 * 2. if n is even and n >= 4 => by goldbach's conjecture we can say that n can be sum of 2 prime numbers 
 *    x + y = n => where x and y are prime numbers 
 * 3. if n is odd => case 1: if n-2 is prime then n = (2 + (n-2)) => ans = 2
 *    case 2: by weak golbachs conjecture each odd number can be represented as sum of 3 prime numbers 
 *    x + y + z = n => x, y, z are prime numbers => ans = 3
 */

bool isPrime(int n) {
	// returns true if n is prime => has only two divisors 1 and n 
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
// O(sqrt(N))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if(isPrime(n)) {
		// number is prime => split into k = 1 different numbers 
		cout << 1 << endl;
	}
	else if(n & 1) {
		if(isPrime(n-2)) cout << 2 << endl;
		else cout << 3 << endl;
	}
	else {	
		// by goldbachs conjecture => every even number can be broken into sum of 2 prime numbers 
		cout << 2 << endl;
	}
}