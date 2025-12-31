#include<bits/stdc++.h>
using namespace std;


void print()    // correct way to use getline 
{
    int t;
    cin >> t;
    cin.ignore();      // very important step to ignore the cursor in the first cin
    while(t--)
    {
        string str;
        getline(cin, str);
        cout << str << endl;
    }
}

void string_ex()
{
    string str1 = "Hello";
    string str2 = "World";
    string sum = str1 + " " + str2;
    cout << sum << endl;
    cout << sum.size() << endl;  // to get the string length
    // to get entire string in one line
    string str3;
    getline(cin, str3);
    cout << str3 << endl;
    
}

int main()
{
    //for(;;operation)  this operation can be anything including print statement
    for(int i=1; i<=10; cout << i++ << " "){
    }
    cout << endl;
    string_ex();
    print();
    return 0;
}