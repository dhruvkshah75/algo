#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://codeforces.com/contest/2193/problem/F
// VERY IMPORTANT Question 

/*
    For every group of same X (a vertical column):

    currL = lowest house (min Y)
    currR = highest house (max Y)

    dpL: Minimum time to finish all houses processed so far and end at currL
    dpR: Minimum time to finish all houses processed so far and end at currR
*/

struct Point {
    int X;
    int Y;
};

void solve(Point A, Point B, vector<Point> &houses) {
    int n = houses.size();

    sort(houses.begin(), houses.end(), [](const Point &a, const Point &b) {
        if (a.X == b.X) return a.Y < b.Y;
        return a.X < b.X;
    });

    ll dpL = 0, dpR = 0;    // dpL and dpR denote the time taken to reach left and right endpoints of previous case
    Point prevL, prevR;

    int i = 0;
    bool first = true;

    while (i < n) {
        int j = i;
        while (j < n && houses[j].X == houses[i].X) j++;
        j--;

        Point currL = houses[i];
        Point currR = houses[j];
        ll len = abs(currR.Y - currL.Y);      // difference between the current endpoints 

        if(first) {
            dpL = abs(A.X - currR.X) + abs(A.Y - currR.Y) + len;
            dpR = abs(A.X - currL.X) + abs(A.Y - currL.Y) + len;
            first = false;
        } 
        else {
            ll newL = min(dpL + abs(prevL.X - currR.X) + abs(prevL.Y - currR.Y) + len,
                dpR + abs(prevR.X - currR.X) + abs(prevR.Y - currR.Y) + len);

            ll newR = min(dpL + abs(prevL.X - currL.X) + abs(prevL.Y - currL.Y) + len,
                dpR + abs(prevR.X - currL.X) + abs(prevR.Y - currL.Y) + len);
            
            // update the dpL and dpR
            dpL = newL;
            dpR = newR;
        }

        prevL = currL;
        prevR = currR;

        i = j + 1;
    }

    ll ans = min(dpL + abs(prevL.X - B.X) + abs(prevL.Y - B.Y),
        dpR + abs(prevR.X - B.X) + abs(prevR.Y - B.Y));

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
        Point A, B;
        cin >> A.X >> A.Y >> B.X >> B.Y;

        vector<Point> houses(n);

        for(int i = 0; i < n; i++)
            cin >> houses[i].X;

        for(int i = 0; i < n; i++)
            cin >> houses[i].Y;

        solve(A, B, houses);
    }
}