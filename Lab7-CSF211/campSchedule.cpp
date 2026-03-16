#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1137/B

void solve(string &s, string &t) {

    if(s.length() < t.length())
        cout << s << endl;

    int cnt0 = 0, cnt1 = 0;



    for(char &c: t) {
        (c == '0') ? cnt0++ : cnt1++;
    }

    unordered_map<char,int> mp;
    // store the cnt of 0 and 1 on the map 
    for(char &c: s) 
        mp[c]++;

    // we need to place cnt1 and cnt0 
    int times = 0;

    if(cnt0 == 0) {
        if(mp.find('0') == mp.end())
            times = mp['1'] / cnt1;
        else {
            cout << s << endl;
            return;
        }
    }
    else if(cnt1 == 0) {
        if(mp.find('1') == mp.end())
            times = mp['0'] / cnt0;
        else {
            cout << s << endl;
            return;
        }
    }
    else 
        times = min(mp['0'] / cnt0, mp['1'] / cnt1);

    cerr << times << endl;

    if(times == 0)
        cout << s << endl;
    else {
        string result = "";
        while(times--) {
            result += t;
            mp['0'] -= cnt0;
            mp['1'] -= cnt1;
        }

        while(mp['0'] > 0) {
            result += '0';
            mp['0']--;
        }

        while(mp['1'] > 0) {
            result += '1';
            mp['1']--;
        }

        cout << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    solve(s, t);
}