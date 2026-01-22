#include <bits/stdc++.h>
using namespace std;


template <typename T> T addition(T a, T b)          //function template
{
    return a+b;
}

void examples()
{
    cout << (char)('c'+ 1) << endl;
    double a = 3/2;   // it will stored as 1 as it first evaluates as integers and then stored as a = 1;
    cout << "The value of double is: " << a << endl;
    cout << 7/2*3 << endl;   // 3*3 = 9;

    int b = 100000;
    int c = 100000;
    int d = b*c;    // d is 10^10 - overflow thru the range of int.
    long int e = b * 1LL * c;  // or could (long int)b * c;
    cout << d << endl;  
    cout << e << endl;
    int max = INT_MAX;
    int min = INT_MIN;
    cout << min << endl;
    max++;      // cause overflow it will cycle back to INT_MIN
    cout << max << endl;
}

int main()
{
    int a = 2;
    int b = 3;
    auto result = addition(a, b);
    cout << "The sum is: " << result << endl;
    cout << a++ << endl;
    cout << ++a << endl;
    //char, int, float, double, bool
    // long int, long long int

    char c = 'a';
    cout << (int)c << endl;

    examples();
}


/*  approximate ranges of int, long int, long long int to keep in mind while coding
*   -10^9 < int < 10^9;       INT_MIN < int < INT_MAX
*   -10^12 < long int < 10^12
*   -10^18 < long long int < 10^18
*/