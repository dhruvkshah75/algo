#include<bits/stdc++.h>
using namespace std;

// N < 10^5
// a[i] < 10^5

int main()
{
    // no of iterations in one second are 10^7 - 10^8
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    // time complexity is o(1)+o(1)+o(1)+o(n) = o(n) since n is a power of 5 so this code will execute in less than 1sec.
}