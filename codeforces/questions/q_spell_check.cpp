
/*
********************************************************** A. Spell Check ******************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
Timur likes his name. As a spelling of his name, he allows any permutation of the letters of the name.
For example, the following strings are valid spellings of his name: Timur, miurT, Trumi, mriTu. 
Note that the correct spelling must have uppercased T and lowercased other letters.

Today he wrote string s of length n consisting only of uppercase or lowercase Latin letters. He asks you to check if s
is the correct spelling of his name.

Input
The first line of the input contains an integer t (1≤t≤103) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤10) — the length of string s.

The second line of each test case contains a string s consisting of only uppercase or lowercase Latin characters.

Output
For each test case, output "YES" (without quotes) if s satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

****************************************************************************************************************************************
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str ="Timur";
    vector<int> hsh(123);
    for(int i=0; i<str.size(); i++){
        hsh[(int)(str[i])]++;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n!=5){
        cout << "NO" << endl;
        return;
    }
    else{
        vector<int> count(123);
        for(int i=0; i<s.size(); i++){
            count[(int)(s[i])]++;
        }
        for(int i=0; i<s.size(); i++){
            if(count[(int)(s[i])] != hsh[(int)(s[i])]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}