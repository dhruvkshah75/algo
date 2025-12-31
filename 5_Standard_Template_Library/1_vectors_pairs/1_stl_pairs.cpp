#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        syntax of pair: pair<int, sting>
    */
   pair<int, string> p;
   //p = make_pair(2, "hello");        // to fill the pair
   // or 
    p = {2, "hello"};
   // pair<int, string> p1 = p;        //directly can copy to each other by value not reference.
   // p1.first = 3;
   pair<int, string> &p1 = p;    // pass by reference (c++ references )
   p1.first = 5;
   cout << p.first << " " << p.second << endl;

   int a[] = {1, 2, 3};
   int b[] = {2, 3, 4};
   // pair is used to maintain relation between two quantities
   pair<int, int> p_arr[3];
   p_arr[0] = {1, 2};
   p_arr[1] = {2, 3};
   p_arr[2] = {3, 4};
   swap(p_arr[0], p_arr[2]);
   for(int i=0; i<3; i++){
        cout << p_arr[i].first << " " << p_arr[i].second << endl;
   }

}