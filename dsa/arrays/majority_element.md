## ALGORITHM to SOLVE the PROBLEM
To solve the majority element problem in **O(1) space**, use the **Boyer-Moore Voting Algorithm**. 
Here's the core idea in 3 steps:

1. **Track a candidate** (initially the first element) and a **count** (initially 1).  
2. **Traverse the array**:  
- If the current element **matches the candidate**, increment the count.  
- If it **differs**, decrement the count.  
- **Reset the candidate** when count drops to 0 (use the current element as the new candidate).  
3. **The candidate at the end is the majority element** (guaranteed to exist).

**Why it works**:  
The majority element appears > n/2 times. Even if all non-majority elements "cancel out" the majority count, 
the majority's surplus ensures it remains the final candidate.  
*Example*: `[2,2,1,1,1,2,2]` → Candidate ends as `2` (correct).

*Try simulating this with the array `[3,3,4,2,4,4,2,4,4]`.*  
What happens to the count when you hit the first `2`? Why doesn't the candidate become `2`?