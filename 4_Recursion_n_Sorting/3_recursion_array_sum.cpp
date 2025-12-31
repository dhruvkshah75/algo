/**************** SUM OF ARRAY USING RECURSION *******************/
/**************** DIGIT SUM USING RECURSION **************************************/

#include<bits/stdc++.h>
using namespace std;


int digit_sum(int n){
    if(n==0) return 0;
    return n%10 + digit_sum(n/10);
}
// time complexity is O(log10(n))

int sum_array(int arr[], int n){
    if(n==0) return 0;
    return arr[n-1] + sum_array(arr, n-1);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << sum_array(arr, n) << endl;

    int num;
    cin >> num;
    cout << digit_sum(num) << endl;
}