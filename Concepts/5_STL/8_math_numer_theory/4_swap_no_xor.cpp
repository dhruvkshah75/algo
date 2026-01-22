#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){         // xor method to swap two numbers 
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main(){
    int a = 4, b = 6;
    cout << a << " " << b << endl;
    /*
        properties of xor(exclusive or)
        1 0 -->> 1
        0 1 -->> 1
        0 0 -->> 0 
        1 1 -->> 0
        so when two bits are same then xor makes it 0
        so 5 -->> 0101 so  5^5 is 0 as both have the same binary so xor of every bit is 0 
        xor of any number with 0 gives back the number

        Very Important property 
        x ^ x = 0 and x ^ 0 = x

        important property of XOR (it is associative so order independent)
        x ^ y ^ z == x ^ z ^ y == y ^ x ^ z
    */

    a = a ^ b;
    b = b ^ a;   // b = b ^ (a ^ b)   -->> b = b ^ b ^ a == 0 ^ a -->> b = a
    a = a ^ b;   // a = a ^ (b ^ a)   -->> a = a ^ a ^ b == 0 ^ b -->> a = b;
    // now the no are swapped

    cout << a << " " << b << endl;
}