#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()

// question link: https://codeforces.com/problemset/problem/1561/C

// Important Binary Search on answer => Based on Highly custom sorting 

bool canSurvive(int n, vector<vector<int>> &caves, ll health) {
    // can i survive all the caves with this health 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < caves[i].size(); j++) {
            if(health <= caves[i][j]) return false;

            // health > monster => update the health and then move forward 
            health++;
        }
    }
    return true;
}

void solve(int n, vector<vector<int>> &caves) {
    // we can apply binary search on the answer => minimum health the hero must have 

    // order in which we ave to beat the monsters is start with the cave in which the monsters max health is min 
    // sort it like that => positon of the monster also depends 

    auto cmp = [&](const vector<int> &a, const vector<int> &b) {
        // the max health of the monster that we must overcome depends on the position 
        auto reqHealth = [&](const vector<int> &a) {
            ll maxHealth = 0;
            // health of all the monsters becomes relative 
            for(int j = 0; j < a.size(); j++) {
                ll cur_monster_health = (ll)a[j] - j + 1;
                maxHealth = max(maxHealth, cur_monster_health); 
            }

            return maxHealth;
        };

        return reqHealth(a) < reqHealth(b);
    };

    sort(all(caves), cmp);

    ll low = 1, high = 2e9;
    int ans = 0;
    // predicate function returns => FFFFTTTT 
    while(low <= high) {
        ll mid = low + (high - low) / 2;

        if(canSurvive(n, caves, mid)) {
            high = mid - 1;
            ans = mid;
        }
        else low = mid + 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> caves(n);

        for(int i = 0; i < n; i++) {
            int k; cin >> k; 
            caves[i].resize(k);

            for(int j = 0; j < k; j++) 
                cin >> caves[i][j];
        }

        solve(n, caves);
    }
}