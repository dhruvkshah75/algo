
/*
VVVVV. IMP
Very important question on inclusion and exclusion
Problem:

Our Monk visits a neighbourhood school to teach kids, once a week. 
This week, they are studying the famous novel "The Three Musketeers" by Alexandre Dumas. As Monk is a fun teacher,
he wants to enact a scene from the novel and hence, must choose 3 children from the class as the musketeers.
There are N children in his class. Monk is given the list of names of the students. 
Help Monk find the number of ways in which he can choose the musketeers, 
such that the names of the three children have atleast a vowel in common i.e. the names must have atleast one of 
('a', 'e', 'i', 'o', 'u') in common. Two ways are considered different only if atleast one of the chosen student is different.

Input:
The first line consists of integer T. T testcases follow. 
The first line of each testcase consists of an integer N, denoting the number of children. 
It is followed by N lines, wherein each line is a string having only lowercase alphabets ('a'-'z') without spaces, 
denoting the names of children. A name can have a maximum length of 15 characters.

Output:
For each testcase, print the answer in a single line.

Constraints:
1 <= T <= 20
1 <= N <= 1e4;

*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 


// nC3 == n*(n-1)*(n-2)/6
bool isVowel(char s){
    return (s == 'a') || (s == 'e') || (s == 'i') || (s == 'o') || (s == 'u');
}

vector<string> subsets(string &s){   // using bitmasking;
    vector<string> ans;
    int len = (1 << s.size());
    // to avoid having empty string being inputted mask is started from 1
    for(int mask = 1; mask < len; mask++){
        string subset;
        for(int bit = 0; bit < s.size(); bit++){
            if(mask & (1 << bit)) subset.pb(s[bit]);
        }
        ans.pb(subset);    
    } 
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    unordered_map<string,int> hsh;
    for(int i=0; i<n; i++){
        set<char> distinct_v;
        for(int j=0; j<v[i].size(); j++){
            if(isVowel(v[i][j])){
                distinct_v.insert(v[i][j]);
            }
        }
        string vowel_str;
        for(auto &ch: distinct_v) vowel_str.pb(ch);
        // generate all subsets of the string vowel_str an add it to the map
        vector<string> subset = subsets(vowel_str);
        for(int i=0; i<subset.size(); i++){
            hsh[subset[i]]++;
        }
    }
    ll ans = 0;
    for(auto &[str, cnt]: hsh){
        if(str.size() == 1 || str.size() == 3 || str.size() == 5){
            if(cnt >= 3){
                ans += (cnt*1LL*(cnt-1)*(cnt-2))/6;
            }
        }
        else{
            if(cnt >= 3){
                ans -= (cnt*1LL*(cnt-1)*(cnt-2))/6;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}