#include <bits/stdc++.h>>
using namespace std;

// Method to print the array
void printArray(char arr[])
{
    for(int i = 0; i < 6; i++)
    {
        cout << " " <<  arr[i];
    }
    cout << endl;
}

// Similar to standard partition method.
// Here we pass the pivot element too 
// instead of choosing it inside the method.
int partition(char arr[], int low, int high, char pivot)
{
    int i = low;
    char temp1, temp2;
    
    for(int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        } 
        else if(arr[j] == pivot) {
            swap(arr[j], arr[high]);
            j--;
        }
    } 
    swap(arr[i], arr[high]);

    // Return the partition index of 
    // an array based on the pivot 
    // element of other array.
    return i;
}

// Function which works just like quick sort
void matchPairs(char nuts[], char bolts[], int low, int high) {
    if (low < high) {
        
        // find the partition of nuts but here the pivot is bolts[high] 
        int pivot = partition(nuts, low, high, bolts[high]);
        // now we have the pivot partition of nuts then using that index we find the partition of bolts as the nuts[pivot] as the pivot 
        partition(bolts, low, high, nuts[pivot]);
        // Recur for [low...pivot-1] & [pivot+1...high] for nuts andbolts array.
        matchPairs(nuts, bolts, low, pivot - 1);
        matchPairs(nuts, bolts, pivot + 1, high);
    }
}

int main() {
    
    // Nuts and bolts are represented 
    // as array of characters
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};

    // Method based on quick sort which 
    // matches nuts and bolts
    matchPairs(nuts, bolts, 0, 5);

    cout <<"Matched nuts and bolts are : \n";
    
    printArray(nuts);
    printArray(bolts);
}
