
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


/**
 * pbds is a ordered set => ordered set gives the kth element and the rank
 * ordered set is like a normal set so does not store duplicates 
 * 
 * 
 * Count inversions problem
 * [ elements ≤ a[i] ] [ elements > a[i] ]
 * <- order_of_key ->  <- what we want ->
 * total = s.size()
 **/

// count inversions using pbds data structure

int64_t count_inversions(vector<int> &a) {
	// Count the inversions in an array: the number of pairs (j, i) with j < i and a[j] > a[i].

	ordered_set<pair<int,int>> s;
	// pair allows duplicate elements being inserted 

	int64_t ans = 0;

	for(size_t i = 0; i < a.size(); i++) {

		inv += s.size() - s.order_of_key({a[i], INT_MAX});
		s.insert({a[i], i});
	} 

	return
}


int main() {
	// example use case of ordered_set => pbds 

	ordered_set<int> s;

	for(int x: {10, 20, 30, 40, 50}) s.insert(x);

	auto it1 = s.lower_bound(25);   // -> iterator of 30
	auto it2 = s.upper_bound(30);   // -> 40

	// important operations => returns number of elements smaller then some element in the set 
	cout << s.order_of_key(30) << "\n";    // 2  (elements strictly < 30)
	cout << s.order_of_key(35) << "\n";    // 3  (works even if 35 isn't in the set)

	// return the iterator of the kth element (0 indexed)
	cout << *s.find_by_order(0) << "\n";   // 10 (0-indexed k-th smallest)
	cout << *s.find_by_order(3) << "\n";   // 40

	// find_by_order returns end() if k >= size
	if (s.find_by_order(10) == s.end()) cout << "out of range\n";

	// count of elements in [l, r]
	int l = 20, r = 40;
	cout << s.order_of_key(r+1) - s.order_of_key(l) << endl;
}