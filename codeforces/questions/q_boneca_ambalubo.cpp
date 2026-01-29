#include<bits/stdc++.h>
using namespace std;

typedef unsigned long ul;

string xorStrings(const string &a, const string &b) {
    string result = "";
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] == b[i] ? '0' : '1');
    }
    return result;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n+10);
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        int max = *max_element(a.begin(), a.end());
        vector<string> binary_str(n+10);
        for(int i=1; i<=n; i++){
            binary_str[i] = bitset<32>(a[i]).to_string();   // to convert a number to a binary string
        }
        string max_str = bitset<32>(max).to_string();
        // create a 2d array in which element stores the req value
        ul ans = 0;
        for(int i=1; i<=n; i++){
            string result = xorStrings(max_str, binary_str[i]);
            bitset<32> bits(result);              
            ul num = bits.to_ulong();
            ans+=num; 
        }
        cout << ans << endl;
    }
}