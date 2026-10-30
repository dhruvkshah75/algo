
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

template <typename T>
void printVec(const vector<T>& v) {
    for(const auto &x: v) cout << x << " ";
    cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
    cerr << "{"; print(p.first); cerr << " ";
    print(p.second); cerr << "}";
}

template <typename T>
void print(const vector<T> &v) {
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * cover all houses using 3 base stations => each station can over [t-d, t+d]
 * we want this d to minimised. so simply apply binary search on d 
 * and then predicate function places 3 towers  
 * */

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    // sort the positions to placing the three towers becomes easy 
    sort(A.begin(), A.end());

    auto isPossible = [&](double d) -> pair<bool,vector<double>> {
        // return true if 3 towers cover all the houses 
        int placed = 0;
        int ind = 0;
        vector<double> result(3, 0.0);

        while(placed < 3 && ind < n) {
            double station_loc = A[ind] + d;
            double end = station_loc + d;
            
            // placed the station at this position 
            result[placed] = station_loc;
            placed++;

            // skip out the locations which are covered
            int j = ind + 1;
            while(j < n && (double)A[j] <= end) j++;
            ind = j;
        }

        bool ans = (ind == n);
        return {ans, result};
    };

    double low = 0.0, high = (double)A[n-1] - A[0];

    // apply bs for 100 iterations 
    for(int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;
        auto [flag, v] = isPossible(mid);

        if(flag) high = mid;
        else low = mid;
    }

    // high is the guranteed to be the correct 
    auto [temp, result] = isPossible(high);

    cout << fixed << setprecision(6) << high << endl;
    for(int i = 0; i < 3; i++) {
        cout << fixed << setprecision(6) << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}