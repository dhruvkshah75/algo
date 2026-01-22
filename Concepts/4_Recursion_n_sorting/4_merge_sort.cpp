/********************* MERGE SORT ******************************/

/*
    it has two steps: merging two sorted array
    and sorting the array
    divide the array into single element arrays then merge all the sorted single elements using merge algorithm
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];

void merge(int l, int r, int mid){
    int l_sz = mid-l+1;
    int L[l_sz+1];
    int r_sz = r-mid;
    int R[r_sz+1];

    // forming two arrays bw l and r
    for(int i=0; i<l_sz; i++){
        L[i] = arr[i+l];
    }
    for(int i=0; i<r_sz; i++){
        R[i] = arr[i+mid+1];
    }

    // merging two sorted arrays
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i=0;
    int r_i=0;
    for(int i=l; i<=r; ++i){
        if(L[l_i] <= R[r_i]){
            arr[i] = L[l_i];
            l_i++;
        }
        else{
            arr[i] = R[r_i];
            r_i++;
        }
    }
}

void merge_sort(int l, int r){
    if(l==r) return;
    int mid = (l+r)/2;
    // recursion occurs till it reaches to a single element 
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, r, mid);
}


int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    merge_sort(0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// time complexity is O(nlog(n)) 