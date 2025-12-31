#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*
    NOTES: Binary operators
    XOR is exclusive or  -->> same input will give 0 so 1 1 -->> 0 and 0 0 -->> 0 
    Left shift << right shift >> 
    and &  or |  xor ^
    not !
    3 << 1 (3 left shift 1) 3 in binary is 0011 after left shift 0110    
    3 << 2 ---->>>   1100  shift to the left by 2 
    3 >> 1 (3 right shift 1)  0011 will become 0001 (shifting to the right)
    6 >> 1 (6 right shift 1) 0110 -->> 0011 i.e 3 
    integers are 32 bit numbers 

    1 << 0 is 1
    1 << 1 is 2
    1 << 2 is 4
    1 << 3 is 8 and s on
    1LL<<n = 2^n  so (1 left shift n will give 2^n)
*/


int main(){
    int max = INT_MAX;
    cout << max << endl;
   //int a = (1<<32)-1;   -->> overflows        // integers are 32 bits 
    int a = (1LL<<31)-1;
    cout << a << endl;
    // the max value of int is 2^31-1;
    // as first bit is for signed and unsigned
    unsigned int b = (1LL<<32)-1;
    cout << b << endl;
}