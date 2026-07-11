// =========================================== greedy ================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/candy/description/

/**
 * Explanation: greedy 
 * Deal with all the increasing sequences and assign them based on their len 
 * and then in the second pass deal with all the strictly decreasing seq where we assign them 
 * now the conflicting case => cases where a mountain is formed (so peak depends) 
 * so for the second pass take max of the two cases so that we handle the conflict correctly 
 * 
 * and to deal with neither strictly increasing or strictly decreasing => simply assign 1 in the start 
 * and using max will make them correctly marked depeding on the len of the inc or dsc sequence 
 * 
 * eg: [1, 2, 3, 10, 8, 5, 4, 3, 1]
 * in the fist pass assign them => [1, 2, 3, 4, 1, 1, 1, 1]
 * and in the second pass for dsc sequences => [1, 2, 3, max(4, 5), 4, 3, 2, 1]
 * so the conflicting case of the mountain peak is handled correctly 
 * */

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();

        vector<int> candy(n, 1);
        // prefill the candy by assigning 1 to all of them => to deal with the case of constant sequence
        // eg: [10, 10, 10, 10]

        // deal with increasing sequences
        for(int i = 1; i < n; i++) {
        	if(ratings[i] > ratings[i-1]) 
        		candy[i] = candy[i-1]+1;
        }

        // deal with the decreasing sequence and handling the max assignment 
        for(int j = n-2; j >= 0; j--) {
        	if(ratings[j] > ratings[j+1])
        		candy[j] = max(candy[j], candy[j+1]+1);
        }

        return accumulate(candy.begin(), candy.end(), 0);
    }
};

/*
	Thoughts 
	what approach i can apply in this candy question 

	Each child must have a single candy 
	and children with higher rating get more candies than their neigbours 

	eg ratings = [1, 0, 2]

	could this be somewhat related to the number of unique values in the array 

	the allotment of candies can be 
	candies = [2, 1, 2]

	since each child must be given at least a candy so give the child with 
	rating = 0 => 1 candy 
	neigbours of both will get more candy i.e. 2 candies as they have higher rating which 

	neighbours only matter (so we can repeat the allotment)

	is this based on the concept where have to do something with valleys 

	Approach
	Figure out if this rating is a valley 
	if i = valley then assign 1 candy to it and then we must deal with neigbours situation 

	more test cases need to be checked 

	Eg: [60, 80, 100, 100, 100, 100, 100]

	ans: [1, 2, 3, 1, 1, 1, 1]

	what if 
	test case = [60, 80, 100, 100, 100, 100, 20]

	ans would be mostly = [1, 2, 3, 1, 1, 2, 1]

	we kept increasing candy by 1 => when strictly increasing 
	and reduced to 1 when ratings became same 

	Final Approach:

	when we find a strictly increasing contiguous segement => allot 1 to the smallest and keep increasing by 1 and stop when the seq no longer is strictly increasing

	when the seq is strictly decreasing (find the length of this seq)
	eg: [10, 7, 4, 2, 1, 15] => strictly decreasing [10, 7, 4, 2, 1] 
	len = 5 => allot candies = [5, 4, 3, 2, 1]

	ans = [5, 4, 3, 2, 1, 2]

	And how to deal when suddenly seq becomes constant eg [10, 10, 10, ...]

	Consider a test case which has all 3 cases => strictly increasing and strictly decreasing and somewhere randomly becomes constant  

	test case = [1, 6, 8, 10, 8, 4, 3, 2, 1]
	 
	in this test case, the strictly increasing sequence is [1, 6, 8, 10] => len = 4 
	assignment is [1, 2, 3, 4]
	but in this the decreasing sequence starting from 10 is [10, 8, 4, 3, 2, 1]
	len = 5 so 10 must start from 4 => so give rating = 10 => 5 candies 
	instead of updating the entire segement of 

	candy assignment = [1, 2, 3, 5, 4, 3, 2, 1]

	When we search for a increasing sequence or decreasing sequence in the ratings array 
	keep the track of the last assignment made as that could be overwritten because of the presence of 
	anthor longer sequence 
	(this question s greedy based on the increasing and decreasing sequences)

	Deal with 3 cases starting from the current index => search for the strictly increasing sequence 
	strictly decreasing and constant series so we can make correct assingment 
	and keep a track of the last assignment to undo the this one as the next one might be longer 

	what if the next one is smaller (increasing -> suddenly decreasing)
	test case => [1, 5, 7, 8, 10, 3, 1]
	candy = [1, 2, 3, 4, 5, ]
	strictly decreasing seq will be [10, 3, 1] => len = 3 (assignment on 10 should be 3 (new one))
	but this is less then the prev assignment of 5 => dont overwrite then the decreasing seq now has a length of 2 instead of 1 

	candy = [1, 2, 3, 4, 5, 2, 1]
*/