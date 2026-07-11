// ============================================== greedy ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/set-intersection-size-at-least-two/description

/** Explanation: greedy + sorting 
 *  Here we must take min elements in the nums array 
 *  nums must contain elements such that each interval has 2 elements 
 *  When do we cut down the elements when there are overlapping intervals
 * 
 *  3 cases of how 2 intervals interact with each other 
 *  1. complete overlap => [l1 .... l2 ... r2 ... r1] 
 *  2. partial overlap => [l1.....l2...r1....r2] => overlapping section is [l2..r1]
 *  3. 
 * 
 *  eg [1, 3], [1, 4] => complete overlap => so consider the smallest smallest interval 
 *  pick the two elements as 1, 2 or 2, 3 or 1, 3  
 * */