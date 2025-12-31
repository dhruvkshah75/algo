#include<bits/stdc++.h>
using namespace std;

/*
    bit manupalation are much faster than modulo or division arithmetic 

*/

void printbinary(int num){
    for(int i=10; i>=0; i--){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

// 0th bit the num and 0th bit of 1 which is 1 undergo and operation to give 1 if if it is odd and 0 if its even
bool isEven(int num){
    if(num & 1) return false;     
    else return true;
}


int main(){
    // even no have 0th bit as 0 and for odd no 0th bit is 1 
    int num;
    cin >> num;
    printbinary(num);
    if(isEven(num)) cout << "Even" << endl;
    else cout << "Odd" << endl;

    // multiply by 2 or divide by 2
    // n >> 1 divides the no by 2  -->> right shift 
    // n << 1 multiplies the no by 2  -->> left shift 
    cout << (num >> 1) << endl;  // right shift of num by 1 the no gets multiplied by 2
    cout << (num << 1) << endl;  // left shift of num by 1 -->> the no gets divided by 2;

    // we can also print binary of char of A B C so on as their ascii value 65, 66 and so on 
    char c = 'A';
    // to print lowercase of A or uppercase of a
    // simply toggle the 5th bit by using XOR 
    // to toggle the bit at the ith bit use (n ^ (1 << i))   // note 1 << i this is left shift
    cout << (char)(c ^ (1 << 5)) << endl;
    // 1 << 5 is 32 is the ascii value of space
    cout << char(c ^ ' ') << endl;

    // to clear the lsb to the req no we can do
    // if i want to clear all bits till 5 bits we can do 
    printbinary(59);
    int a = 59;
    int i = 4;  // clear 4 lsb of 59
    printbinary(a & (~((1 << (i+1))-1)));

    // clear msbs till the ith bit
    // eg 00000111011 clear msbs till the 3rd bit 
    //    00000001111 -->> 0000010000-1 
    printbinary(a & ((1 << (i+1))-1));

}
