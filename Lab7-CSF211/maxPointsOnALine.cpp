#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    1 <= n <= 300 
    For every pair we find out how many other points have the same slope => use a map for that 
    map<pair<int,int>,int> mp => this stores the reduced form of {dx, dy} and keep only dx as negative 

    For a particular point populate the map with slope of that point with each other point and fill the map 
    and then get the maxPoints with the same slope 
*/

class Solution {
    pair<int,int> helperFunc(const pair<int,int>&a, const pair<int,int>&b) {
        // calculate the slope of these two and store in reduced form 
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        // note if the number is negative only keep dx negative 
        if(dy < 0){ 
            dx = -dx;  // making dx negative and dy as postive 
            dy = -dy;    
        }
        int gcd = __gcd(dx, dy);
        return {dx/gcd, dy/gcd};
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n == 1)
            return 1;

        // we take 2 points at a time and put in the slope in the map for a particular point 
        map<pair<int,int>,int> mp;
        // instead of storing a double store the reduced dy/dx form using gcd 
        int maxPoints = 0;

        for(int i = 0; i < n; i++) {
            // now we populate the map 
            for(int j = i + 1; j < n; j++) {
                pair<int,int> slope = helperFunc({points[i][0], points[i][1]}, {points[j][0], points[j][1]});
                mp[slope]++;
            }

            // now calculate for each pair and how many points lie on that 
            for(int j = i + 1; j < n; j++) {
                pair<int,int> slope = helperFunc({points[i][0], points[i][1]}, {points[j][0], points[j][1]});
                // we must also count the current point so all the values in the mp must be mp + 1
                maxPoints = max(maxPoints, mp[slope] + 1);
            }

            mp.clear();
        }

        return maxPoints;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for(int i=0; i<n; i++)  
        cin >> points[i][0] >> points[i][1];

    Solution s = Solution();

    int result = s.maxPoints(points);

    cout << result << endl;
}