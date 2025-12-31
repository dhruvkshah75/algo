#include<bits/stdc++.h>
using namespace std;

void check_palindrome()
{
    string str;
    cin >> str;
    for(int i=0; i<str.size()/2; i++)   // loop runs till halfway of the string
    {
        if(str[i] != str[str.size()-i-1])
        {
            cout << "Not a palindrome" << endl;
            return;
        }
    }
    cout << "Yes it is a palindrome" << endl;
}

int main()
{
    string str;
    getline(cin, str);
    string str_rev;
    for(int i = str.size()-1; i>=0; i--)     // correct way to reverse a string.
    {
        str_rev.push_back(str[i]);      // similar to (str_rev = str_rev + str[i]);
    }
    cout << str_rev << endl;


    check_palindrome();
}