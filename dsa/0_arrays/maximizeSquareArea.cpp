#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/ 

/*
Algorithm:
    We need the largest square hole, which requires equal openings in both directions. 
    So we find the maximum consecutive bars we can remove horizontally and vertically, separetly in both the arrays, 
    convert each to opening size by adding 1, and then take the smaller value as our square's side length.
*/



class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // so we have n+2 horizontal bars and m+2 vertical bars 
        // 2 are the end bars we have to remove bars from the arrays to get the maximum area 
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        // now we calculate the longest consecutive sequence 
        int i=0;
        int hx = 0, hy = 0;
        while(i < hBars.size()){
            int tp1 = hBars[i];
            int j = i+1;
            int tp2 = tp1+1;
            while(j < hBars.size() && hBars[j] == tp2){
                tp2++; j++;
            }
            if(tp2-tp1 > hy-hx){
                hx = tp1; hy = tp2-1;
            }
            i = j;
        }
    
        int k=0;
        int vx = 0, vy = 0;
        while(k < vBars.size()){
            int tp1 = vBars[k];
            int j = k+1;
            int tp2 = tp1+1;
            while(j < vBars.size() && vBars[j] == tp2) {
                tp2++; j++;
            }
            if(tp2-tp1 > vy-vx) {
                vx = tp1; vy = tp2-1;
            }
            k = j;
        }
        int ans = min(hy-hx+2, vy-vx+2);
        return ans*ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int len1, len2;
    cin >> len1 >> len2;
    vector<int> hBars(len1);
    vector<int> vBars(len2);
    for(int i=0; i<len1; i++){
        cin >> hBars[i];
    }

    for(int i=0; i<len2; i++) {
        cin >> vBars[i];
    }

    Solution s = Solution();
    int ans = s.maximizeSquareHoleArea(n, m, hBars, vBars);
    cout << ans << endl;
}
