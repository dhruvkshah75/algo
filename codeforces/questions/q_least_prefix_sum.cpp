// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

int Solve(vector<int> a) {
  long long sum = 0;
  multiset<int> s;
  int ret = 0;
  for (int x : a) {
    sum += x;
    s.insert(x);
    while (sum < 0) {
      sum -= 2 * (*s.begin());
      ret += 1;
      s.erase(s.begin());
    }
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = k; i < n; i++) {
      b.push_back(a[i]);
    }
    vector<int> c;
    for (int i = k - 1; i > 0; i--) {
      c.push_back(-a[i]);
    }
    cout << Solve(b) + Solve(c) << '\n';
  }
  return 0;
}
