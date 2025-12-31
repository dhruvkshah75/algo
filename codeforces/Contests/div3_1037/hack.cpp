// Custom bits/stdc++.h replacement for macOS/Clang


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <clocale>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define ll long long int
#define endl '\n'
#define print(ans) cout << ans << endl
#define flagyn(flag) cout << ((flag) ? "YES" : "NO") << endl
#define pb push_back
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define fork(n) for (int k = 0; k < n; k++)
#define empire ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    empire;
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k,maxi=-1;
        cin>>n>>k;
        vector<ll>a(n);
        fori(n) {
            cin>>a[i];
        }
        int idx=-1;
        int ele=-1;
        for (int i = 0; i < n; i++)
        {
            if(i==k-1){
                idx=a[i];
                ele=a[i];
                break;
            }
        }
        sort(a.begin(),a.end());

        for (int i = 0; i < n; i++)
        {
            if(a[i]==idx){
                idx=i;
                break;
            }
        }
        vector<int>v;
        for (int i = idx; i < n; i++) {
            bool fl = false;
            for (int j = 0; j < v.size(); j++) {
                if (a[i] == v[j]) {
                    fl = true;
                    break;
                }
            }
            if (!fl) {
                v.push_back(a[i]);
            }
        }
        
        
        int i;
        int sec=0;
        idx=0;
        bool b=true;
        n=v.size();
        while ((idx+1)<n)
        {
            int x = v[idx+1]-v[idx];
            if(x+sec>v[idx]){
                b=false;
                break;
            }else{
                sec+=x;
            }
            idx++;
        }
        flagyn(b);

    }

    return 0;
}
