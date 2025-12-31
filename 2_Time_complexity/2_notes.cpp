#include<iostream>
using namespace std;

// n < 10^5

int main(){
    int n;
    cin >> n;
    int ctr;
    while(n>0){         // time complexity is not o(n) n iterations dont occur 
        n/=2;
        ctr++;  //no of times the loop iterates 
    }
    // time complexity is o(1)+o(1)+o(1)+o(ctr) 
    // here ctr = log(n) to the base 2
    // overall time complexity of the code is o(log(n))
    // always try to convert o(n) code to o(log(n)) 
}

// eg 10-8-4-2-1 4 iteratiions