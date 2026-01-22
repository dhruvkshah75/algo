//  ******************** to pass 2d arrays use this method *****************
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;        // declaring 2d arrays globally in case of competitve programming 
int a[N][N];

void func()
{
    a[0][0] = 5;
}

int main()
{
    a[0][0] = 7;
    cout << a[0][0] << endl;
    func();
    cout << a[0][0] << endl;
}



/*
    void func(int a[][20][30])   while passing n d arrays then only the first [] can be empty rest all should have defined values
    {
        a[0][0][0] = 7;
    }

    int main()
    {
        int arr[10][20][30];
        func(&arr[0][0][0])
    }

*/