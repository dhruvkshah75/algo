/************************ ARRAY MANUPILATION **********************/
/*
    Startin with a 1-indexed array of zereos and a list of operations
    for each operation add a value to each the array element between two given indices
    inclusive. once all the operations have been performed, return the 
    maximum value in the array.
    queires are 
    queries = [[1, 5, 3], [4, 8, 7], [6, 9, 1]]
    a b k
    1 5 3
    4 8 7
    6 9 1
    ans is 10;
    int n-the number of elements in the array
    int queries[q][3] each query has 3 inputs 

    input format:
    first line contains n and m n is the size of the array and m is no of queries 
    next line contains 3 inputs a b k

    Constraints:
    3 <= n <= 10e7
    1 <= m <= 2*10e5
    1 <= a <= b <= n
    0 <= k <= 10e9
*/

//      combination of both prefix sum and hashing

/*
    Notes:
    in this question for all queries add k at a index then add -k at b+1 index for all m queries,
    then take prefix sum of the entire array it will qive the required answer

    Trick used:
    1. so to add k between a and b inclusive ------ add k to ath index and -k to b+1th index
    ex:  follow step 1
    indexes: 1  2   3   4   5  6
             0  0   0   0   0  0
    1 2 100  100 0 -100 0   0  0
    2 5 100  100 100 -100 0 0 -100
    3 4 100  100 100 0 0 -100 -100

    2. now take the prefix sum of the given array for all elements:
    preifix_sum is 
    1   2   3   4   5
    100 200 200 200 100
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
long long int arr[N];   // as k is 1e9 

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b, k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b+1] += (-k);
    }  
    // now the initial array is ready now take the prefix sum of the array
    for(int i=1; i<=n; i++){
        arr[i] = arr[i-1] + arr[i];
    }

    long long max = INT_MIN;
    for(int i=1; i<=n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    cout << max << endl;

}

// Time complexity of the above code is O(M) + O(N) + O(N) = O(N) = 2*10e7 iterations so it will get completed in 1 sec










// #ifdef Wrong
// int main(){
//     int n, m;
//     cin >> n >> m;
//                         //int* arr = new int[5](); this initialises it to 0 
//     while(m--)
//     {
//         int a, b, k;
//         cin >> a >> b >> k;
//         for(int i=a; i<=b; i++)
//         {
//             arr[i] +=k;
//         }
//     }
//     long long max = -1;
//     for(int i=1; i<=n; i++)
//     {
//         if(max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     cout << max << endl;      
// }
// #endif

