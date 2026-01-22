
/*
    GENERATE PARENTHESIS question on leetcode(medium)

    ex:
    input: n=3;
    output: ["((()))", "(())()", "()(())", "()()()", "(()())"]
    constraint of n is 1 <= n <= 8;
    uses backtracking concept

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

vector<string> valid;

// since in this question u are trying to create multiple possibilites so backtracking is required
// in this in one function call can have two recursive calls so backtracking i.e. 
// pop_back() step is required to undo the chnage done so that it can go into the next recursive call;

void generate(string &s, int open, int close){
    if(open == 0 && close == 0){  // base condition for recursion
        valid.push_back(s);
        return;
    }
    if(open > 0){
        s.push_back('(');
        generate(s, open-1, close);
        s.pop_back();   // --> backtracking step  
        // pop_back step is necessary to create multiple steps 
    }
    if(close > 0){         
        if(open < close){   // open indicates the no of opening brackets consumed so not used open should be less 
            s.push_back(')');
            generate(s, open, close-1);
            s.pop_back();
        }
    }
}

void solve(){
    // count of openeing bracket should be more than cosed brackets then only closing bracket addition is allowed
    int n;
    cin >> n;
    string s = "";
    generate(s, n, n);
    for(auto &s: valid){
        cout << s << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}