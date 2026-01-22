// ******************* ARRAYS ******************

#include<bits/stdc++.h>
using namespace std;

void print_array(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(i!= len-1)
            cout << arr[i] << " ";
        else 
            cout << arr[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    print_array(arr, n);
    
    int rows, cols;
    cin >> rows >> cols;                                         
    int a[rows][cols];             // rows means how many array[cols];

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> a[i][j];
        }
    }


    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
}