#include<bits/stdc++.h>
using namespace std;

void print_vec(vector<pair<int,int>> &v){
    cout << "size: " << v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}

void print_vec(vector<int> &v);

int main(){
    vector<pair<int,int>> v;
    // every element of the vector is going to be a pair
    // i.e. v[0] is a pair
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});  // v.push_back(make_pair(x, y))
    }
    print_vec(v);

    // ***************** NOTE ****************
    vector<int> v1(10);  // ---> creating a vector of 10 elements and all elements are initialised to 0

    vector<int> v2[10];    // --> this is an array of vectors i.e. v[0] is a vector v[1] is a vector and so o
    
    int N;
    cin >> N;
    vector<int> v3[N];   // good way of defining a 2d vector or 2d array of dynamic length
    // other way of describing a 2d array of dynamic length is 
    vector<vector<int>> v4(N, vector<int>(N));
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            v3[i].push_back(x); 
        }
    }

    // to print the vectors
    for(int i=0; i<N; i++){
        print_vec(v3[i]);
    }

}

void print_vec(vector<int> &v){
    
    for(int j=0; j< v.size(); j++){
        cout << v[j] << " ";
    }
    cout << endl;
}