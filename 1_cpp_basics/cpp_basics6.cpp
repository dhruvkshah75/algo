/**********************  C++ references *******************/
// c++ references are better than pointers for competitive programming.

#include<bits/stdc++.h>
using namespace std;

/*
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
*/

void increment(int &n, int n1)    // this pass by reference
{
    n++;
    n1++;
}

void func(string &s)    // c++ refernce
{
    s = "hello";
}

void func1(int a[])
{
    a[0] = 5;
}

int main()
{
    int a = 3;
    int b = 5;
    cout << a << " " << b << endl;
    increment(a, b);
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    string s = "adwwt";
    cout << s << endl;
    func(s);
    cout << s << endl;

    int arr[10];
    arr[0] = 8;
    cout << arr[0] << endl;
    func1(arr);
    cout << arr[0] << endl;

}

// C++ has some inbuilt functions with it such that max(a, b), min(a, b) and swap(a, b)
// note: arrays can never be passed by value, always passed by reference 