#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    notes: 
    eg of a binary no 1 0 1 1 1 0 1 1 -->> the rightmost bit is lsb(least significant bit)  -->> this binary no has 6 set bits and 2 unset bits
    so 0th bit is lsb and nth bit is the msb (most significant bit) 
    set bit -->> 1 and unset bit -->> 0 
    _________________________________________________________________________________________________________________________
    IMP method to check if the the nos ith bit is set or not is by doing and with the no with only 1 set bit at ith position
    eg 
    5 -->>  0101
            0010 apply & operation on both we get
            0000 -->> 0 so the ith bit that is 1st bit is unset in 5
    7 -->>  0111  
            0010  apply & operation
    we get  0010 -->> the no gets returned (or its non zero) 
    (so if the ith bit is set then a non zero no is returned when and operation is done
        if the ith bit is unset then zero is returned);
    to get the no ---->>    1 left shift i
                            (1 << i) -->> 2^i;  
                            if we subtract 1 from (1 << i) we get all 1s before the ith position

*/

void printBinary(int num){
    for(int i=10; i>=0; i--){
        cout << ((num >> i) & 1);    // num right shift takes the ith bit at 0th position and then and with 1 gives 0 or one 
    }
    cout << endl;
}

int main(){
    // left shift << and right shift >> 
    printBinary(9);
    int a = 9;
    int i = 1;  // to check if the ith bit is set or not
    if((a & (1 << i)) != 0){       // 1 << i   --->> 00000100000....  1 at the ith position 
        cout << "set bit" << endl;
    }
    else{
        cout << "unset bit" << endl;
    }
    // to make the ith bit set we can do (a | (1 << i))
    int b = (a | (1 << i));    // --->>> 1001 | 0010 -->> 1011 which is 11
    int c = (a | (1 << 2));
    cout << b << endl;
    cout << c << endl;

    /*
        to unset the bit at the ith position do and with 1111111101111111... 0 at the ith position
        this is the invert of the no with 1 at the ith position 000000100000....  1 at the ith position
        ~ -->> tilda is used to invert the no 
        ~ (1 << i)  -->> is to get the no 
    */
    // bit set
    printBinary(a | (1 << 1));

    printBinary(1 << 3);
    printBinary(~(1 << 3));  
    // bit unset
    printBinary(9 & (~(1 << 3)));   // -->> to unset the bit at the 3rd bit in case of 9  ->> 1001 

    // bits are 0 based indexed 
    // toggle  -->> XOR toggles the bit --->> make 0 to 1 and 1 to 0 at the ith position
    // if i want to toggle bit at the ith position
    printBinary(a ^ (1 << 2));
    // does on and off to the bit 

    // count the no of set bits
    int d = 9;
    int ct = 0;
    for (int i = 31; i >= 0; i--){
        if ((d & (1LL << i)) != 0){
            ct++;
        }
    }
    cout << ct << endl;

    cout << __builtin_popcount(a) << endl;   // -->> inbuilt function to calculate no of set bits
    // works for int 
    cout << __builtin_popcountll((1LL<<35)-1) << endl;
    // __builtin_popcountll works for long long 
}