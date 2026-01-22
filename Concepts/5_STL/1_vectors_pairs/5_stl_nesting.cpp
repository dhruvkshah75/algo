// vector of vectors

/*  
    note: vector<int> v(10) is a vector of size 10 all intialized to 0;
          vector<int> v[10] is array of vectors i.e. v[i] is a vector 
          vector<int> v is a vetor of size 0
          vector<int> v(10, 4) is a vector of size 10 and all the elements are initialised to 4
*/

#include<bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v){
    cout << "Size: " << v.size() << endl; 
    for(int j=0; j< v.size(); j++){
        cout << v[j] << " ";
    }
    cout << endl;
}

int main(){
    vector<vector<int>> v;    // the initial size of it is 0; its a vector of vectors 
    // similar to 2d array so u can access the elements by doing v[i][j]
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vector<int> temp;          
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);      // every element in v is a vector so adding the entire temp in v.
    }

    v[0].push_back(10);  // adding element 10 to v[0] which is the vector
    v.push_back(vector<int> ());  // an empty vector gets added 


    // print it 
    for(int i=0; i<v.size(); i++){
        print_vec(v[i]);
    }

}