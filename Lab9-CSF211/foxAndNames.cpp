#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/510/C

void solve(int n, vector<string> &words) {
    // use topological sorting 

    vector<vector<int>> adjL(26);
    vector<int> indegree(26, 0);
    // 0 = a to 25 = z 

    for(int i = 0; i+1 < n; i++) {
        string str1 = words[i], str2 = words[i+1];
        bool stored = false;
        for(int j = 0; j < min(str1.length(), str2.length()); j++) {
            if(str1[j] == str2[j]) continue;

            stored = true;
            adjL[str1[j] - 'a'].push_back(str2[j] - 'a');
            indegree[str2[j] - 'a']++;
            break;
        }

        if(!stored && str1.length() > str2.length()) {
            cout << "Impossible" << endl;
            return;
        }
    }


    // now apply kahn's algorithm
    queue<int> q;
    vector<bool> vis(26, false);

    string result = "";

    for(int i = 0; i < 26; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        result += (char)(node + 'a');

        for(int nbg: adjL[node]) {
            indegree[nbg]--;
            if(vis[nbg]) {  // cycle detected 
                cout << "Impossible" << endl;
                return;
            }
            else if(indegree[nbg] == 0) {
                q.push(nbg);
                vis[nbg] = true;
            }
        }
    }

    if(result.length() == 26)
        cout << result << endl;
    else 
        cout << "Impossible" << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);

    for(string &str: words) 
        cin >> str;

    solve(n, words);
}