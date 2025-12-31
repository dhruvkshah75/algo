
/*  
    Problem : XOR challenge:

    You are given an integer C such that the XOR of two integers A and B is C. In short  (⊕ denotes the bitwise the XOR operation).

    Out of all possible pairs of A and B, you must find two integers such that their product is maximum. 

    Let us define L(C) as the length of C in its binary representation. Then, L(A) <= L(C) and L(B) <= L(C).

    Input format: 
    A single integer representing C (0 <= C <= 1e5);

    Output format: 
    Print the maximum product you can achieve under the given conditions

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int msb_pos(int n){
    int pos = -1;
    while (n > 0){
        n >>= 1;
        pos++;
    }
    return (pos);  // eg 8 is 1000 so this will return 3 as the ans as pos starts from -1
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    int a = 0, b = 0;
    int pos = msb_pos(c);  // -->> instead of this use (int)log2(c) -->> gives the position of the msb
    cerr << pos << endl;
    cerr << (int)log2(c) << endl; 
    for(int i=0; i<=pos ;i++){
        if(i == pos){
            a |= 1 << i;
            b &= ~(1 << i);
            break;
        }
        if(c & (1 << i)){  // if the bit is set then a should have the bit set and b should be unset
            b |= 1 << i;  // make the bit set 
            a &= ~(1 << i);  // make the bit unset
        }
        else{   // if bit is unset then both a and b should have that bit set
            a |= 1 << i;
            b |= 1 << i;
        }
    }

    cout << a*1LL*b << endl;
}