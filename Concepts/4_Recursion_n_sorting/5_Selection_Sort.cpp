/************************* SELECTION SORT ****************************/

/*
    note:
    sorted sublist       unsorted sublist      least element in unsorted lsit
    ()                   (11, 25, 12, 22, 64)  11
    (11)                 (25, 12, 22, 64)      12
    (11, 12)             (25, 22, 64)          22
    (11, 12, 22)         (25, 64)              25
    (11, 12, 22, 25)     (64)                  64
    (11, 12, 22, 25, 64) ()                    

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // selection sorting algorithm
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    // time complexity is O(n^2) u should use in built sorting algorithms which have O(nlog(n)) complexity

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}