// =========================================== binary tree =================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description

/* Explanation: binary trees + preorder serialization 
   iterative approach can use stack => keep pushing the elements in the stack and then when # is reached 
   and then pop the top element and try 

   or use a recursive procedure 
   we consume one node after anathor => consuming a node means starting a subtree rooted at node and then this one having valid left part and right part 
   when we reach # -> nullptr which itself is a valid subtree so return true and move on to the next node 
   and keep doing this 
   after all the recursive calls are finished the index used for tracking must be eqaul to the end of the string 
*/