#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/2/A

void solve(vector<pair<string,int>> &rounds) {
    int n = rounds.size();

    // step 1: calculate final scores
    unordered_map<string,int> score;

    for(auto& [player, playerScore] : rounds)
        score[player] += playerScore;

    // step 2: find maxScore and build winner set
    int maxScore = INT_MIN;
    for(auto& [player, pScore] : score)
        maxScore = max(maxScore, pScore);

    unordered_set<string> winners;      // map which contains only the winners 

    for(auto& [player, pScore] : score)
        if(pScore == maxScore)
            winners.insert(player);

    // step 3: replay to find who first reaches >= maxScore
    unordered_map<string,int> running;
    // select only the one among the winner set 
    for(auto& [currPlayer, roundScore] : rounds) {
        running[currPlayer] += roundScore;
        // choose the one among the winner set that wins 
        if(winners.count(currPlayer) && running[currPlayer] >= maxScore) {
            cout << currPlayer << endl;
            return;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 

    vector<pair<string,int>> rounds(n);

    for(int i = 0; i < n; i++) {
        cin >> rounds[i].first >> rounds[i].second;
    }

    solve(rounds);
}